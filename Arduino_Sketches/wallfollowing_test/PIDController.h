#ifndef PIDController_h
#define PIDController_h

#include <Arduino.h>
				
class PIDController
{
    public:
	PIDController();
    explicit PIDController(int sampleTimeInMSecs, double KP, double KI, double KD, double MAX, double MIN);
    double ComputeOutput(double input, double setPoint);
    void SetGains(double KP, double KI, double KD);
    void SetSamplingPeriod(int newSamplePeriodInMSecs);
    void SetOutputLimits(double MAXOUTPUT, double MINOUTPUT);
    void ResetMemory();
    
    private:
    double kp, ki, kd;
    unsigned long previousSampleTime;
    double controllerOutput, maxOutput, minOutput, previousInput;
    double integralOutput, proportionalOutput, derivativeOutput;
    int currentSamplingPeriodInMS;
};

#endif