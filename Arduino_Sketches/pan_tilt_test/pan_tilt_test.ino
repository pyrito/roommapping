#include "pan_tilt_test.h"
#include <Servo.h>
void setup()
{
  yawServo.attach(9);
  pitchServo.attach(8);
  SetPanTiltConfiguration(0,0,13,10);
  delay(1000);
  scanmovement();
}

void scanmovement()
{ 
  for (int y=0; y<=18; y++){
    yawServo.write(y*10);
    delay(50);  
  } 
}

void loop(){
  
}
