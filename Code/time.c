/*******************************************************************************
* ������         : Delay10ms(void)
* ��������		   : �ӳ�10ms
* ����           : ��
* ���         	 : ��
*******************************************************************************/

#include<time.h>
void Delay10ms(void)   //��� 0us
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