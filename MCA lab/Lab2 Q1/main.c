#include "led.h"
#include<lpc214x.h>

int main(){ 
	PINSEL0 |= 0xF0F0;
	IODIR0 |= (0xF<<16); 
	VICIntEnable = (1<<1);
	VICIntEnable = (1<<3);
	VICVectAddr0 = (unsigned int) increment;
  VICVectCntl0 = (1<<5)| 14; 
	VICVectAddr1 = (unsigned int) decrement;
  VICVectCntl1 = (1<<5) | 15;   
	while(1);
	return 0;
}
