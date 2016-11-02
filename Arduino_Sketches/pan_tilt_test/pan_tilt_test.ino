#include "pan_tilt_test.h"
#include <Servo.h>

int yawOffset = 10;
int pitchOffset = 35;

float yaw, pitch;
int x,y;

void setup()
{
  delay(11000);
  Serial.begin(9600);
  yawServo.attach(8);
  digitalWrite(8, HIGH);
  pitchServo.attach(9);
  
  SetPanTiltConfiguration(90, 0, yawOffset, pitchOffset);
}

void scan()
{ 
  
  for(int y = 0; y <= 5; y++)
  {
    SetPanTiltConfiguration(0, y, yawOffset, pitchOffset);
    delay(400);
    
        for (int x = 0; x <= 90; x += 10)
        {
            SetPanTiltConfiguration(x, y, yawOffset, pitchOffset);
            Serial.print(distance());
            Serial.print(" ");

            Serial.print(x);
            Serial.print(" ");
            Serial.print(90-y);
            Serial.print(" ");
            Serial.println(filteredDistance(20,90,20));
            
            delay(200);
        }
        
  }

}
void loop()
{
  
  //Serial.println(distance());
  //Serial.println(filteredDistance(20, 1000, 20));
  scan();
  delay(200);
}

void movement()
{
  for (int z = 0; z <=15; z += 1)
  {
    SetPanTiltConfiguration(90, z, yawOffset, pitchOffset);
    delay(1000);
  }
  
}
