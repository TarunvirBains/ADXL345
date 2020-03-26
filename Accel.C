//some help from https://github.com/adafruit/Adafruit_ADXL345/blob/master/Adafruit_ADXL345_U.cpp

#include "IIC0_New.h"
#include "derivative.h"
#include "ADXL345.h"


//assumes 12C initialized


//With the SDO/ALT ADDRESS pin high, the 7-bit I2C address for the device is 0x1D, followed bythe R/W bit. This translates to 0x3A for a write and 0x3B for a read.
//An alternate I2C address of 0x53 (followed by the R/W bit) can be chosen by grounding the SDO/ALT ADDRESS pin (Pin 12). This translates to 0xA6 for a write and 0xA7 for a read. 
unsigned int GetAccelX()

//return the raw sensor data
int GetAxis(char register)
{
  	//while((IIC0_Read(ADXL345, ADXL345Ready)&0b00001111)==0);	//check status of accel
	return IIC0_ReadA16(ADXL345 ,register); //this might not be a float???
}

int GetX()
{
	int val = GetAxis(ADXL345X);
	return val; //once we've analyzed this we can convert it to degrees.		
}

int GetY()
{
	int val = GetAxis(ADXL345Y);
	return val;			
}

int GetZ()
{
	int val = GetAxis(ADXL345Y);
	return val;		
	return 0;
}

//void autosleepON()
//{
	//page 16/17 of datasheet
	//Register 0x2D OR 
//}


//0 = 2g
//1 = 4g
//2 = 8g
//3 = 16g
//2 is very sensitive, 16 may be better for more vibrations.  
//uint GetG()
//{
	//8-bit read
	//return (I2Cread(ADLXL345_DataFormat) & 0x03) //return the current G range. 
//}


//0 = 2g
//1 = 4g
//2 = 8g
//3 = 16g
//2 is very sensitive, 16 may be better for more vibrations.  
//uint SetG(uchar range)
//{
	uint curr = (I2Cread(ADLXL345_DataFormat)) //read all eight bits to preserve state
	
	if(range > 3) // high values will not be accepted!
		range = 3;
	//update range
	curr &= 0xF0; //clear 
	curr |= range; //set the byte to the desired value
	
	//8-bit write
	//return (read(ADLXL345_DataFormat) & 0x03) //return the current G range. 
//}

