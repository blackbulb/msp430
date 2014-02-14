/*
   Objective of the program is: First the red led is on.
   When the switch s2 is pressed, and released the red led
   goes off and green led goes on. Again pressing and releasing
   s2 toggles the ON state of the red and green leds.
*/

#include<msp430.h>
main()
{
	P1DIR = 1;
	P1OUT = 1;
	
	while(1){
		/*Is zero when switch s2 is pressed */
		if(((P1IN>>3)&1) == 0)
		{
		        /*No change of lights while switch is pressed */
			while(((P1IN>>3)&1) == 0);
			/* Toggles ON state of red and greed leds */
			if(P1DIR == 1){
				P1OUT =	P1DIR = 0X40;
			}		
			else if(P1DIR == 0X40)
			{
				P1OUT = P1DIR = 1;
			}

		} 
		

	
	;}

}

