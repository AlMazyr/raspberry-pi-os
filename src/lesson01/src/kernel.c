#include "pl011.h"

void kernel_main(void)
{
	pl011_init();
	pl011_send_string("Hello, world!\r\n");

	while (1) {
		pl011_send(pl011_recv());
	}
}
