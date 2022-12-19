#include<lpc214x.h>

int seq[4]={8,4,2,1};
unsigned char rec;
void delay(int ms){ 
	for(int j=0;j<ms;j++)
		for(int i=0;i<50000;i++);
}

void pllinit(){ 
  PLL0CON=0x01;          
  PLL0CFG=0x24;        
  PLL0FEED=0XAA;        
  PLL0FEED=0X55;
  while((PLL0STAT&(1<<10))==0);   
  PLL0CON=0x03;          
  PLL0FEED=0XAA;
  PLL0FEED=0X55;
  VPBDIV = 0x01;          
}

void uartinit(){ 
	PINSEL0=0X5;
  U0LCR=0X83;            
  U0DLL=135;
  U0DLM=1;
  U0LCR=0X03; 
}

unsigned char rec_char(){ 
	unsigned char a;
	while((U0LSR &(1<<0))==0);
	a=U0RBR;
	return a;
}

void tx(unsigned char c){
  while((U0LSR&(1<<5))==0);    
  U0THR=c;
}

void anticlockwise(){ 
	IOCLR0|=0xF<<16;
	for(int i=0;i<=3;i++){ 
		IOSET0|=seq[i]<<16;
		delay(2);
		IOCLR0|=seq[i]<<16;
		delay(2);
	}
}

void clockwise(){ 
	IOCLR0|=0xF<<16;
	for(int i=3;i>=0;i--){ 
		IOSET0|=seq[i]<<16;
		delay(2);
		IOCLR0|=seq[i]<<16;
		delay(2);
	}
}

