#ifndef __led_H_
#define __led_H_

#include<reg51.h>
#include<INTRINS.H>    
 
sbit SRCLK=P3^6;
sbit RCLK=P3^5;
sbit SER=P3^4;
#define COMMONPORTS		P0

void Hc595SendByte(unsigned char dat);
void LED_Show(unsigned char x1,y1,x2,y2,x3,y3,x4,y4);
void Awin();
void Bwin();
#endif