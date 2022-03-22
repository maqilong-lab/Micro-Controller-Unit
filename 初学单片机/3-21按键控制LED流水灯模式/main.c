#include <REGX52.H>
#include <INTRINS.H>
#include "Timer0.h"
#include "Key.h"

/**
  * @brief  定时器0初始化，1毫秒@11.0592MHz
  * @param  无
  * @retval 无
  */
  
unsigned char KeyNum,LEDMode;

void main( )
{
	P2 = 0xFE;
	Timer0_Init();
	while(1)
	{
		KeyNum = Key();
		if(KeyNum)
		{
			if(KeyNum == 1)
			{
				LEDMode++;
				if(LEDMode >= 2)
					LEDMode = 0;
			}
		}
	} 
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x18;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	T0Count++;
	if(T0Count >= 500)
	{
		T0Count =  0;
		if(LEDMode == 0)
			P2 = _crol_(P2,1);
		if(LEDMode == 1)
			P2 = _cror_(P2,1);	
	}
}

/*定时器中断函数模板
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0x18;		//设置定时初始值
	TH0 = 0xFC;		//设置定时初始值
	T0Count++;
	if(T0Count >= 1000)
	{
		T0Count =  0;
	}
}
*/