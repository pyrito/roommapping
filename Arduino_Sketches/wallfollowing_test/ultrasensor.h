#include <Arduino.h>

const int triggerPin = 4;
const int echoPin = 3;

long microsecondsToInches(long microseconds){
return microseconds / 74 / 2;
}

long microsecondsToFeet(long microseconds){
return microseconds / 74 / 2 / 12;
}

long microsecondsToCentimeters(long microseconds){
return microseconds / 29 / 2;
}

int ultrasound(){
  long duration, feet, inches, cm;
  
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(triggerPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  //feet = microsecondsToFeet(duration);
  return round(cm);
  
  delay(500);
}
