#include <REGX52.H>

void Delay1ms(xms)	
{
	unsigned char i, j;
	while(xms)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
}


void main()
{
	while(1)
	{
		if(P3_0 == 0)
		{
			Delay1ms(20);
			while(P3_0 == 1);
			Delay1ms(20);
			
			P1_0 =~ P1_0;
		}
	}
}