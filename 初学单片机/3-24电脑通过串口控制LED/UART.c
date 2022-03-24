#include <REGX52.H>

/**
  * @brief 	串口初始化  //4800bps@11.0592MHz
  * @param	无
  * @retval	无
  */
void UART_Init()    	
{
	SCON = 0x50;
	PCON = 0x80;
	TMOD &= 0x0F;
	TMOD |= 0x20;
	TL1 = 0xF4;		//设置定时初始值
	TH1 = 0xF4;		//设置定时重载值
	ET1 = 0;		//禁止定时器%d中断
	TR1 = 1;		//启动定时器1
	EA = 1;			//启动CPU总中断
	ES = 1;			//启动串口中断
}


/**
  * @brief	串口发送一个数据字节
  * @param	Byte要发送的一个字节的数据
  * @retval	无
  */
void UART_SendByte(unsigned char Byte)
{
	SBUF = Byte;
	while(TI == 0);
	TI == 0;
}

/*      **串口中断函数模板
void UART_Rountine() interrupt 4	
{
	if(RI == 1)
	{
		
		RI = 0;
	}
}
*/