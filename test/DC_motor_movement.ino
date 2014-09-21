#include "test.h"

void setup(){
 
  Serial.begin(9600);
  //pinMode(motor1Control, OUTPUT);
  //pinMode(motor2Control, OUTPUT);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT); 
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT); 
}

void loop(){
  //analogWrite(motor1Control, 157);
  //analogWrite(motor2Control, 0);
 goBackwards();
 
 
}



