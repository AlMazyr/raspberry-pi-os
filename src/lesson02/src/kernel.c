#include "printf.h"
#include "utils.h"
#include "pl011.h"

void kernel_main(void)
{
	printf("Exception level: %d \r\n", get_el());
	while (1) {
		pl011_send(pl011_recv());
	}
}
