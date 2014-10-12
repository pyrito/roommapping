#include <Arduino.h>
//Theses are the wheel functions

const int motor1Pin1 = 6;
const int motor1Pin2 = 5;
const int motor2Pin1 = 11;
const int motor2Pin2 = 10;
//const int motor1Control = 9;
//const int motor2Control = 10;

void goForward(){
  analogWrite(motor1Pin1, 200); 
  digitalWrite(motor1Pin2, LOW); 
  analogWrite(motor2Pin1, 150); 
  digitalWrite(motor2Pin2, LOW); 
}

void goBackwards(){
  analogWrite(motor1Pin2, 200); 
  digitalWrite(motor1Pin1, LOW); 
  analogWrite(motor2Pin2, 150); 
  digitalWrite(motor2Pin1, LOW); 
}

void goLeft(){
  analogWrite(motor1Pin2, 150);
  digitalWrite(motor1Pin1, LOW);
  analogWrite(motor2Pin1, 150);
  analogWrite(motor2Pin2, LOW);
}

void goRight(){
  analogWrite(motor1Pin1, 150);
  digitalWrite(motor1Pin2, LOW);
  analogWrite(motor2Pin2, 150);
  digitalWrite(motor2Pin1, LOW);
}

