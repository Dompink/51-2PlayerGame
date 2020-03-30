/*******************************************************************************
* 函数名         : Delay10ms(void)
* 函数功能		   : 延迟10ms
* 输入           : 无
* 输出         	 : 无
*******************************************************************************/

#include<time.h>
void Delay10ms(void)   //误差 0us
{
    unsigned char a,b,c;
    for(c=1;c>0;c--)
        for(b=38;b>0;b--)
            for(a=130;a>0;a--);
}

void Delay1ms(unsigned int a)
{
	unsigned int b,c;
	for(c=a;c>0;c--)
		for(b=110;b>0;b--);
}