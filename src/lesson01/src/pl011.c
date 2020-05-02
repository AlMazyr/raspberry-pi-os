#include "utils.h"
#include "pl011.h"
#include "peripherals/pl011.h"
#include "peripherals/gpio.h"

void pl011_init()
{
	unsigned int selector;

	selector = get32(GPFSEL1);
	BITMASKCLEAR(selector, 7, 12);		// clean gpio14
	BITMASKCLEAR(selector, 7, 15);		// clean gpio15
	BITMASKSET(selector, 4, 12);		// set alt0 for gpio14
	BITMASKSET(selector, 4, 15);		// set alt0 for gpio15
	put32(GPFSEL1,selector);

	put32(GPPUD,0);
	delay(150);
	put32(GPPUDCLK0, BIT(14)|BIT(15));
	delay(150);
	put32(GPPUDCLK0,0);

	put32(PL011_CR, 0);			// disable
	put32(PL011_IBRD, PL011_IBRD_115200); 	// setup br 115200
	put32(PL011_FBRD, PL011_FBRD_115200);
	put32(PL011_LCRH, (3<<5)|BIT(4)); 	// set 8-bit word, enable fifo
	put32(PL011_CR, BIT(0)|BIT(8)|BIT(9)); 	//enable tx,rx
}

void pl011_send(char c)
{
	while(1) {
		if (!(get32(PL011_FR) & BIT(5)))
			break;
	}
	put32(PL011_DR, c);
}


char pl011_recv()
{
	while(1) {
		if (!(get32(PL011_FR) & BIT(4)))
			break;
	}
	return get32(PL011_DR) & 0xff;
}

void pl011_send_string(const char *str)
{
	for (int i = 0; str[i] != '\0'; i ++) {
		pl011_send((char)str[i]);
	}
}
