#ifndef _TWOCOLOREDLED_h
#define _TWOCOLOREDLED_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "arduino.h"
#else
  #include "WProgram.h"
#endif
class TwoColoredLED{
 private: 
  int mBlue;
  int mRed;
  bool mStatus;
  String mName;

 public:
  TwoColoredLED();
  void setColor(char);
  void setOff();
  void setLED(char, int, int);
  bool isOn();
  
};
#endif


