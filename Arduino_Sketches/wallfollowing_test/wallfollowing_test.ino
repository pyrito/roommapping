#include "motorMovement.h"
#include "ultrasensor.h"

void setup(){
  Serial.begin(9600);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT); 
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT); 
  
}

void loop(){
  
  wallfollowing();
  
}

void wallfollowing(){
  int ultraDistance = ultrasound();
  delay(500);
  /*Serial.print(cm);
  Serial.print("cm");
  Serial.println();*/
  
    if((ultraDistance <= 16) && (ultraDistance >= 13)){
      Serial.println("Going straight");
      goForward();
    }
    
    else if ((ultraDistance > 16) && (ultraDistance < 35)){
      Serial.println("left");
      analogWrite(motor1Pin1, 150); 
      digitalWrite(motor1Pin2, LOW); 
      analogWrite(motor2Pin1, 100); 
      digitalWrite(motor2Pin2, LOW); 
    }
    
    else if (ultraDistance < 16){
      Serial.println("turn right");
      analogWrite(motor1Pin1, 110); 
      digitalWrite(motor1Pin2, LOW); 
      analogWrite(motor2Pin1, 150); 
      digitalWrite(motor2Pin2, LOW); 
    }
  
}
