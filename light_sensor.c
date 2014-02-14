/*
 Objective of this program is to use the onboard led as a light sensor.
 When light is shined on the led, it produces a voltage, which is fed
 into the onboard adc (anlog to digital converter). Another led is 
 shined if a voltage is detected.
*/
 
#include <msp430.h>

#define LED_RED   0x01 
#define LED_GREEN 0x40 

void adc_init()
{
	ADC10CTL0 = ADC10ON | ADC10SHT_2 | SREF_0;
	ADC10CTL1 = INCH_0 | SHS_0 | ADC10DIV_0 | ADC10SSEL_0 | CONSEQ_0 ;
	ADC10AE0 = BIT0;
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
	int voltage;

	P1DIR = LED_GREEN;
	P1OUT = LED_GREEN;
	
	adc_init();

	while(1)
		{
		start_conversion();
		while(converting())
			{}
		voltage = ADC10MEM;
		if(voltage>300)
		//if(ADC10MEM>300)
			{
				//P1DIR = LED_RED;
				//P1OUT = LED_RED;		
				P1DIR = 0;
				P1OUT = 0;
			}
		else
			{
				P1DIR = LED_GREEN;
				P1OUT = LED_GREEN;
			}	
		delay = 0;
		while(delay++ < 10000);//Dela between successive ADC readings
	}
}
