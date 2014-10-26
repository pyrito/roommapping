#include "Gyroscope.h"

Gyroscope::Gyroscope() 
{
    Wire.begin();
    SetXYZOffsets(0.0,0.0,0.0);
    
    dx = 0;
    dy = 0;
    dz = 0;
    anglesXYZ[0] = 0;
    anglesXYZ[1] = 0;
    anglesXYZ[2] = 0;
    timeOfLastUpdate = 0;
    now = 0;
}

void Gyroscope::Init() 
{
    _I2C_address = ITG3200_ADDR_AD0_HIGH;
    SetSampleRateDiv(NOSRDIVIDER);
    SetFSRange(RANGE2000);
    SetFilterBW(BW256_SR8);
    SetClockSource(PLL_XGYRO_REF);
    SetITGReady(true);
    SetRawDataReady(true);  
    delay(GYROSTART_UP_DELAY); 
    
    ZeroCalibrate(300,5);
}

void Gyroscope::Reinitialize() 
{
    dx = 0;
    dy = 0;
    dz = 0;
    anglesXYZ[0] = 0;
    anglesXYZ[1] = 0;
    anglesXYZ[2] = 0;
    ZeroCalibrate(200,5);
    timeOfLastUpdate = micros();
}

byte Gyroscope::GetI2CAddress() 
{
    /*readFromRegister(WHO_AM_I, 1, &_buff[0]); 
     return _buff[0];  */
    return _I2C_address;
}

void Gyroscope::SetI2CAddress(unsigned int  _addr) 
{
    WriteToRegister(WHO_AM_I, _addr); 
    _I2C_address = _addr;
}

byte Gyroscope::GetSampleRateDiv() 
{
    ReadFromRegister(SMPLRT_DIV, 1, &_buff[0]);
    return _buff[0];
}

void Gyroscope::SetSampleRateDiv(byte _SampleRate) 
{
    WriteToRegister(SMPLRT_DIV, _SampleRate);
}

byte Gyroscope::GetFSRange() 
{
    ReadFromRegister(DLPF_FS, 1, &_buff[0]);
    return ((_buff[0] & DLPFFS_FS_SEL) >> 3);
}

void Gyroscope::SetFSRange(byte _Range) 
{
    ReadFromRegister(DLPF_FS, 1, &_buff[0]);   
    WriteToRegister(DLPF_FS, ((_buff[0] & ~DLPFFS_FS_SEL) | (_Range << 3)) ); 
}

byte Gyroscope::GetFilterBW() 
{  
    ReadFromRegister(DLPF_FS, 1, &_buff[0]);
    return (_buff[0] & DLPFFS_DLPF_CFG); 
}

void Gyroscope::SetFilterBW(byte _BW) 
{   
    ReadFromRegister(DLPF_FS, 1, &_buff[0]);
    WriteToRegister(DLPF_FS, ((_buff[0] & ~DLPFFS_DLPF_CFG) | _BW)); 
}

bool Gyroscope::IsITGReadyOn() 
{   
    ReadFromRegister(INT_CFG, 1, &_buff[0]);
    return ((_buff[0] & INTCFG_ITG_RDY_EN) >> 2);
}

void Gyroscope::SetITGReady(bool _State) 
{
    ReadFromRegister(INT_CFG, 1, &_buff[0]);
    WriteToRegister(INT_CFG, ((_buff[0] & ~INTCFG_ITG_RDY_EN) | _State << 2)); 
}

bool Gyroscope::IsRawDataReadyOn() 
{
    ReadFromRegister(INT_CFG, 1, &_buff[0]);
    return (_buff[0] & INTCFG_RAW_RDY_EN);
}

void Gyroscope::SetRawDataReady(bool _State) 
{
    ReadFromRegister(INT_CFG, 1, &_buff[0]);
    WriteToRegister(INT_CFG, ((_buff[0] & ~INTCFG_RAW_RDY_EN) | _State)); 
}

byte Gyroscope::GetClockSource() 
{  
    ReadFromRegister(PWR_MGM, 1, &_buff[0]);
    return (_buff[0] & PWRMGM_CLK_SEL);
}

void Gyroscope::SetClockSource(byte _CLKsource) 
{   
    ReadFromRegister(PWR_MGM, 1, &_buff[0]);
    WriteToRegister(PWR_MGM, ((_buff[0] & ~PWRMGM_CLK_SEL) | _CLKsource)); 
}

void Gyroscope::SetXYZOffsets(float _Xoffset, float _Yoffset, float _Zoffset) 
{
    XYZoffsets[0] = _Xoffset;
    XYZoffsets[1] = _Yoffset;
    XYZoffsets[2] = _Zoffset;
}

void Gyroscope::ZeroCalibrate(unsigned int totSamples, unsigned int sampleDelayMS) 
{
    float xyz[3]; 
    float tmpOffsets[] = {0,0,0};
    
    for(int i = 0;i < totSamples;i++)
	{
        delay(sampleDelayMS);
        ReadGyro(xyz, (xyz) + 1, (xyz) + 2);
        tmpOffsets[0] += xyz[0];
        tmpOffsets[1] += xyz[1];
        tmpOffsets[2] += xyz[2];  
    }
    SetXYZOffsets(-tmpOffsets[0] / totSamples, -tmpOffsets[1] / totSamples, -tmpOffsets[2] / totSamples);
}

void Gyroscope::ReadGyro(float *_GyroX, float *_GyroY, float *_GyroZ)
{
    ReadFromRegister(GYRO_XOUT, 6, _buff);
    *_GyroX = ((_buff[0] << 8) | _buff[1]);
    *_GyroY = ((_buff[2] << 8) | _buff[3]); 
    *_GyroZ = ((_buff[4] << 8) | _buff[5]);
}

void Gyroscope::ReadGyroCal(float *_Gyro) 
{
    ReadGyro(_Gyro, _Gyro + 1, _Gyro + 2);
	
    _Gyro[0] += XYZoffsets[0];
    _Gyro[1] += XYZoffsets[1];
    _Gyro[2] += XYZoffsets[2];
    
    _Gyro[0] *=  1 / 14.375;
    _Gyro[1] *=  1 / 14.375;
    _Gyro[2] *=  1 / 14.375;
}

void Gyroscope::UpdateAngles() 
{
    float gyroOutputXYZ[3];
    float dt;
    
    now = micros();
    if(now > timeOfLastUpdate)
    {
        ReadGyroCal(gyroOutputXYZ);
        
        dt = (now - timeOfLastUpdate)/1000000.0;
        timeOfLastUpdate = now;
        
        dx = gyroOutputXYZ[0]*dt;
        dy = gyroOutputXYZ[1]*dt;
        dz = gyroOutputXYZ[2]*dt;
        
        anglesXYZ[0] += dx;
        anglesXYZ[1] += dy;
        anglesXYZ[2] += dz;
        
    }
    else
        timeOfLastUpdate = now;
}

float Gyroscope::ReturnXAngle()
{
    return anglesXYZ[0];
}

float Gyroscope::ReturnYAngle()
{
    return anglesXYZ[1];
}

float Gyroscope::ReturnZAngle()
{
    return anglesXYZ[2];
}

void Gyroscope::WriteToRegister(uint8_t _registerAddress, uint8_t _newRegisterValue) 
{
    Wire.beginTransmission(_I2C_address); 
    Wire.write(_registerAddress);
    Wire.write(_newRegisterValue); 
    Wire.endTransmission();
}

void Gyroscope::ReadFromRegister(uint8_t _registerAddress, uint8_t _numBytesToRead, uint8_t __buffer[]) 
{
    Wire.beginTransmission(_I2C_address); 
    Wire.write(_registerAddress);
    Wire.endTransmission();
    
    Wire.beginTransmission(_I2C_address); 
    Wire.requestFrom(_I2C_address, _numBytesToRead);
    uint8_t i = 0; 
    while (Wire.available()) 
	{
        _buff[i] = Wire.read();
        i++;
    }
    Wire.endTransmission();
}