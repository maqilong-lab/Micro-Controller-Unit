#include <REGX52.H>

void Delay1ms(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;

	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
	xms--;
}


int main()
{
	while(1)
	{
		int t = 1000;
		P1=0xFE;
		Delay1ms(t);
		P1=0xFF;
		Delay1ms(t);
		P1=0xFD;
		Delay1ms(t);
		P1=0xFF;
		Delay1ms(t);
		P1=0xFB;
		Delay1ms(t);
		P1=0xFF;
		Delay1ms(t);
		P1=0xF7;
		Delay1ms(t);
		P1=0xFF;
		Delay1ms(t);
		P1=0xEF;
		Delay1ms(t);
		P1=0xFF;
		Delay1ms(t);
		P1=0xDF;
		Delay1ms(t);
		P1=0xFF;
		Delay1ms(t);
		P1=0xBF;
		Delay1ms(t);
		P1=0xFF;
		Delay1ms(t);
		P1=0x7F;
		Delay1ms(t);
		P1=0xFF;
		Delay1ms(t);
		P1=0x00;
		Delay1ms(t);
	}
}