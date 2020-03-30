#ifndef __bgm1_H_
#define __bgm1_H_


#include <REG51.H>    
#include <INTRINS.H>    

sbit Beep =  P1^5 ; 

void int0();
void delaybgm (unsigned char m);
void delayms(unsigned char a);
void bgm1main();
#endif