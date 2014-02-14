#include<msp430.h>
main()
{
	P1DIR = 1;
	P1OUT = 1;
	
	while(1){
		/*Is zero when switch s2 is pressed p1.3 */
		if(((P1IN>>3)&1) == 0)
		{
			P1OUT = 0;
			if(P1DIR == 1){
				P1DIR = 0X40;
			}		
			else if(P1DIR == 0X40)
			{
				P1DIR = 1;
			}

		} 
		else
		{
			P1OUT = P1DIR;
		}
	
	;}

}

