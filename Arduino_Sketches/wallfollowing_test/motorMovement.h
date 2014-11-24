#include <Arduino.h>
//Theses are the wheel functions

const int rightMotorPin1 = 6;
const int rightMotorPin2 = 5;
const int leftMotorPin1 = 11;
const int leftMotorPin2 = 10;

void moveRWheel(int throttle){
  if(throttle > 255)
    throttle = 255;
  else if(throttle < -255)
    throttle = -255;
  
  if(throttle >= 0){
    analogWrite(rightMotorPin1, throttle);
    digitalWrite(rightMotorPin2, LOW);  
  }
  
  else{
    analogWrite(rightMotorPin2, throttle);
    digitalWrite(rightMotorPin1, LOW);  
  }
  
}

void moveLWheel(int throttle){
  if(throttle > 255)
    throttle = 255;
  else if(throttle < -255)
    throttle = -255;
  
  if(throttle >= 0){
    analogWrite(leftMotorPin1, throttle);
    digitalWrite(leftMotorPin2, LOW);  
  }
  
  else{
    analogWrite(leftMotorPin2, throttle);
    digitalWrite(leftMotorPin1, LOW);  
  }
  
}

