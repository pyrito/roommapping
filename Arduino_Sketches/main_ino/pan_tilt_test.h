#include <Arduino.h>
#include <Servo.h>

 Servo yawServo;
 Servo pitchServo;
 
void SetPanTiltConfiguration(float yaw, float pitch, float yawOffset, float pitchOffset)
{ 
  yawServo.write(yaw + yawOffset);
  pitchServo.write(pitch + pitchOffset);
}

void scanservo(){
  
  
}
