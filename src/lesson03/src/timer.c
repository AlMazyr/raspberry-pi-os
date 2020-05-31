#include "utils.h"
#include "printf.h"
#include "peripherals/timer.h"

const unsigned int interval = 200000;
unsigned int curVal = 0;

void timer_init ( void )
{
	curVal = get32(TIMER_CLO);
	curVal += interval;
	put32(TIMER_C1, curVal);
}

void handle_timer_irq( void ) 
{
	curVal += interval;
	put32(TIMER_C1, curVal);
	put32(TIMER_CS, TIMER_CS_M1);
	printf("Timer interrupt received\n\r");
}

void ltimer_init()
{
	put32(LTIMER_IRQ_R, LTIMER_IRQ0); // interrupt routing to core0
	put32(LTIMER_CS, 15000000ul | BIT(28) | BIT(29));
}

void handle_ltimer_irq()
{
	put32(LTIMER_IRQ_CR, BIT(31));
}

