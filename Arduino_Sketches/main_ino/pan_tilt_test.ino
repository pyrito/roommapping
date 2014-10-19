#include "pan_tilt_test.h"
#include <Servo.h>
void setup()
{
  yawServo.attach(9);
  pitchServo.attach(8);
  SetPanTiltConfiguration(0,0,13,10);
}

void loop()
{ 
  SetPanTiltConfiguration(0,0,13,10);
}

