/*
 * registers.h
 *
 * Created: 4/6/2023 11:32:40 PM
 *  Author: MOHAMED ABDELSALAM
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "typedefs.h"
/******************************************************************************/
// Timer2 Registers
/******************************************************************************/
#define TIFR *((volatile uint8_t*)0x58)
#define TCCR2 *((volatile uint8_t*)0x45)
#define TCNT2 *((volatile uint8_t*)0x44)
/******************************************************************************/
// DIO Registers
/******************************************************************************/
//PortA Registers
#define PORTA (*((volatile uint8_t*)0x3B))
#define DDRA (*((volatile uint8_t*)0x3A))
#define PINA (*((volatile uint8_t*)0x39))
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
#endif /* REGISTERS_H_ */