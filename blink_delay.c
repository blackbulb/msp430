/* Objective of the program is to blink the onboard red
   led, by togglint its output flag in fixed intervals
   calculated by a delay loop.
*/
#include <msp430.h>
#define LED1 BIT0
#define TOGGLE_LED1 (P1OUT ^= LED1)

void delay()
{
	unsigned int i = 0;
	while(++i < 30000);
}

main()
{
	P1OUT = 0;
	P1DIR = 1;
	
	while(1) {
		TOGGLE_LED1;
		delay();
	}
}
