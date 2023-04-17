/*
 * IncFile1.h
 *
 * Created: 4/11/2023 4:50:46 AM
 *  Author: MOHAMED ABDELSALAM
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#include "../ECUAL/button/button.h"
#include "../ECUAL/led/led.h"
#include "../MCAL/external_interrupt/external_interrupt.h"
#define EX_INT0_PORT 'D'
#define EX_INT0_PIN 2
void APP_init(void);
void APP_start(void);
void APP_stop(void);
void EX_INT0_ISR(void);
#endif /* INCFILE1_H_ */