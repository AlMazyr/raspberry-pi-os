#ifndef	_PL011_H
#define	_PL011_H

#define PL011_CLOCK	48000000ul

#define PL011_BRD(br)		((PL011_CLOCK) / (16.0 * (br)))
#define PL011_BRD_115200	PL011_BRD(115200ul)
#define PL011_IBRD_115200	((unsigned int)PL011_BRD_115200)
#define PL011_FBRD_115200	((unsigned int)(((PL011_BRD_115200-PL011_IBRD_115200)*64)+0.5))

void pl011_init();
void pl011_send(char c);
char pl011_recv();
void pl011_send_string(const char *str);
void putc(void *p, char c);

#endif  /*_PL011_H */
