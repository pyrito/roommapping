#include "coordinate_test.h"
#include "sharp_sensor.h"

const int sharpPin = A0;

void setup() {
  float yaw;
  float pitch;
  float yawOffset;
  float pitchOffset;
  
  }

void loop(){

  //  math(0,0,13,10);
  conversion();
    
  }

int conversion(){
  float sharpDistance = 12343.85*pow(analogRead(sharpPin),-1.15);
  Serial.println(sharpDistance);
}
