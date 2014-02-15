/* The objective of this program is to use the watchdog
   as a timer. In the right setting, the watchdog will
   create an interrupt when it counts to the indicated
   value, and the user-defined isr gets executed. Here,
   we toggle the onboard red LED.
*/
#include <msp430.h>
#define LED1 BIT0
__attribute__((interrupt(WDT_VECTOR)))
void isr()
{
P1OUT ^= LED1;
}
//initialize watchdog as interval timer
void watchdog_init()
{
// clk = smclk/32768, interval timer mode
// wdt enabled (ie, WDTHOLD = 0)
WDTCTL = 0x5A10;
/* Last 3 bits are zero which is fine as it implies SMCLK/32768*/
IE1 = 1;//Interrupt enabled
}
main()
{
P1DIR = LED1;
__enable_interrupt();
watchdog_init();
while(1);
}

