#ifndef	_TIMER_H
#define	_TIMER_H

void timer_init ( void );
void ltimer_init ( void );
void handle_timer_irq ( void );
void handle_ltimer_irq ( void );

#endif  /*_TIMER_H */
