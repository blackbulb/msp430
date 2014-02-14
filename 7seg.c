#include<msp430.h>

void delay()
{
	int i;
	for(i=0;i<30000;++i);
}
/* a b c d e f g of the display correspond to 1 2 4 8 16 32 64 bits of P1DIR and P1OUT */
main()
{
	P1OUT=0;
	P1DIR=0;
	while(1){
		/*  Zero */
		P1DIR=P1OUT=(1+2+4+8+16+32);
		delay();
		/* One */
		P1DIR=P1OUT=(2+4);
		delay();
		/* Two */
		P1DIR=P1OUT=(1+2+8+16+64);
		delay();
		/* Three */
		P1DIR=P1OUT=(1+2+8+64);
		delay();
		/* Four */
		P1DIR=P1OUT=(2+4+32+64);
		delay();
		/* Five */
		P1DIR=P1OUT=(1+2+4+32+64);
		delay();
		/* Six */
		P1DIR=P1OUT=(1+4+8+16+32+64);
		delay();
		/* Seven */
		P1DIR=P1OUT=(1+2+4);
		delay();
		/* Eight */
		P1DIR=P1OUT=(1+2+4+8+16+32);
		delay();
		/* Nine */
		P1DIR=P1OUT=(1+2+4+32+64);
		delay();
		
	}
}

