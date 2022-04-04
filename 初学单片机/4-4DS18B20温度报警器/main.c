#include <REGX52.H>
#include "DS18B20.h"
#include "LCD1602.h"
#include "Delay.h"
#include "AT24C02.h"
#include "Key.h"
#include "Timer0.h"

float Temperature,TShow;
char TH,TL;
unsigned char KeyNum;

void main( )
{
	DS18B20_ConvertT();
	Delay(1000);
	
	TH = AT24C02_ReadByte(0);				//读取TH值
	TL = AT24C02_ReadByte(1);				//读取TL值
	if(TH > 125 || TL < -55 || TH <= TL)	//判断TH和TL是否有误
	{
		TH = 30;
		TL = 18;
	}
	LCD_Init();
	LCD_ShowString(1,1,"T:");				//LCD屏幕显示
	LCD_ShowString(2,1,"TH:");
	LCD_ShowString(2,9,"TL:");
	LCD_ShowSignedNum(2,4,TH,3);
	LCD_ShowSignedNum(2,12,TL,3);
	Timer0_Init();
	while(1)
	{
		KeyNum = Key();
		
		/* 温度读取显示 */
		DS18B20_ConvertT();
		Temperature = DS18B20_ReadT();		//读取温度值
		if(Temperature < 0)					//判断温度值，在屏幕上显示相应的符号和值
		{
			LCD_ShowChar(1,3,'-');
			TShow = -Temperature;
		}
		else
		{
			LCD_ShowChar(1,3,'+');
			TShow = Temperature;
		}
		LCD_ShowNum(1,4,TShow,3);					//显示温度数值
		LCD_ShowChar(1,7,'.');						//显示小数点
		LCD_ShowNum(1,8,(unsigned long)(TShow*100)%100,2); 		//显示小数值
	
		/* 阈值判断显示 */
		if(KeyNum)								//根据按键值的不同，对阈值做出改变
		{
			if(KeyNum == 1)
			{
				TH++;
				if(TH > 125){TH = 125;}
			}
			if(KeyNum == 2)
			{
				TH--;
				if(TH <= TL){TH++;}
			}
			if(KeyNum == 3)
			{
				TL++;
				if(TL >= TH){TL--;}
			}
			if(KeyNum == 4)
			{
				TL--;
				if(TL < -55){TL = -55;}
			}
			LCD_ShowSignedNum(2,4,TH,3);		//更新显示阈值
			LCD_ShowSignedNum(2,12,TL,3);
			AT24C02_WriteByte(0,TH);			//将最新阈值写入AT24C02
			Delay(5);
			AT24C02_WriteByte(1,TL);
			Delay(5);
		}
		if(Temperature > TH)					//判断温度是否超出阈值，并作出显示反馈
		{
			LCD_ShowString(1,12,"OV:H");
		}
		else if(Temperature < TL)
		{
			LCD_ShowString(1,12,"OV:L");
		}
		else
		{
			LCD_ShowString(1,12,"    ");
		}
	}
}

void Timer0_Routine() interrupt 1      //定时器中断函数
{
	static unsigned int T0Count;
	TL0 = 0x18;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	T0Count++;
	if(T0Count >= 20)
	{
		T0Count =  0;
		Key_Loop();
	}
}