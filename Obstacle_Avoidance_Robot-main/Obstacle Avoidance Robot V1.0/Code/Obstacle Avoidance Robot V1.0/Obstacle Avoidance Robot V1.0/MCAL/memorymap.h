﻿

#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_


#include "../SERVICES/std_types.h"

/********************************************DIO MAPING************************	********/
#define DDRA (*(volatile uint8_t*)0x3A)
#define DDRB (*(volatile  uint8_t*)0x37)
#define DDRC (*(volatile uint8_t*)0x34)
#define DDRD (*(volatile uint8_t*)0x31)


#define PINA (*(volatile uint8_t*)0x39)
#define PINB (*(volatile uint8_t*)0x36)
#define PINC (*(volatile uint8_t*)0x33)
#define PIND (*(volatile uint8_t*)0x30)


#define PORTA (*(volatile uint8_t*)0x3B)
#define PORTB (*(volatile uint8_t*)0x38)
#define PORTC (*(volatile uint8_t*)0x35)
#define PORTD (*(volatile uint8_t*)0x32)

/******************************EXT INTERRUPT MAPPING**************************************/

#define MCUCSR  (*(volatile uint8_t*)0X54)
#define MCUCR  (*(volatile uint8_t*)0X55)
#define GICR  (*(volatile uint8_t*)0X5B)
/*************interrupt registers pin macro*/
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define ISC2  6
#define INT0 6
#define INT1 7
#define INT2 5
/****data sheet attributes to enable context switching and to enable global interrupt*/
#define INT0_vect	 __vector_1
#define INT1_vect	 __vector_2
#define INT2_vect	 __vector_3
#define TIMER2_OVF	 __vector_5

#define sei() __asm__ __volatile__("sei" ::: "memory")
#define cli() __asm__ __volatile__("cli" ::: "memory")

#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)



/*****************************************TIMER MAPING*************************************/
/***************************** TIMER_0 ******************************/
#define TCNT0   (*(volatile uint8_t*)0x52)
#define TCCR0   (*(volatile uint8_t*)0x53)
#define TIMSK   (*(volatile uint8_t*)0x59)
#define GIFR    (*(volatile uint8_t*)0x5A)
#define TIFR    (*(volatile uint8_t*)0x58)
#define OCR0    (*(volatile uint8_t*)0x5C)
/**TCCR0**/
#define CS00  0
#define CS01  1
#define CS02  2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0  7
/*************/

/***TIMSK**/
#define TOIE0 0
#define OCIE0 1
/**************/

/**GIFR**/


/*********/

/**TIFR**/
#define TOV0 0
#define OCF0 1
/**************/

/***************************** TIMER_1*******************************/
/* TCCR1A */
#define WGM11   1
#define WGM10   0

/* TCCR1B */
#define ICNC1   7
#define ICES1   6
/* bit 5 reserved */
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

#define TCNT1     (*(volatile unsigned short*)0x4C)
#define TCNT1L    (*(volatile unsigned char*)0x4C)
#define TCNT1H    (*(volatile unsigned char*)0x4D)

#define OCR1A     (*(volatile unsigned short*)0x4A)
#define OCR1AL    (*(volatile unsigned char*)0x4A)
#define OCR1AH    (*(volatile unsigned char*)0x4B)

#define TCCR1B    (*(volatile unsigned char*)0x4E)
#define TCCR1A    (*(volatile unsigned char*)0x4F)

/* TIMSK */
#define TOIE1   2

/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect			__vector_9


/***************************** TIMER_2 ******************************/
#define TCCR2   (*(volatile uint8_t*)0x45)
#define TCNT2   (*(volatile uint8_t*)0x44)


/**TCCR2**/
#define CS20	0
#define CS21	1
#define CS22	2
#define WGM21	3
#define COM20	4
#define COM21	5
#define WGM20	6
#define FOC2	7

/**TIFR**/
#define TOV2 6

/***** TIMSK***/
#define TOIE2 6
/****************************************ADC MAPING***********************************************/
#define ADMUX  (*(volatile uint8_t*)0x27)
#define ADCSRA (*(volatile  uint8_t*)0x26)
#define ADCH   (*(volatile uint8_t*)0x25)
#define ADCL   (*(volatile uint8_t*)0x24)
#define ADC   (*(volatile Uint16_t*)0x24)       /*to read instead of using ADCH & ADCL*/

/*ADCMUX*/
#define REFS1	7
#define REFS0	6
#define ADLAR	5
#define MUX4	4
#define MUX3	3
#define MUX2	2
#define MUX1	1
#define MUX0	0

/*ADCSRA*/
#define ADEN	7
#define ADSC	6
#define ADATE	5
#define ADIF	4
#define ADIE	3
#define ADPS2	2
#define ADPS1	1
#define ADPS0	0

/****************************************UART MAPING***********************************************/
#define UDR		(*(volatile uint8_t*)0x2C)
#define UCSRA   (*(volatile  uint8_t*)0x2B)
#define UCSRB   (*(volatile uint8_t*)0x2A)
#define UCSRC   (*(volatile uint8_t*)0x40)
#define UBRRL   (*(volatile uint8_t*)0x29)

/*UCSRA*/
#define RXC	7
#define TXC	6
#define UDRE	5
#define FE		4
#define DOR	3
#define PE		2
#define U2X	1
#define MPCM	0

/*UCSRB*/
#define RXCIE	7
#define TXCIE	6
#define UDRIE	5
#define RXEN	4
#define TXEN	3
#define UCSZ2	2
#define RXB8	1
#define TXB8	0

/*UCSRC*/
#define URSEL	7
#define UMSEL	6
#define UPM1	5
#define UPM0	4
#define USBS	3
#define UCSZ1	2
#define UCSZ0	1
#define UCPOL	0



#endif /* MEMORYMAP_H_ */