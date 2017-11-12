#include "Lock.h"

Lock::Lock() {
  allClientsConnected = false;
  doorOpen = false;
  sensorCount = 0;
  activeSensors = 0;
  red = 'r';
  blue = 'b';
  purple = 'p';
  
}

void Lock::setSetter(){

  leds[0].setLED('a', D1, D2);
  leds[1].setLED('b', D3, D4);
  leds[2].setLED('c', D5, D6);
  leds[3].setLED('d', D7, D8);
}

void Lock::registerDevice() {
  sensorCount++;
  for (int i = 0; i<sensorCount; i++)
    leds[i].setColor(red);//leds werden geschaltet

  Serial.println("connected");
  Serial.println("sensorCount " +sensorCount);//zahl wird nicht ausgegeben
}

void Lock::setRing() {
  Serial.println("activeSensors " +activeSensors);//zahl wird nicht ausgegeben
  for (int i = 0; i < activeSensors; i++)
    leds[i].setColor(blue);//leds werden nicht geschaltet

  if (activeSensors == sensorCount)
    allSensorsActive = true;
  else
    allSensorsActive = false;
}

void Lock::sensorActive() {
  if(allClientsConnected){
    activeSensors++;
    setRing();
    Serial.println("activeSensorsXX " +activeSensors);
  }
}

void Lock::sensorInactive() {
  if(allClientsConnected){
    activeSensors--;
    setRing();
  }
}

void Lock::setAllClientsConnected() {
  allClientsConnected = true;
  for (int i = 0; i < 4; i++)
    leds[i].setOff();
}

void Lock::openDoor() {
  //something
  doorOpen = true;
}

bool Lock::isAllClientsRegistered() {
  return allClientsConnected;
}

bool Lock::isAllSensorsActive() {
  return allSensorsActive;
}

bool Lock::isDoorOpen() {
  return doorOpen;
}

