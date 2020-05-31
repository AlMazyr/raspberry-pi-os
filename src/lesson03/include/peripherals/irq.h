#ifndef	_P_IRQ_H
#define	_P_IRQ_H

#include "peripherals/base.h"

#define IRQ_BASIC_PENDING	(PBASE+0x0000B200)
#define IRQ_PENDING_1		(PBASE+0x0000B204)
#define IRQ_PENDING_2		(PBASE+0x0000B208)
#define FIQ_CONTROL		(PBASE+0x0000B20C)
#define ENABLE_IRQS_1		(PBASE+0x0000B210)
#define ENABLE_IRQS_2		(PBASE+0x0000B214)
#define ENABLE_BASIC_IRQS	(PBASE+0x0000B218)
#define DISABLE_IRQS_1		(PBASE+0x0000B21C)
#define DISABLE_IRQS_2		(PBASE+0x0000B220)
#define DISABLE_BASIC_IRQS	(PBASE+0x0000B224)

// GPU Base Pending register
#define GPU_IRQ_PEND_1		BIT(9)
#define GPU_IRQ_PEND_2		BIT(8)
#define GPU_IRQ_PEND_UART	BIT(19)

// GPU Pending 1 register
#define SYSTEM_TIMER_IRQ_0	(1 << 0)
#define SYSTEM_TIMER_IRQ_1	(1 << 1)
#define SYSTEM_TIMER_IRQ_2	(1 << 2)
#define SYSTEM_TIMER_IRQ_3	(1 << 3)

// GPU IRQ Enable 2 register
#define GPU_IRQ_2_UART		BIT(57%32)

#endif  /*_P_IRQ_H */
