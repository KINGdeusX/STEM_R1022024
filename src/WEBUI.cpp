// #include <Arduino.h>
// #include <ESP8266WiFi.h>
// #include <ESP8266WebServer.h>

// #include <ESP8266WiFi.h>
// #include <ESP8266WebServer.h>

// const char* ssid = "Canal_Control";
// const char* password = "admin123";

// ESP8266WebServer server(80);

// const int ledPin = 5;
// bool ledState = LOW;

// // Function to handle the root page
// void handleRoot() {
//   String html = "<!DOCTYPE html><html lang=\"en\">";
//   html += "<head>";
//   html += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
//   html += "<style>";
//   html += "body { font-family: Arial, sans-serif; text-align: center; padding: 20px; }";
//   html += "h1 { color: #333; }";
//   html += "p { font-size: 1.2em; }";
//   html += "button { padding: 15px 30px; font-size: 1.2em; color: white; background-color: #4CAF50; border: none; border-radius: 5px; cursor: pointer; }";
//   html += "button:hover { background-color: #45a049; }";
//   html += "</style>";
//   html += "</head>";
//   html += "<body>";
//   html += "<h1>Canal Control System</h1>";
//   html += "<p>Control Gate " + String(ledState ? "UP" : "DOWN") + "</p>";
//   html += "<form action=\"/toggle\" method=\"POST\">";
//   html += "<button type=\"submit\">" + String(ledState ? "LOWER" : "RAISE") + "</button>";
//   html += "</form>";
//   html += "</body></html>";
  
//   server.send(200, "text/html", html);
// }


// // Function to handle the toggle action
// void handleToggle() {
//   ledState = !ledState;
//   digitalWrite(ledPin, ledState);
//   server.sendHeader("Location", "/");
//   server.send(303);
// }

// void setup() {
//   pinMode(ledPin, OUTPUT);
//   digitalWrite(ledPin, ledState);
  
//   Serial.begin(115200);

//   // Set up the Wi-Fi access point
//   WiFi.softAP(ssid, password);

//   // Optional: Assign a static IP configuration
//   // IPAddress IP(192, 168, 1, 1);
//   // IPAddress gateway(192, 168, 1, 1);
//   // IPAddress subnet(255, 255, 255, 0);
//   // WiFi.softAPConfig(IP, gateway, subnet);

//   Serial.print("AP IP address: ");
//   Serial.println(WiFi.softAPIP());

//   // Define the HTTP routes
//   server.on("/", handleRoot);
//   server.on("/toggle", HTTP_POST, handleToggle);

//   // Start the HTTP server
//   server.begin();
//   Serial.println("HTTP server started");
// }

// void loop() {
//   server.handleClient();
// }