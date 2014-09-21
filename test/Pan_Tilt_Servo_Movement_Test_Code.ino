//This is the Pan Tilt Servo Movement code
//By pyrito

#include <Servo.h>

 Servo yawServo;
 Servo pitchServo;

void setup()
{
  yawServo.attach(3);
  pitchServo.attach(2);
  SetPanTiltConfiguration(0,0,13,10);
}

void loop()
{ 
}

void SetPanTiltConfiguration(float yaw, float pitch, float yawOffset, float pitchOffset)
{ 
  yawServo.write(yaw + yawOffset);
  pitchServo.write(pitch + pitchOffset);
}
