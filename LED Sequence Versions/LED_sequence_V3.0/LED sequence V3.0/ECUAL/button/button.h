/*
 * button.h
 *
 * Created: 4/9/2023 9:10:06 AM
 *  Author: MOHAMED ABDELSALAM
 */ 

#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/dio/dio.h"
//BUTTON Pin Numbers
#define BUTTON0_PORT 'A'
#define BUTTON0_PIN 7
void BUTTON_init (uint8_t buttonport, uint8_t buttonpin);
void BUTTON_read (uint8_t buttonport, uint8_t buttonpin, uint8_t *value);
#endif /* BUTTON_H_ */