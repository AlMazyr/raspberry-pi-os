#include "mm.h"

.section ".text.boot"

.globl _start
_start:
	mrs	x0, mpidr_el1		
	and	x0, x0,#0xFF		// Check processor id
	mov	x19, x0			// save processor id
	cbz	x0, master		// Hang for all non-primary CPU
	b	second_startup

second_startup:
	wfe
	cmp	x19, #1
	b.eq	core1
	cmp	x19, #2
	b.eq	core2
	cmp	x19, #3
	b.eq	core3
proc_hang:
	b	proc_hang
core1:
	mov	sp, STACK_START1
	mov	x0, x19
	bl	kernel_secondary
core2:
	mov	sp, STACK_START2
	mov	x0, #100
	bl	delay
	mov	x0, x19
	bl	kernel_secondary
core3:
	mov	sp, STACK_START3
	mov	x0, #10000
	bl	delay
	mov	x0, x19
	bl	kernel_secondary

master:
	adr	x0, bss_begin
	adr	x1, bss_end
	sub	x1, x1, x0
	bl 	memzero

	mov	sp, #LOW_MEMORY
	bl	kernel_main
	sev
	b 	proc_hang		// should never come here
