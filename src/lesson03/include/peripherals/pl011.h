#ifndef	_P_PL011_H
#define	_P_PL011_H

#include "peripherals/base.h"

#define PL011_BASE	(PBASE+0x201000)

#define PL011_DR	(PL011_BASE+0)
#define PL011_RSRECR	(PL011_BASE+0x4)
#define PL011_FR	(PL011_BASE+0x18)
#define PL011_IBRD	(PL011_BASE+0x24)
#define PL011_FBRD	(PL011_BASE+0x28)
#define PL011_LCRH	(PL011_BASE+0x2c)
#define PL011_CR	(PL011_BASE+0x30)
#define PL011_IMSC	(PL011_BASE+0x38)
//TODO:

#endif  /*_P_PL011_H */
