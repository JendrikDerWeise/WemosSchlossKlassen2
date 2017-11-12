#include "TwoColoredLED.h"

TwoColoredLED::TwoColoredLED(){
  mStatus = false;
}

void TwoColoredLED::setLED(char n, int red, int blue){
  mRed = red;
  mBlue = blue;
  pinMode(mRed, OUTPUT);
  pinMode(mBlue, OUTPUT);
  mName = n;
  Serial.println("n: "+ mName + " name: " +mName);
}

void TwoColoredLED::setColor(char color){
  switch(color){
    case 'r':
      digitalWrite(mRed, HIGH);
      break;
    case 'b':
      digitalWrite(mBlue, HIGH);
      break;
    case 'p':
      digitalWrite(mRed, HIGH);
      digitalWrite(mBlue, HIGH);
      break;
  }
  mStatus = true;
  Serial.println(" " + mName + " ist an.");
}

void TwoColoredLED::setOff(){
    digitalWrite(mRed, LOW);
    digitalWrite(mBlue, LOW);
    mStatus = false;
    Serial.println(" " + mName + " ist aus.");
}

bool TwoColoredLED::isOn(){
  return mStatus;
}

