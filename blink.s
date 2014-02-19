org 0xf800
start:
; stop the watchdog
mov.w #0x5a80, &0x0120
; setting the red led
mov.b #1, &0x22
mov.b #0, &0x21
L1:
xor.w #0xff, &0x21
; delay loop
mov.w #0xffff, R7
L2:
sub.w #1, R7
jnz L2
jmp L1
loop:
jmp loop
org 0xfffe
dw start

