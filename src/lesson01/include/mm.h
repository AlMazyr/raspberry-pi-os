#ifndef	_MM_H
#define	_MM_H

#define PAGE_SHIFT	 		12
#define TABLE_SHIFT 			9
#define SECTION_SHIFT			(PAGE_SHIFT + TABLE_SHIFT)

#define PAGE_SIZE   			(1 << PAGE_SHIFT)	
#define SECTION_SIZE			(1 << SECTION_SHIFT)	

#define LOW_MEMORY              	(2 * SECTION_SIZE)

#define STACK_START1			(1 << 20)
#define STACK_START2			(1 << 20)*2
#define STACK_START3			(1 << 20)*3

#ifndef __ASSEMBLER__

void memzero(unsigned long src, unsigned long n);

#endif

#endif  /*_MM_H */
