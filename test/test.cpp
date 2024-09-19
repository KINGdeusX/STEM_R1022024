#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Set Wi-Fi credentials for the Access Point
const char* ssid = "EcoCanalRemote";
const char* password = "admin1234";

// Create a web server on port 80
ESP8266WebServer server(80);

// Manually assign IP address (to be 192.168.1.1)
IPAddress local_IP(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

// Boolean variables to track states
bool isRaised = false;
bool mode = 0;  // 0 = Automatic, 1 = Manual

// HTML content with dynamic mode and conditional Raise/Lower button
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

// Function to simulate lifting
void lift_sequencer() {
  Serial.println("Lift sequence triggered!");
  // Add actual lifting logic here
}

// Function to simulate lowering
void lower_sequencer() {
  Serial.println("Lower sequence triggered!");
  // Add actual lowering logic here
}

// Function to handle setting the mode
void handleSetMode() {
  if (server.hasArg("mode")) {
    String modeValue = server.arg("mode");
    if (modeValue == "1") {
      mode = 1;  // Set to Manual
      Serial.println("Mode set to Manual.");
    } else if (modeValue == "0") {
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
  // Start serial communication for debugging
  Serial.begin(115200);

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
  // Handle incoming client requests
  server.handleClient();
}