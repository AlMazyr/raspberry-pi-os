#include "pl011.h"
#include "utils.h"

volatile int busy;

void kernel_secondary(int pid)
{
	while (busy)
		delay(10);
	busy = 1;
	pl011_send_string("Hello, from core ");
	pl011_send('0' + pid);
	pl011_send_string("\r\n");
	busy = 0;
	while(1);
}


void kernel_main(void)
{
	pl011_init();
	pl011_send_string("Hello, world!\r\n");
}
