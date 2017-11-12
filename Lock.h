//Lock.h

#ifndef _LOCK_h
#define _LOCK_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "arduino.h"
  #include "TwoColoredLED.h"
#else
  #include "WProgram.h"
#endif
class Lock{
public:
  Lock();
  void registerDevice();
  void sensorActive();
  void sensorInactive();
  void setAllClientsConnected();
  void openDoor();
  bool isAllClientsRegistered();
  bool isAllSensorsActive();
  bool isDoorOpen();
  void setSetter();

private:
  void setRing();
  int sensorCount;
  int activeSensors;
  bool allClientsConnected;
  bool allSensorsActive;
  bool doorOpen;
  TwoColoredLED leds[4] ;
  char red;
  char blue;
  char purple;
};
#endif



