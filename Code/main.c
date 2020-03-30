/*******************************************************************************
* 实 验 名		双人大战游戏	 
* 作者			Group   
* 实验效果   A，B玩家移动互射，并在结束后播放bgm    
* 注    意		 
*******************************************************************************/
#include<reg51.h>
#include<intrins.h>
#include<time.h>
#include<bgm1.h>
#include<bgm2.h>
#include<led.h>
#include<button.h>


/*******************************************************************************
* 函 数 名         : main
* 函数功能         : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
//定义参数
unsigned char AL,AR,AF,BL,BR,BF;
unsigned char LA,LB,AU,BU,SA,SB;
unsigned char nA,nB,LAX,LAY,LBX,LBY;
unsigned char E,winner;
unsigned char n_min,n_step;
//主程序
void main(void)
{
	//初始化参量
	LA=4;LB=5;   //初始位置 
	AU=BU=100;   //操作状态
	SA=SB=0;     //子弹状态
	LAX=LAY=LBX=LBY=0;   //子弹位置
	n_min=50;        //左右移动允许间隔
	n_step=4;    //子弹移动周期
	nA=nB=0;     //子弹标记参量
	E=winner=0;     //胜利者置为0
  //未决出胜负前一直循环
while (E==0){
  //操作标置参量+1/初始化 
	AU++;BU++;
  AL=AR=AF=BL=BR=BF=0;
	//按键扫描并对各参量赋值
switch(KeyDown()+1){
	case(5):AL=1;break;
	case(13):AR=1;break;
	case(9):AF=1;break;
	case(8):BR=1;break;
	case(12):BF=1;break;
	case(16):BL=1;break;
	}

	if ( (AL == 1) && (AU>= n_min) ) {      //A往左移动一格
	AU=0;  LA++;
	}
	
	if ( (AR == 1) && (AU>= n_min) ) {      //A往右移动一格
	AU=0;  LA--;
	}

	if ( (BL == 1) && (BU>= n_min) ) {      //B往左移动一格
	BU=0;  LB--;
	}
	
	if ( (BR == 1) && (BU>= n_min) ) {      //B往右移动一格
	BU=0;  LB++;
	}

	if (LA==9 || LA==0) {winner=2; E=1;break;}   //A移出场外，B获胜
  if (LB==9 || LB==0) {winner=1; E=1;break;}   //B移出场外，B获胜
	
  if (AF==1 && SA==0) {
	SA++; //A开火
	LAX = 2; LAY = LA; 	//A子弹位置
}

  if (BF==1 && SB==0) {
	SB++; //B开火
	LBX = 7; LBY = LB; 	//B子弹位置
}

if (SA!=0){
	if(SA==7 && LAY==LB) {E=1;winner=1;SA=0;nA=0;break;};   //A击中B,A赢
	if(nA==n_step){   //需要移动
		nA=0; //重置nA
		if(SA==7){ SA=0;LAX=0;LAY=0;}   //未击中
		else {SA++;LAX++;} //未移动到边 继续移动
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

//显示点阵图案
LED_Show(1,LA,8,LB,LAX,LAY,LBX,LBY);
}
//展示A胜利
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

//死循环
while(E==1){
	}
}
