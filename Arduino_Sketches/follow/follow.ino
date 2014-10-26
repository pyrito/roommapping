//#include "test.h"
#include "Arduino.h"
void setup() {
 


const int motor1Pin1 = 6;
const int motor1Pin2 = 5;
const int motor2Pin1 = 11;
const int motor2Pin2 = 10;
//const int motor1Control = 9;
//const int motor2Control = 10;
int sideD = //left sensor distance

}

void wallFollow(sideD){
  
  if (sideD>12){
        
  analogWrite(motor1Pin1, 110); 
  digitalWrite(motor1Pin2, LOW); 
  analogWrite(motor2Pin1, 110); 
  digitalWrite(motor2Pin2, LOW); 
  }
  
  else if (12<sideD && sideD<=18){
    
  analogWrite(motor1Pin1, 120); 
  digitalWrite(motor1Pin2, LOW); 
  analogWrite(motor2Pin1, 100); 
  digitalWrite(motor2Pin2, LOW); 
}

void loop() {
  
}
