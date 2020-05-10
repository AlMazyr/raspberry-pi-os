#include "mm.h"
#include "smp.h"

.section ".text.boot"

.globl _start
_start:
	mrs	x0, mpidr_el1		
	and	x0, x0,#0xFF		// Check processor id
	mov	x19, x0			// save processor id
	cbz	x0, master		// Hang for all non-primary CPU
	b	second_startup

second_startup:
//	wfe
	mrs	x19, mpidr_el1
	and	x19, x19,#0xFF		// Check processor id
	mov 	x0, SECONDARY_STACK_START
	mul 	x2, x0, x19		// calculate SP for each core
	mov 	sp, x2			// setup sp for each core
	mov	x1, #30000
	mul	x0, x1, x19		// calc delay for each core
	bl	delay
	mov	x0, x19
	bl	kernel_secondary
proc_hang:
	b	proc_hang

master:
	adr	x0, bss_begin
	adr	x1, bss_end
	sub	x1, x1, x0
	bl 	memzero

	mov	sp, #LOW_MEMORY
	bl	kernel_main
	mov 	x0, #2			// core id
	adr	x1, second_startup	// where to start
	bl	wakeup_core
	mov 	x0, #3			// core id
	bl	wakeup_core
//	sev
	b 	proc_hang		// should never come here
