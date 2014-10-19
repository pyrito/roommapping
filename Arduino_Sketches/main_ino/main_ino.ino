#include "test.h"
#include "pan_tilt_test.h"

void setup(){
  yawServo.attach(3);
  pitchServo.attach(2);
  Serial.begin(9600);
  
}

void loop(){
   for (int y=0; y<=18; y++){
    yawServo.write(y*10);
    delay(50);  
  } 
  
  
  
}
