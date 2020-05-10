.globl wakeup_core
wakeup_core:
	mov x2, 0xd8
	str x1, [x2, x0, LSL #3]
	sev
	ret
