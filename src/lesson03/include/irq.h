#ifndef	_IRQ_H
#define	_IRQ_H

#define CORE_IRQ0	0x40000060
#define LTIMER_IRQ	BIT(11)
#define GPU_IRQ		BIT(8)


void enable_interrupt_controller( void );

void irq_vector_init( void );
void enable_irq( void );
void disable_irq( void );

#endif  /*_IRQ_H */
