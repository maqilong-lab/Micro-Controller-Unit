#include <REGX52.H>
#include "OneWire.h"

#define DS18B20_SKIP_ROM   0xCC
#define DS18B20_CONVERT_T  0x44
#define DS18B20_READ_SCRATCHPAD   0xBE


/**
  * @brief  DS18B20开始温度变换
  * @param  无
  * @retval 无
  */
void DS18B20_ConvertT(void)
{
	OneWire_Init();
	OneWire_SendByte(DS18B20_SKIP_ROM);
	OneWire_SendByte(DS18B20_CONVERT_T);
}


/**
  * @brief  DS18B20开始温度变换
  * @param  无
  * @retval 无
  */
float DS18B20_ReadT(void)
{
	unsigned char TLSB,TMSB;
	int Temp;
	float Temperture;
	OneWire_Init();
	OneWire_SendByte(DS18B20_SKIP_ROM);
	OneWire_SendByte(DS18B20_READ_SCRATCHPAD);
	TLSB = OneWire_RecieveByte();
	TMSB = OneWire_RecieveByte();
	Temp = (TMSB<<8) | TLSB;
	Temperture = Temp / 16.0;
	return Temperture;
}