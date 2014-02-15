/*
	The objective of this program is to interface the launchpad with
	a potentiometer. The voltage on P1.4 is varied using the potentiometer
	from a supply voltage across Vcc and gnd of the launchpad.
*/
 
#include <msp430.h>

#define LED_RED   0x01 
#define LED_GREEN 0x40 

void adc_init()
{
	ADC10CTL0 = ADC10ON | ADC10SHT_2 | SREF_0;
	ADC10CTL1 = INCH_4 | SHS_0 | ADC10DIV_0 | ADC10SSEL_0 | CONSEQ_0 ;
	ADC10AE0 = BIT4;
	ADC10CTL0 |= ENC ;
}

void start_conversion()
{
	ADC10CTL0 |= ADC10SC;
}

unsigned int converting()
{
	return ADC10CTL1 & ADC10BUSY;
}

void main()
{
	int delay;
	int reading;

	P1DIR = LED_GREEN;
	P1OUT = LED_GREEN;
	
	adc_init();

	while(1)
		{
		start_conversion();
		while(converting())
			{}
		reading = ADC10MEM;
		if(reading < 255){
			P1DIR = P1OUT = 0;
		}
		else if(reading < 511){
			P1DIR = P1OUT = 1;
		}
		else if(reading < 511+256){
			P1DIR = P1OUT = 0X40;
		}
		else{
			P1DIR = P1OUT = 0x41;
		}
		//delay = 0;
		//while(delay++ < 10000);//Dela between successive ADC readings
	}
}
