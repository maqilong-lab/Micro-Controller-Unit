#include <REGX52.H>

unsigned char Key_FlagNum;


/**
  * @brief	按键返回函数
  * @param	无
  * @retval	Temp：临时保存的按键值
  */
unsigned char Key(void)
{
	unsigned char Temp;
	Temp = Key_FlagNum;
	Key_FlagNum = 0;
	return Temp;
}


/**
  * @brief	得到按键值函数
  * @param	无
  * @retval	KeyNumber：返回所按下按键的值
  */
unsigned char Key_GetState(void)
{
	unsigned char KeyNumber = 0;
	
	if(P3_1 == 0){KeyNumber = 1;}
	if(P3_0 == 0){KeyNumber = 2;}
	if(P3_2 == 0){KeyNumber = 3;}
	if(P3_3 == 0){KeyNumber = 4;}
	
	return KeyNumber;
}


/**
  * @brief	按键循环函数
  * @param	无
  * @retval	无
  */
void Key_Loop(void)
{
	static unsigned char NowState,LastState;
	LastState = NowState;					 //将现在按键的状态赋值给上次的按键状态
	NowState = Key_GetState();				 //取得最新的按键状态
	if(LastState == 1 && NowState == 0) 	 //按键1按下   ：通过最新按键状态与上次按键状态来判断按键的所处状态是按下还是抬起，下同
	{
		Key_FlagNum = 1;
	}
	
	if(LastState == 2 && NowState == 0)		//按键2按下
	{
		Key_FlagNum = 2;
	}
	
	if(LastState == 3 && NowState == 0)		//按键3按下
	{
		Key_FlagNum = 3;
	}
	
	if(LastState == 4 && NowState == 0)		//按键4按下
	{
		Key_FlagNum = 4;
	}
}