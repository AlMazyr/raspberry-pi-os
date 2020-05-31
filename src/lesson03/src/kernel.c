#include "printf.h"
#include "timer.h"
#include "irq.h"
#include "pl011.h"

void kernel_main(void)
{
	pl011_init();
	init_printf(0, putc);
	irq_vector_init();
	ltimer_init();
	enable_interrupt_controller();
	enable_irq();

	while (1);
}
