#include "printf.h"
#include "pl011.h"
#include "utils.h"

void hyp_main()
{
	pl011_init();
	init_printf(0, putc);
	printf("Exception level: %d \r\n", get_el());
}
