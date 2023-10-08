/*	Learn-in-depth Lab2 startup file
	Eng.Abdelrahman	*/

.section .vectors
.word stack_top
.word _reset
.word NMI
.word Hard_Fault
.word MM_Fault
.word Bus_Fault
.word Usage_Fault
.word RESERVED
.word RESERVED
.word RESERVED
.word RESERVED
.word SV_call
.word Debug_Reserved
.word RESERVED
.word PendSV
.word SysTick
.word IRQ0
.word IRQ1
.word IRQ1


.section .text
_reset:
	ldr r0, =_S_Data
    ldr r1, = _E_Data
 	ldr r2, =_D_Size
 	movs r3, #0
 	b DataInit

CopyData:
 	ldr r4, [r2, r3]
 	str r4, [r0, r3]
  	adds r3, r3, #4

DataInit:
 	adds r4, r0, r3
 	cmp r4, r1
 	bcc CopyData
  	ldr r2, =_S_bss
  	ldr r4, =_E_bss
  	movs r3, #0
  	b LoopFillZero
FillZero:
 	str  r3, [r2]
  	adds r2, r2, #4

LoopFillZero:
 	cmp r2, r4
  	bcc FillZero
 	bl main

.thumb_func

.section .interrupts-of-vector-table
.weak NMI
.thumb_set NMI,_reset

.weak Hard_Fault
.thumb_set Hard_Fault,_reset

.weak MM_Fault
.thumb_set MM_Fault,_reset

.weak Bus_Fault
.thumb_set Bus_Fault,_reset

.weak Usage_Fault
.thumb_set Usage_Fault,_reset

.weak SV_call
.thumb_set SV_call,_reset

.weak PendSV
.thumb_set PendSV,_reset

.weak SysTick
.thumb_set SysTick,_reset

.weak IRQ0
.thumb_set IRQ0,_reset

.weak IRQ1
.thumb_set IRQ1,_reset

.weak IRQ2
.thumb_set IRQ2,_reset


.section .not_used
RESERVED:
Debug_Reserved:

