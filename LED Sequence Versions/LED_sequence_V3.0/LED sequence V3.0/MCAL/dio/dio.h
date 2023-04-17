/*
 * dio.h
 *
 * Created: 4/8/2023 11:45:56 PM
 *  Author: MOHAMED ABDELSALAM
 */ 


#ifndef DIO_H_
#define DIO_H_
/*****************************************************************************/
#include "../../UTILITIES/registers.h"
/*****************************************************************************/
//port numbers
#define port_A 'A'
#define port_B 'B'
#define port_C 'C'
#define port_D 'D'
/*****************************************************************************/
//port directions
#define IN 0
#define OUT 1
/*****************************************************************************/
//Output levels
#define LOW 0
#define HIGH 1
/*****************************************************************************/
//Digital input/output APIs:
/*****************************************************************************/
void DIO_init (uint8_t portNumber,uint8_t pinNumber,uint8_t direction);
void DIO_write (uint8_t portNumber,uint8_t pinNumber,uint8_t value);
void DIO_read (uint8_t portNumber,uint8_t pinNumber,uint8_t *data);
void DIO_toggle (uint8_t portNumber,uint8_t pinNumber);
/*****************************************************************************/
#endif /* DIO_H_ */