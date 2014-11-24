#include "pan_tilt_test.h"
#include "sharpsensor_test.h"

#include <Servo.h>

int yawOffset = 10;
int pitchOffset = 35;
float yaw, pitch;
int measure = sharp.distance();
int x,y;

void setup()
{
  Serial.begin(9600);
  yawServo.attach(8);
  digitalWrite(8, HIGH);
  pitchServo.attach(9);
  SetPanTiltConfiguration(90, 0, yawOffset, pitchOffset);
  delay(1000);
  //scan();
}

int coordinates()
{
  int x = measure*cos(yaw+yawOffset);
  int y = measure*sin(yaw+yawOffset);
  int z = measure*sin(pitch+pitchOffset);
}

void scan()
{ 
  for(int y = 0; y < 50; y += 10)
  {
    SetPanTiltConfiguration(0, y, yawOffset, pitchOffset);
    
        for (int x = 0; x < 180; x += 10)
        {
            SetPanTiltConfiguration(x, y, yawOffset, pitchOffset);
            //IRsensor();
            //coordinates();
            //code to take measurements
            Serial.print(x);
            Serial.print(" ");
            Serial.print(y);
            Serial.print(" ");
            Serial.println((sharp.distance() + sharp.distance() + sharp.distance() + sharp.distance() + sharp.distance() )/(5.0));
            delay(200);
        }
  }

}
void loop(){
 //IRsensor();

 scan();
}
