#include <REGX52.H>
#include <INTRINS.H>

void Delay100ms()		//@12.000MHz
{
	unsigned char i, j;

	i = 195;
	j = 138;
	do
	{
		while (--j);
	} while (--i);
}



int main()
{
	while(1)
	{
		P1=0xFE;
		Delay100ms();
		P1=0xFF;
		Delay100ms();
		P1=0xFD;
		Delay100ms();
		P1=0xFF;
		Delay100ms();
		P1=0xFB;
		Delay100ms();
		P1=0xFF;
		Delay100ms();
		P1=0xF7;
		Delay100ms();
		P1=0xFF;
		Delay100ms();
		P1=0xEF;
		Delay100ms();
		P1=0xFF;
		Delay100ms();
		P1=0xDF;
		Delay100ms();
		P1=0xFF;
		Delay100ms();
		P1=0xBF;
		Delay100ms();
		P1=0xFF;
		Delay100ms();
		P1=0x7F;
		Delay100ms();
		P1=0xFF;
		Delay100ms();
		P1=0x00;
		Delay100ms();
	};
		
}
