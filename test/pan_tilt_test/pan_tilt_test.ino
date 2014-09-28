#include "pan_tilt_test.h"
#include <Servo.h>
void setup()
{
  yawServo.attach(3);
  pitchServo.attach(2);
  SetPanTiltConfiguration(0,0,13,10);
}

void loop()
{ 
}

