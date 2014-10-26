#include <Arduino.h>
#include "sharp_sensor.h"

int dis = conversion();
//this the mathematics function for the x, y, z points. 

  void math(float yaw, float yawOffset, float pitch, float pitchOffset)
 {
    
    int x = dis*cos(yaw+yawOffset);
    int y = dis*sin(yaw+yawOffset);
    int z = dis*sin(pitch+pitchOffset);
    
    Serial.print(x);
    Serial.print('/t');
    Serial.print(y);
    Serial.print('/t');
    Serial.print(z);
    
  } 
  
