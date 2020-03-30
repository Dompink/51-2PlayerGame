/*******************************************************************************
* �� �� ��         : KeyDown
* ��������		     : ����а������²���ȡ��ֵ
* ��    ��         : ��
* ��    ��         : KeyValue
*******************************************************************************/
#include<button.h>
#include<reg51.h>
#include<time.h>

#define GPIO_DIG P0
#define GPIO_KEY P1
unsigned char KeyValue;

char KeyDown()
{
	char a=0;
	KeyValue=0;
	GPIO_KEY=0x0f;
	if(GPIO_KEY!=0x0f)//��ȡ�����Ƿ���
	{
		Delay10ms();//��ʱ10ms��������
		if(GPIO_KEY!=0x0f)//�ٴμ������Ƿ���
		{
			
			//������
			GPIO_KEY=0X0F;
			switch(GPIO_KEY)
			{
				case(0X07):	KeyValue=0;break;
				case(0X0b):	KeyValue=1;break;
				case(0X0d): KeyValue=2;break;
				case(0X0e):	KeyValue=3;break;
			}
			//������
			GPIO_KEY=0XF0;
			switch(GPIO_KEY)
			{
				case(0X70):	KeyValue=KeyValue;break;
				case(0Xb0):	KeyValue=KeyValue+4;break;
				case(0Xd0): KeyValue=KeyValue+8;break;
				case(0Xe0):	KeyValue=KeyValue+12;break;
			}
		}
	}
	return KeyValue;
}