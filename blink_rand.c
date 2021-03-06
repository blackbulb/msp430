/*  
   Onjective of this program is to blink the red onboard led with random
   intervals. The random numbers are generated by a linear feedback-shift
   register http://en.wikipedia.org/wiki/Linear_feedback_shift_register
*/
#include <msp430.h>
#include <stdint.h>

void delay()
{
	unsigned int i = 0;
	while(++i < 30000);
}

int main(void)
{
	
	uint16_t lfsr = 0xACE1u;
	unsigned bit;
	unsigned period = 0;
	P1DIR = 1;
	P1OUT = 1;

	do
	{
		/* taps: 16 15 13 11; feedback polynomial: x^16 + x^14 + x^13 + x^11 + 1 */
		bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) ) & 1;
        	lfsr =  (lfsr >> 1) | (bit << 15);
        	++period;
		P1OUT = bit&1;
		delay();
    	} while(lfsr != 0xACE1u);
 
    return 0;
} 

