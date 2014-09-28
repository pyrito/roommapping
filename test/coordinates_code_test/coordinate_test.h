#include <Arduino.h>
//this the mathematics function for the x, y, z points. 

  void math(float yaw, float yawOffset, float pitch, float pitchOffset, int dis)
 {
    
    int x = dis*cos(yaw+yawOffset);
    int y = dis*sin(yaw+yawOffset);
    int z = dis*sin(pitch+pitchOffset);
    
  } 
  