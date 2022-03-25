#include <REGX52.H>
#include "Delay.h"

sbit RCK = P3^5;	//RCLK
sbit SCK = P3^6;	//SCLK
sbit SER = P3^4;	//SER


/**
  * @brief	74HC595写入一个字节
  * @param	要写入的字节
  * @retval	无
  */
void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i;
	for(i = 0; i < 8; i++)
	{
		SER = Byte&(0x80>>i);
		SCK = 1;
		SCK = 0;
	}
	RCK = 1;
	RCK = 0;
}


/**
  * @brief	LED 点阵屏显示一列数据
  * @param	Column 要显示的列，范围：0~7，0为显示屏最左边一列
  * @param	Data要显示列的数据，高位在上，低位在下
  * @retval 无
  */
void MatrixLED_ShowColumn(unsigned char Column,Data)
{
	_74HC595_WriteByte(Data);
	P0 = ~(0x80>>Column);
	Delay(1);
	P0 = 0xFF;
}

void main( )
{
	SCK = 0;
	RCK = 0;
	while(1)
	{					//显示一个爱心
		MatrixLED_ShowColumn(0,0x30);	   
		MatrixLED_ShowColumn(1,0x78);
		MatrixLED_ShowColumn(2,0x7C);
		MatrixLED_ShowColumn(3,0x3E);
		MatrixLED_ShowColumn(4,0x7C);
		MatrixLED_ShowColumn(5,0x78);
		MatrixLED_ShowColumn(6,0x30);
	}
}