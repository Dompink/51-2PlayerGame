#include<led.h>
#include<time.h>
#include<reg51.h>
#include<intrins.h>
/*******************************************************************************
* ������         : Hc595SendByte(unsigned char dat)
* ��������		   : ����ĳ��ĳ���е�LED����
* ����           : 
* ���         	 : 
*******************************************************************************/

void Hc595SendByte(unsigned char whatever)
{
	unsigned char a;
	SRCLK=0;
	RCLK=0;
	for(a=0;a<8;a++)
	{
		SER=whatever>>7;
		whatever<<=1;
		SRCLK=1;
		_nop_();
		_nop_();
		SRCLK=0;	
	}
	RCLK=1;
	_nop_();
	_nop_();
	RCLK=0;
}
/*******************************************************************************
* ������         : LED_Show
* ��������		   : ʹLED������ʾ����ͼ��
* ����           : �ĸ����XY����
* ���         	 : 
*******************************************************************************/

unsigned char tab;
//��ʾ���1ʤ��ͼ��//
unsigned char code A_win[8]={0x00,0x00,0x00,0x00,0x21,0x7f,0x01,0x00};
//��ʾ���2ʤ��ͼ��//
unsigned char code B_win[8]={0x00,0x00,0x27,0x45,0x45,0x45,0x39,0x00};
//��ѡͨ����//
unsigned char code T[8] = {0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};
//��ѡͨ����//
unsigned char code ROW_value[8] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};


void LED_Show(unsigned char x1,y1,x2,y2,x3,y3,x4,y4){

//��ʼ��
unsigned char CHARCODE[8]= {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
//ʹ��X��Y��  ����Ϊ1
if(x1!=0 && y1!=0){CHARCODE[x1-1]+=ROW_value[y1-1];}
if(x2!=0 && y2!=0){CHARCODE[x2-1]+=ROW_value[y2-1];}
if(x3!=0 && y3!=0){CHARCODE[x3-1]+=ROW_value[y3-1];}
if(x4!=0 && y4!=0){CHARCODE[x4-1]+=ROW_value[y4-1];}
//����ͼ��
for(tab=0;tab<8;tab++)
			{	
				Hc595SendByte(0x00);
				COMMONPORTS	= T[tab];
				Hc595SendByte(CHARCODE[tab]);	
			}
}

unsigned int  i;

void Awin(){
	for(i= 0; i<50; i++ )   //��˸50��
		{
for(tab=0;tab<8;tab++)
			{	
				Hc595SendByte(0x00);
				COMMONPORTS	= T[tab];
				Hc595SendByte(A_win[tab]);
				Delay1ms(10); //��
			}
}
		}

void Bwin(){
	for(i= 0; i<50; i++ )   //
		{
for(tab=0;tab<8;tab++)
			{	
				Hc595SendByte(0x00);
				COMMONPORTS	= T[tab];
				Hc595SendByte(B_win[tab]);
				Delay1ms(10);				
			}
}
		}


