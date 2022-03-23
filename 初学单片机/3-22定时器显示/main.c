#include <REGX52.H>
#include "LCD1602.h"
#include "Timer0.h"

unsigned char sec,min,hour;

void main( )
{
	LCD_Init();
	Timer0_Init();
	
	LCD_ShowString(1,1,"Clock:");
	LCD_ShowString(2,1,"  :  :  ");
	
	while(1)
	{
		LCD_ShowNum(2,1,hour,2);
		LCD_ShowNum(2,4,min,2);
		LCD_ShowNum(2,7,sec,2);
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x18;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	T0Count++;
	if(T0Count >= 1000)
	{
		T0Count =  0;
		sec++;
		if(sec >= 60)
		{
			sec = 0;
			min++;
			if(min >= 60)
			{
				min = 0;
				hour++;
				if(hour > 23)
					hour = 0;
			}
		}
	}
}