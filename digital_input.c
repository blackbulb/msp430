#include<msp430.h>
main()
{
	P1DIR = 1;
	P1OUT = 1;
	
	while(1){
		/*Is zero when switch s2 is pressed p1.3 */
		if(P1IN>>3 == 0){P1OUT = 0;continue;} 
		P1OUT = 1;
	
	;}

}

