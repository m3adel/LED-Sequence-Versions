/*
 * led.h
 *
 * Created: 4/9/2023 8:54:47 AM
 *  Author: MOHAMED ABDELSALAM
 */ 


#ifndef LED_H_
#define LED_H_
/*****************************************************************************/
#include "../../MCAL/dio/dio.h"
/*****************************************************************************/
//LED MACROS
/*****************************************************************************/
//LED Port Numbers
#define LED0_PORT 'A'
#define LED1_PORT 'A'
#define LED2_PORT 'A'
#define LED3_PORT 'A'
//LED Pin Numbers
#define LED0_PIN 0
#define LED1_PIN 1
#define LED2_PIN 2
#define LED3_PIN 3
//LED OUTPUTS
#define ON 1
#define OFF 0
/*****************************************************************************/
//LED APIs:
/*****************************************************************************/
void LED_init (uint8_t port, uint8_t pin);
void LED_on (uint8_t port, uint8_t pin);
void LED_off (uint8_t port, uint8_t pin);
void LED_toggle (uint8_t port, uint8_t pin);
/*****************************************************************************/



#endif /* LED_H_ */