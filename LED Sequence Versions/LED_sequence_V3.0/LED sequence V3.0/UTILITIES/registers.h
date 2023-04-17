/*
 * registers.h
 *
 * Created: 4/8/2023 2:14:20 PM
 *  Author: MOHAMED ABDELSALAM
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "typedefs.h"
/******************************************************************************/
// Timer0 Registers
/******************************************************************************/
#define TCNT0   (*(volatile uint8_t*)(0x52))
#define TCCR0   (*(volatile uint8_t*)(0x53))
#define OCR0    (*(volatile uint8_t*)(0x5C))
#define TIMSK   (*(volatile uint8_t*)(0x59))
#define TOIE0 0 //overflow enable bit
#define TIFR    (*(volatile uint8_t*)(0x58))
/******************************************************************************/
// Timer2 Registers
/******************************************************************************/
#define TCCR2 *((volatile uint8_t*)0x45)
#define TCNT2 *((volatile uint8_t*)0x44)
/******************************************************************************/
// DIO Registers
/******************************************************************************/
//PortA Registers
#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA *((volatile uint8_t*)0x3A)
#define PINA *((volatile uint8_t*)0x39)
//PortB Registers
#define PORTB *((volatile uint8_t*)0x38)
#define DDRB *((volatile uint8_t*)0x37)
#define PINB *((volatile uint8_t*)0x36)
//PortC Registers
#define PORTC *((volatile uint8_t*)0x35)
#define DDRC *((volatile uint8_t*)0x34)
#define PINC *((volatile uint8_t*)0x33)
//PortD Registers
#define PORTD *((volatile uint8_t*)0x32)
#define DDRD *((volatile uint8_t*)0x31)
#define PIND *((volatile uint8_t*)0x30)
/******************************************************************************/
// External Interrupt Registers
/******************************************************************************/
#define SREG *((volatile uint8_t*)0x5F)
#define I_BIT	7
#define GIFR *((volatile uint8_t*)0x5A)
#define INTF0 6
#define INTF1 7
#define INTF2 5
#define GICR *((volatile uint8_t*)0x5B)
#define INT0 6
#define INT1		7
#define INT2		5
#define MCUCR *((volatile uint8_t*)0x55)
//sense modes for int0/1
#define falling_edge		1   
#define rising_edge 2
//Mode selecting bits
#define ISC00	0
#define ISC01	1
#define ISC10	2
#define ISC11	3
//sense modes for int2
#define ISC2	6
#define falling_edge_2	0
#define rising_edge_2	1
#define MCUCSR  (*(volatile uint8_t*)(0x54))
/******************************************************************************/
#endif /* REGISTERS_H_ */