/**

**/
#include<msp430.h>
main()
{
	P1DIR = 0;
	while(1){
	
		if(P1IN>>3 == 0){break;}
	
	;}
	P1DIR = 1;
	P1OUT = 1;

}

