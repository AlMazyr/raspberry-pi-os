#ifndef	_BOOT_H
#define	_BOOT_H

#define BIT(bit)			(1 << bit)
#define BITSET(var, bit)		var |= (BIT(bit))
#define BITMASKSET(var, mask, bit)	var |= ((mask) << (bit))
#define BITCLEAR(var, bit)		var &= ~(BIT(bit))
#define BITMASKCLEAR(var, mask, bit)	var &= ~((mask) << (bit))

extern void delay ( unsigned long);
extern void put32 ( unsigned long, unsigned int );
extern unsigned int get32 ( unsigned long );
extern int get_el ( void );

#endif  /*_BOOT_H */
