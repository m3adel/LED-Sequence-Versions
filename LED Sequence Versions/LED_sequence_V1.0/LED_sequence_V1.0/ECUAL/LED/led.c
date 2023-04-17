/*
 * led.c
 *
 * Created: 4/9/2023 8:55:14 AM
 *  Author: MOHAMED ABDELSALAM
 */ 
#include "led.h"

void LED_init (uint8_t port, uint8_t pin){
	DIO_init(port,pin,OUT);
}
void LED_on (uint8_t port, uint8_t pin){
	DIO_write(port,pin,HIGH);
}
void LED_off (uint8_t port, uint8_t pin){
	DIO_write(port,pin,LOW);
}
void LED_toggle (uint8_t port, uint8_t pin){
	DIO_toggle(port,pin);
}