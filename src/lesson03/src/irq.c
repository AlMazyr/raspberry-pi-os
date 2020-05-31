#include "utils.h"
#include "printf.h"
#include "timer.h"
#include "entry.h"
#include "peripherals/irq.h"
#include "irq.h"
#include "pl011.h"

const char *entry_error_messages[] = {
	"SYNC_INVALID_EL1t",
	"IRQ_INVALID_EL1t",		
	"FIQ_INVALID_EL1t",		
	"ERROR_INVALID_EL1T",		

	"SYNC_INVALID_EL1h",		
	"IRQ_INVALID_EL1h",		
	"FIQ_INVALID_EL1h",		
	"ERROR_INVALID_EL1h",		

	"SYNC_INVALID_EL0_64",		
	"IRQ_INVALID_EL0_64",		
	"FIQ_INVALID_EL0_64",		
	"ERROR_INVALID_EL0_64",	

	"SYNC_INVALID_EL0_32",		
	"IRQ_INVALID_EL0_32",		
	"FIQ_INVALID_EL0_32",		
	"ERROR_INVALID_EL0_32"	
};

void enable_interrupt_controller()
{
	//put32(ENABLE_IRQS_1, SYSTEM_TIMER_IRQ_1); // enable System Timer irq
	put32(ENABLE_IRQS_2, GPU_IRQ_2_UART); // enable PL011 irq
}

void show_invalid_entry_message(int type, unsigned long esr, unsigned long address)
{
	printf("%s, ESR: %x, address: %x\r\n", entry_error_messages[type], esr, address);
}

static void handle_gpu_irq()
{
	unsigned int irq = get32(IRQ_BASIC_PENDING);

	if (irq & GPU_IRQ_PEND_UART)
		pl011_irq();
	//TODO: other gpu interrupts
}

void handle_irq(void)
{
	unsigned int irq = get32(CORE_IRQ0);

	if (irq & LTIMER_IRQ)
		handle_ltimer_irq();
	if (irq & GPU_IRQ)
		handle_gpu_irq();
	// TODO: other core interrupts
}

