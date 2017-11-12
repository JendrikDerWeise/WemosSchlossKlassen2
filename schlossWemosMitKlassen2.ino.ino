
#include "Lock.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

/* Set these to your desired credentials. */
const char *ssid = "ESPap";
const char *password = "thereisnospoon";
const int buttonPin = D0;
Lock lock;


ESP8266WebServer server(80);

/*void buttonPressed() {
  lock.setAllClientsConnected();
  server.send(200, "text/plain", "gehtlos");
}*/
void reg(){
  lock.registerDevice();
}

void sensAc(){
  lock.sensorActive();
}

void sensInAc(){
 lock.sensorInactive(); 
}

void setup() {
  pinMode(buttonPin, INPUT);
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/registerSensor", reg);
  server.on("/sensorActive", sensAc);
  server.on("/sensorInactive", sensInAc);
  server.begin();
  Serial.println("HTTP server started");
  delay(1);
  lock.setSetter();
}

void loop() {
  //checkForNewClients();
  server.handleClient();
  if (!lock.isAllClientsRegistered()) {
    if (digitalRead(buttonPin) == HIGH){
      lock.setAllClientsConnected();
    }
  }
  /*
  if (lock.isAllSensorsActive()) {
    if (digitalRead(buttonPin) == HIGH) {
      //lock.openDoor();
      
    }
  }

  if(lock.isDoorOpen()){}
    //broadcast an alle "shutdown"
    
    if (digitalRead(buttonPin) == HIGH);
    */
}

