#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "SSID";
const char* password = "PASSWORD";

ESP8266WebServer server(80);   //instantiate server at port 80 (http port)

String page = "";
int LEDPin = 13;
void setup(void){
  //the HTML of the web page
  page = "<head>\n    <title></title>\n    <meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\n    <style type=\"text/css\">\n        html, body {\n            height: 100%;\n            margin: 0;\n            overflow: hidden;\n        }\n\n        #wrapper {\n        \tbackground-color: black;\n            min-height: 100%; \n            position: relative;\n\n        }\n\n        p {\n        \tcolor: white;\n        \tfont-family: Helvetica;\n        \tfont-size: 10vw;\n        \ttext-align: center;\n        }\n\n        #on {\n        \tbackground-color: green;\n        \tpadding: 20px;\n        \theight: 50%;\n        }\n\n        #off {\n        \tbackground-color: red;\n        \tpadding: 20px;\n        \theight: 50%;\n        }\n\n\n    </style>\n</head>\n\n<body>\n    <div id=\"wrapper\">\n    \t<div onclick=\"location.href='LEDOn';\" id=\"on\">\n    \t\t<p>ON</p>\n    \t</div>\n\n    \t<div onclick=\"location.href='LEDOff';\" id=\"off\">\n    \t\t<p>OFF</p>\n    \t</div>\n    </div>\n</body>";
  
  //make the LED pin output and initially turned off
  pinMode(LEDPin, OUTPUT);
  digitalWrite(LEDPin, LOW);
     
  delay(1000);
  Serial.begin(9600);
  WiFi.begin(ssid, password); //begin WiFi connection

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  server.on("/", [](){
    server.send(200, "text/html", page);
  });

  server.on("/LEDOn", [](){
    server.send(200, "text/html", page);
    digitalWrite(LEDPin, HIGH);
    delay(1000);
  });
  server.on("/LEDOff", [](){
    server.send(200, "text/html", page);
    digitalWrite(LEDPin, LOW);
    delay(1000); 
  });
  server.begin();
  Serial.println("Web server started!");
}
 
void loop(void){
  server.handleClient();
}
