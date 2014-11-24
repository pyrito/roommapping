#include <Arduino.h>

const int triggerPin = 4;
const int echoPin = 3;

long microsecondsToInches(long microseconds){
return microseconds / 74 / 2;
}

long microsecondsToFeet(long microseconds){
return microseconds / 74 / 2 / 12;
}

float microsecondsToCentimeters(float microseconds){
return microseconds / 29.0 / 2.0;
}

float ultrasound(){
  float pulseDuration;
  
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(triggerPin, LOW);

  pinMode(echoPin, INPUT);
  pulseDuration = pulseIn(echoPin, HIGH);
 
  return microsecondsToCentimeters(pulseDuration);
}
