#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int PassWord;
unsigned int count;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"PassWord");
	while(1)
	{
		KeyNum = MatrixKey();
		if(KeyNum)
		{
			if(KeyNum <= 10)
			{
				if(count < 4)   				//输入四位密码
				{
					PassWord *= 10;				//密码左移一位
					PassWord += KeyNum % 10;	//获取一位密码								
					count++;						//计位
				}
				LCD_ShowNum(2,1,PassWord,4);	//更新显示
			}
			if(KeyNum == 11)					//S11按键按下为确认
			{
				if(PassWord == 2345)
				{
					LCD_ShowString(1,14,"OK ");		//密码正确显示OK
					PassWord = 0;					//密码清0
					count = 0;						//计数清0
					LCD_ShowNum(2,1,PassWord,4);	//更新显示
				}
				else
				{
					LCD_ShowString(1,14,"ERR");		//密码错误显示ERR
					PassWord = 0;					//密码清0
					count = 0;						//计数清0
					LCD_ShowNum(2,1,PassWord,4);	//更新显示
				}
			}
			
			if(KeyNum == 12)					//按S12键取消
			{
				PassWord = 0;					//密码清0
				count = 0;						//计数清0
				LCD_ShowNum(2,1,PassWord,4);	//更新显示
			}
		}
	}
}
