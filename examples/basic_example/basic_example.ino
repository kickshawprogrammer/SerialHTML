#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>

#include <SerialHTML.h>

AsyncWebServer server(80);

const char* ssid = "Your WiFi SSID";
const char* password = "Your WiFi Password";

void receiveMessage(uint8_t* data, size_t length) {
  SerialHTML.println("Received Data...");
  
  String message = "";
  for(auto i=0; i<length; i++) {
    message += char(data[i]);
  }
  
  SerialHTML.println(message);
}

void setup() {
  Serial.begin(115200);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
      Serial.printf("WiFi Failed!\n");
      ESP.reset();
  }
  
  Serial.printf("IP Address: %s\n", WiFi.localIP().toString().c_str());

  // SerailHTML is accessible at "<IP Address>/serial" in browser
  SerialHTML.begin(&server);
  SerialHTML.setReceiveHandler(receiveMessage);

  server.begin();
}

void loop() {
//  static int i=0;
//
//  SerialHTML.printf("iterations: %d\n", ++i);
//  delay(1000);
}
