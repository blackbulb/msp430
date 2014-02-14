/* 
   Objective of this program is to use the internal timer of msp430
   to blink the onboard red led, rather than using a delay loop
   as in the previous exercise 
*/
#include <msp430.h>

main()
{
	P1DIR=1;
	P1OUT=1;
	
	/*Initializing TACTL, Timer_A Control Register*/
	TACTL=0;

	/*Choosing clock source*/
	/*D9,D8=10 implies SMCLK is used*/
	TACTL|=(1<<9);

	/*Choosing the continuous mode*/
	/*D5,4=10 implies continuous mode*/
	TACTL|=(1<<5);


	while(1) {

		/*D0 of TACTL is the TAIFG - the interrupt bit*/
		while((TACTL&1)==0);

		TACTL=(TACTL&~1);/*Unset D0*/
		P1OUT^=1;/*Toggle LED1*/
	}
}


