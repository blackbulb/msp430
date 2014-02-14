/* Objective of this program is to blink 4 leds, connected
   via breadboard to the lauchpad, sequentially
   The leds are connected to the port P1
*/
#include<msp430.h>

void delay()
{
	int i;
	for(i=0;i<30000;++i);
}

main()
{

	while(1){
		P1OUT=1;
		P1DIR=1;
		delay();
		P1OUT=2;
		P1DIR=2;
		delay();
		P1OUT=4;
		P1DIR=4;
		delay();
		P1OUT=8;
		P1DIR=8;
		delay();
	}
}

