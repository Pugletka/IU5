start:

.include "m16def.inc" 

.list 

.def t=r20

.def temp=r16 

.def kold=r17

.def k=r18

.def s=r19
 
.def k__z=r20
 
.def k___=r21

.def s___=r22

;--------------------------------------------

.cseg 

.org 0 

;--------------------------------------------

ldi temp,0x80 

out acsr,temp

;--------------------------------------------

ldi temp,0x00 ; 0 --> temp

out ddrd,temp 

ldi temp,0xFF ; 0xff --> temp

out ddrb,temp 

out portd,temp 

;---------------------------------------------

ldi kold, 0x00 ; 0--->kold

ldi s, 0x00 ; 0--->s___

out portb, s ; s___(=0)

;---------------------------------------------
ldi temp, 0b101 ; ??????????? 1024 
out tccr0, temp 
ldi temp, 135 ; ????????? ???????? ??????? 
out osccal, temp 
 
ldi temp,low(RAMEND) ; ????????????? ????? 
out spl,temp 
ldi temp,high(RAMEND)
out sph,temp 
;---------------------------------------------

read: ;

in k, pind 

cp k, kold 

breq read 

tst kold 

brne remem 

tst k 

breq remem 

jmp lbl1 ;

;---------------------------------------------

remem: 

mov kold, k  

jmp read 

;---------------------------------------------

lbl1:
cpi k, 0x01
breq red
jmp remem

red:

ldi k__z, 10 
 
rcall subr_delay1

ldi k__z, 50   
 
rcall subr_delay0

ldi k__z, 10  

rcall subr_delay1

ldi k__z, 50 

rcall subr_delay0

ldi k__z, 10 

rcall subr_delay1

ldi k__z, 200 
 
rcall subr_delay0
 
 
jmp remem 
  
 
subr_delay1:  ; "1" ?????� k__z ?????? ? ???????????? 
ldi s___, 1  ; 1 --> s___ 
out portb, s___  ; s___ --> pb 
ldi temp, 0
out tcnt0, temp ; 0 --> tcnt0 ????????? ??????? 
ccc1:   ; ?????? ????? 
in k___, tcnt0 ; ??????? ?????? 
cp k___, k__z ; ???????? k__ ? k__z 
brlo ccc1  ; ???? k___<k__z, ???? ? ??????
 ret   ; ????? ???????????? subr_delay1 
 

subr_delay0:  ; "0" ?????� k__z ?????? ? ???????????? 
ldi s___, 0  ; 0 --> s___ 
out portb, s___  ; s___ --> pb
ldi temp, 0  
out tcnt0, temp ; 0 --> tcnt0 
ccc0:   ; ?????? ????? 
in k___, tcnt0 ; ??????? ?????? 
cp k___, k__z ; ???????? k__ ? k__z 
brlo ccc0  ; ???? k___<k__z, ???? ? ?????? 
ret   ; ????? ???????????? subr_delay  



