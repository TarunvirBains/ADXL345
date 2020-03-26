#define ADXL345 (0x53);
#define ADXL345Ready (0x07); //data ready bit
#define ADLXL345_DataFormat (0x31) //Stuff like G range 
#define ADXL345X (0x32); //Xdata - 0x32 & 0x33
#define ADXL345Y (0x34); //Ydata - 0x34 & 0x35
#define ADXL345Z (0x36); //Zdata - 0x36 & 0x37


float GetAxis(char);

int GetX();
//int GetY();
//int GetZ();

//void autosleepON(void)

int GetG();