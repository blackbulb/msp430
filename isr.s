org 0xf800
main:
;stop the watchdog
mov.w #0x5a80, &0x0120
;Initialize port p1 to output/logic low
mov.b #1, &0x22
mov.b #0, &0x21
mov.w #0x280, R1
;Configure TACTL
mov.w #0x2e2, &0x160
;Enable interrupts
eint

L1: jmp L1 ;Infinite loop

timer_isr:
;Toggle led
xor.b #1,&0x21
;Clear the interrupt vector by clearing the last bit of TACTL
and.w #-2,&0x160
reti ;reti restores the status register too, unlike ret

org 0xfff0
dw timer_isr

org 0xfffe
dw  main
