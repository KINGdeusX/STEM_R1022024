#include <Arduino.h>
#include <DRV8825.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define STEPPER_0_D 5
#define STEPPER_0_S 4
#define STEPPER_1_D 0
#define STEPPER_1_S 2
#define STEPPER_2_D 14
#define STEPPER_2_S 12
#define STEPPER_3_D 13
#define STEPPER_3_S 15
#define sensor1 16

// Set Wi-Fi credentials for the Access Point
const char* ssid = "EcoCanalRemote";
const char* password = "admin1234";

// Create a web server on port 80
ESP8266WebServer server(80);

// Manually assign IP address (to be 192.168.1.1)
IPAddress local_IP(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

// setDirection
// DRV8825_CLOCK_WISE         = 0;  //  LOW
// DRV8825_COUNTERCLOCK_WISE  = 1;  //  HIGH

DRV8825 stepper1, stepper2, stepper3, stepper4; // Defined Stepper

int stepper_internal_delay = 10; // 10 ms for every step
int execution_delay = 1000;
int discarding_delay = 5000;

int stppr_wingL_num_steps = 300; // Number of steps defined for the Wing left Extractor
int stppr_WingR_num_steps = 300; // Number of steps defined for the Wing right Extractor
int stppr_cntrl_gate = 200; // Control Gate number fo steps
int stppr_trash_puller = 400; // Trash net puller

bool isRaised = false;
bool mode = false; // 0 Automatic 1 Manual
bool exec = false; // 0 noting happens 1 sequence begins

void wingL(const boolean direction, int steps) {
	stepper1.begin(STEPPER_0_D, STEPPER_0_S);
  	stepper1.setDirection(direction); // Direction
	for(int i = 0; i <= steps; i++){
		stepper1.step(); // Execute Step
		delay(stepper_internal_delay); 
	}
}
void wingR(const boolean direction, int steps) {
	stepper2.begin(STEPPER_1_D, STEPPER_1_S);
	stepper2.setDirection(direction); // Direction
	for(int i = 0; i <= steps; i++){
		stepper2.step(); // Execute Step
		delay(stepper_internal_delay); 
	}
}
void Cntrl(const boolean direction, int steps) {
	stepper3.begin(STEPPER_2_D, STEPPER_2_S);
	stepper3.setDirection(direction); // Direction
	for(int i = 0; i <= steps; i++) {
		stepper3.step(); // Execute Step
		delay(stepper_internal_delay); 
	}
}
void Puller(const boolean direction, int steps) {
	stepper4.begin(STEPPER_3_D, STEPPER_3_S);
	stepper4.setDirection(direction); // Direction
	for(int i = 0; i <= steps; i++){
		stepper4.step(); // Execute Step
		delay(stepper_internal_delay);
	}
}

void lift_sequencer(){
	Serial.println("Executing");
	server.send(200, "text/plain", "Executing Please Wait");

	Serial.println("Raising Control Gate");
	Cntrl(0, stppr_cntrl_gate); // Raise the control gate
	Serial.println("Control Gate Raised");
	delay(execution_delay);

	Serial.println("Rolling Trash");
	Puller(0, stppr_trash_puller); // Rolls up the trash
	Serial.println("Trash Rolled");
	delay(execution_delay);
	
	Serial.println("Raising The Extractor");
	wingL(0, stppr_wingL_num_steps);
	Serial.println("Extractor Raised");
	delay(execution_delay);

	delay(discarding_delay); // delay for discarding the trash
	server.send(200, "text/plain", "Lower");
}

void lower_sequencer() {
	server.send(200, "text/plain", "Executing Please Wait");
	Serial.println("Lowering the Extractor");
	wingL(1, stppr_wingL_num_steps);
	Serial.println("Extractor Lowered");
	delay(execution_delay);
	
	Serial.println("Unrolling Trash");
	Puller(1, stppr_trash_puller); // Rolls up the trash
	Serial.println("Trash unrolled");
	delay(execution_delay);

	Serial.println("Lowering Control Gate");
	Cntrl(1, stppr_cntrl_gate); // Raise the control gate
	Serial.println("Control Gate Lowered");
	delay(execution_delay);

	Serial.println("Execution Finished");
	delay(5000); // Leveling Delay
	server.send(200, "text/plain", "Raise");
}

String generateHTML() {
  	String html = R"=====(
		<!DOCTYPE html>
		<html>
		<head>
			<meta name="viewport" content="width=device-width, initial-scale=1">
			<title>EcoCanal</title>
			<style>
			body {
				font-family: Arial, sans-serif;
				text-align: center;
				margin-top: 50px;
			}
			h1 {
				font-size: 24px;
				background-color: #4CAF50;
				width: -webkit-fill-available;
				color: #ffffff;
				height: auto;
				padding: 20px;
			}
			footer {
				background-color: #4CAF50;
				width: -webkit-fill-available;
				color: #ffffff;
				height: auto;
				padding: 20px;
			}
			#container {
				padding: 100px 0px 100px 0px;
			}
			.btn {
				padding: 15px 25px;
				margin: 10px;
				font-size: 18px;
				border: none;
				border-radius: 5px;
				color: white;
				cursor: pointer;
			}
			.isSelected {
				background-color: #4CAF50; /* Green */
			}
			.notSelected {
				background-color: #ffffff; /* Red */
				color: black;
				border: 1px solid black;
			}
			.raise-lower {
				background-color: #008CBA; /* Blue */
			}
			.btn:hover {
				opacity: 0.8;
			}
			/* Responsive design */
			@media screen and (max-width: 600px) {
				.btn {
				padding: 10px 20px;
				font-size: 16px;
				}
			}
			</style>
			<script>
			function setMode(modeType) {
				var xhttp = new XMLHttpRequest();
				xhttp.open("GET", "/setMode?mode=" + modeType, true);
				xhttp.send();
				setTimeout(function() {
				location.reload();
				}, 500); // Reload page after 500ms to update UI
			}

			function toggleLift() {
				var xhttp = new XMLHttpRequest();
				xhttp.onreadystatechange = function() {
				if (this.readyState == 4 && this.status == 200) {
					document.getElementById("toggle-btn").innerHTML = this.responseText;
				}
				};
				xhttp.open("GET", "/toggleLift", true);
				xhttp.send();
			}
			</script>
		</head>
		<body>
			<h1>EcoCanal</h1>
			<div id="container">
  )=====";

  // Add dynamic mode text
  if (mode == 1) {
    	html += "<p><strong>Manual</strong> is Selected</p>";
  } else {
    	html += "<p><strong>Automatic</strong> is Selected</p>";
  }

  // Add buttons for mode selection
  if (mode == 1) {
    html += R"=====(
          <button class="btn isSelected" onclick="setMode(1)">Manual</button>
          <button class="btn notSelected" onclick="setMode(0)">Automatic</button>
          <br>
    )=====";
  }
  else {
    html += R"=====(
          <button class="btn notSelected" onclick="setMode(1)">Manual</button>
          <button class="btn isSelected" onclick="setMode(0)">Automatic</button>
          <br>
    )=====";
  }

  // Conditionally display Raise/Lower button if mode is 1 (Manual)
  if (mode == 1) {
    html += R"=====(
        <button id="toggle-btn" class="btn raise-lower" onclick="toggleLift()">Raise</button>
        <p>Manually Trigger the Extraction Sequence</p>
    )=====";
  }
  else {
     html += R"=====(
        <p>No need to do for now seat back and relax (^_^)</p>
    )=====";
  }

  html += R"=====(
		</div>
		</body>
		<footer><p >Powered by ESP8266 deisgned to Control the EcoCanal System</p></footer>
	</html>
  )=====";

  return html;
}

// Function to handle setting the mode
void handleSetMode() {
	if (server.hasArg("mode")) {
		String modeValue = server.arg("mode");
		if (modeValue == "1") {
			mode = 1;  // Set to Manual
			Serial.println("Mode set to Manual.");
		} 
		else if (modeValue == "0") {
			mode = 0;  // Set to Automatic
			Serial.println("Mode set to Automatic.");
		}
		server.send(200, "text/plain", "Mode changed");
	}
}

// Handle toggle between Raise and Lower
void handleToggleLift() {
	if (isRaised) {
		lower_sequencer();  // Call lower_sequencer function
		server.send(200, "text/plain", "Raise");
		isRaised = false;
	} else {
		lift_sequencer();  // Call lift_sequencer function
		server.send(200, "text/plain", "Lower");
		isRaised = true;
	}
}

void setup() {
	// Code Here
	Serial.begin(115200);
	
	pinMode(sensor1, INPUT);
	// Set ESP8266 as an access point and configure a static IP
	WiFi.softAPConfig(local_IP, gateway, subnet);
	WiFi.softAP(ssid, password);

	// Print IP address to serial monitor
	IPAddress myIP = WiFi.softAPIP();
	Serial.println("Access Point IP address: ");
	Serial.println(myIP);

	// Define the root route, which serves the HTML page
	server.on("/", []() {
		server.send(200, "text/html", generateHTML());
	});

	// Route to handle setting the mode
	server.on("/setMode", handleSetMode);

	// Route to handle toggling between Raise and Lower
	server.on("/toggleLift", handleToggleLift);

	// Start the web server
	server.begin();
	Serial.println("HTTP server started");
}
 
void loop() {
	//Code Here
	server.handleClient();
	if (mode == 0) { // Executing Automode
		bool sensor_value = digitalRead(sensor1); // Waits for the laser data

		Serial.println("System in auto Mode");

		if (sensor_value == 1) {
			Serial.print(" Laser Obstructed");
			exec = 1;
		}
		else if (sensor_value == 0) {
			Serial.print(" Laser Clear");
			exec = 0;
		}

		if (exec == 1) {
			// Execution
			lift_sequencer(); // Activates the raise sequence using the custom function
			lower_sequencer(); // Activiates the lower sequence using the custom function
		}
		else if (exec == 0) {
			// Stand by
			Serial.print(" Stand By");
		}
	}
	else if (mode == 1) { // Executing Manual Mode
		//WEBUI controlled Stuff here
		Serial.println("System in manual Mode Stand by");
	}
}