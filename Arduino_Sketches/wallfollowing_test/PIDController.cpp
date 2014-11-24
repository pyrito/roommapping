#include "PIDController.h"

PIDController::PIDController()
{
}

PIDController::PIDController(int samplePeriod, double KP, double KI, double KD, double MAXOUTPUT, double MINOUTPUT)
{
    
    currentSamplingPeriodInMS = samplePeriod;
    integralOutput = 0;
    previousSampleTime = millis();
    previousInput = 0;
    kp = KP;
    ki = KI;
    kd = KD;
    maxOutput = MAXOUTPUT;
    minOutput = MINOUTPUT;
    controllerOutput = 0;
}

double PIDController::ComputeOutput(double input, double setPoint)
{
    
    int currentSampleTime = millis();
    
    if(previousSampleTime > currentSampleTime)
        previousSampleTime = millis();
    
    if((currentSampleTime - previousSampleTime) > currentSamplingPeriodInMS)
    {
        proportionalOutput = kp*(setPoint - input);
        integralOutput += ki*(setPoint - input);
        derivativeOutput = kd*(previousInput - input);
        
        if(integralOutput > maxOutput)
            integralOutput = maxOutput;
        else if(integralOutput < minOutput)
            integralOutput = minOutput;
        
        controllerOutput = proportionalOutput + integralOutput + derivativeOutput;
        
        if(controllerOutput > maxOutput)
            controllerOutput = maxOutput;
        else if(controllerOutput < minOutput)
            controllerOutput = minOutput;
        
        previousInput = input;
        previousSampleTime = currentSampleTime;
    
    }
    
    return controllerOutput;
}

void PIDController::SetGains(double KP, double KI, double KD)
{
    kp = KP;
    ki = KI;
    kd = KD;
}

void PIDController::SetSamplingPeriod(int newSamplePeriod)
{
    
    ki /= (double)newSamplePeriod/(double)currentSamplingPeriodInMS;
    kd *= (double)newSamplePeriod/(double)currentSamplingPeriodInMS;
    
    currentSamplingPeriodInMS = newSamplePeriod; 
}

void PIDController::SetOutputLimits(double MAXOUTPUT, double MINOUTPUT)
{
    maxOutput = MAXOUTPUT;
    minOutput = MINOUTPUT;
}

void PIDController::ResetMemory()
{
    integralOutput = 0;
    previousSampleTime = millis();
    previousInput = 0;
    controllerOutput = 0;
}
