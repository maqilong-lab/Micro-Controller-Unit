#include <REGX52.H>

void Delay(unsigned int xms)		
{
	unsigned char i, j;
	while(xms--)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
}


void main()
{
	unsigned char LEDNum = 0;
	while(1)
	{
		if(P3_0 == 0)
		{
			Delay(20);
			while(P3_0 == 0);
			Delay(20);
			
			LEDNum++;
			P1 =~ LEDNum;
		}
	}
}