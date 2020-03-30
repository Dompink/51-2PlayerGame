/*******************************************************************************
* ʵ �� ��		˫�˴�ս��Ϸ	 
* ����			Group   
* ʵ��Ч��   A��B����ƶ����䣬���ڽ����󲥷�bgm    
* ע    ��		 
*******************************************************************************/
#include<reg51.h>
#include<intrins.h>
#include<time.h>
#include<bgm1.h>
#include<bgm2.h>
#include<led.h>
#include<button.h>


/*******************************************************************************
* �� �� ��         : main
* ��������         : ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
//�������
unsigned char AL,AR,AF,BL,BR,BF;
unsigned char LA,LB,AU,BU,SA,SB;
unsigned char nA,nB,LAX,LAY,LBX,LBY;
unsigned char E,winner;
unsigned char n_min,n_step;
//������
void main(void)
{
	//��ʼ������
	LA=4;LB=5;   //��ʼλ�� 
	AU=BU=100;   //����״̬
	SA=SB=0;     //�ӵ�״̬
	LAX=LAY=LBX=LBY=0;   //�ӵ�λ��
	n_min=50;        //�����ƶ�������
	n_step=4;    //�ӵ��ƶ�����
	nA=nB=0;     //�ӵ���ǲ���
	E=winner=0;     //ʤ������Ϊ0
  //δ����ʤ��ǰһֱѭ��
while (E==0){
  //�������ò���+1/��ʼ�� 
	AU++;BU++;
  AL=AR=AF=BL=BR=BF=0;
	//����ɨ�貢�Ը�������ֵ
switch(KeyDown()+1){
	case(5):AL=1;break;
	case(13):AR=1;break;
	case(9):AF=1;break;
	case(8):BR=1;break;
	case(12):BF=1;break;
	case(16):BL=1;break;
	}

	if ( (AL == 1) && (AU>= n_min) ) {      //A�����ƶ�һ��
	AU=0;  LA++;
	}
	
	if ( (AR == 1) && (AU>= n_min) ) {      //A�����ƶ�һ��
	AU=0;  LA--;
	}

	if ( (BL == 1) && (BU>= n_min) ) {      //B�����ƶ�һ��
	BU=0;  LB--;
	}
	
	if ( (BR == 1) && (BU>= n_min) ) {      //B�����ƶ�һ��
	BU=0;  LB++;
	}

	if (LA==9 || LA==0) {winner=2; E=1;break;}   //A�Ƴ����⣬B��ʤ
  if (LB==9 || LB==0) {winner=1; E=1;break;}   //B�Ƴ����⣬B��ʤ
	
  if (AF==1 && SA==0) {
	SA++; //A����
	LAX = 2; LAY = LA; 	//A�ӵ�λ��
}

  if (BF==1 && SB==0) {
	SB++; //B����
	LBX = 7; LBY = LB; 	//B�ӵ�λ��
}

if (SA!=0){
	if(SA==7 && LAY==LB) {E=1;winner=1;SA=0;nA=0;break;};   //A����B,AӮ
	if(nA==n_step){   //��Ҫ�ƶ�
		nA=0; //����nA
		if(SA==7){ SA=0;LAX=0;LAY=0;}   //δ����
		else {SA++;LAX++;} //δ�ƶ����� �����ƶ�
		}
	else {nA++;}  //
	}

if (SB!=0){
	if(SB==7 && LBY==LA) {E=1;winner=2;SB=0;nB=0;break;};
	if(nB==n_step){  
		nB=0; 
		if(SB==7){ SB=0;LBX=0;LBY=0;}   
		else {SB++;LBX--;} 
		}
	else {nB++;}  
	}

//��ʾ����ͼ��
LED_Show(1,LA,8,LB,LAX,LAY,LBX,LBY);
}
//չʾAʤ��
if(winner==1)
{
 Awin();
 bgm1main();
}

if(winner==2)
{
 Bwin();
 bgm1main();
}	

//��ѭ��
while(E==1){
	}
}
