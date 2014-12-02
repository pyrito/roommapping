#include <Arduino.h>
#include <Servo.h>

#define ir A0
#define model 1080

Servo yawServo;
Servo pitchServo;

boolean done = false;
 
void SetPanTiltConfiguration(float yaw, float pitch, float yawOffset, float pitchOffset)
{ 
  yawServo.write(yaw - yawOffset);
  pitchServo.write(pitch + pitchOffset);
}

float distance() 
{    
    int raw = analogRead(ir);
    float voltFromRaw = map(raw, 0, 1023, 0, 5000);
    return 27.728*pow(voltFromRaw/1000, -1.2045);
}

float filteredDistance(int numOfSamples, int tolerance, int delayBetweenSamples)
{    
  int validMeasurements = 0;
  float sum = 0.0;
  
  while(validMeasurements < numOfSamples)
  {
    int measurement = distance();
    
    if (measurement <= tolerance)
    {
      sum = sum + measurement;
      validMeasurements++;
    }
    delay(delayBetweenSamples);
  }
    
  return sum/(float)validMeasurements;
}
