  void setup() {
  float yaw;
  float pitch;
  float yawOffset;
  float pitchOffset;
  int dis;
  
  }

  void loop() 
  {
  }
  void math(float yaw, float yawOffset, float pitch, float pitchOffset, int dis)
 {
    
    int x = dis*cos(yaw+yawOffset);
    int y = dis*sin(yaw+yawOffset);
    int z = dis*sin(pitch+pitchOffset);
    
  } 
  
  
