#include "motorMovement.h"
#include "ultrasensor.h"
#include "PIDController.h"
int sharpDistance;
PIDController wallFollowingController(100, 2.0, 0, 0, 20, -20);
float distanceFromWall;
float PControlOut;
float rightWheelOffset = 110;
float leftWheelOffset = 100;


void setup(){
  Serial.begin(9600);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT); 
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT); 
  
  delay(500);
}

void loop(){
  
  //Serial.println(ultrasound());
  
  wallfollowing();
  
  /*if(sharpDistance > 8){
    wallfollowing();
  }
    else{
    moveRWheel(0);
    moveLWheel(0);
  }*/
  
  delay(100);
  
}

int conversion(){
  const int sharpPin = A0;
  int sharpDistance = 12343.85 * pow(analogRead(sharpPin), -1.15);
  Serial.println(sharpDistance);
  delay(50);
}

void wallfollowing(){
  distanceFromWall = ultrasound();
  /*Serial.print(cm);
  Serial.print("cm");
  Serial.println();*/


  if(distanceFromWall > 35){
    Serial.println("stop");
    moveRWheel(0);
    moveLWheel(0);
  }
  else if((distanceFromWall <= 16) && (distanceFromWall >= 11)){
    moveLWheel(leftWheelOffset);
    moveRWheel(rightWheelOffset);
  }
  else{
    PControlOut = wallFollowingController.ComputeOutput(distanceFromWall, 13.5);
    Serial.print(leftWheelOffset + PControlOut);
    Serial.print(" ");
    Serial.println(rightWheelOffset - PControlOut);
    
    moveLWheel(leftWheelOffset + PControlOut);
    moveRWheel(rightWheelOffset - PControlOut);
  }
}
