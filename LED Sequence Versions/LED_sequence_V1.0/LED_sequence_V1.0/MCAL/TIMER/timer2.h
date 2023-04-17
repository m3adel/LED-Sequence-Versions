/*
 * timer.h
 *
 * Created: 4/6/2023 11:16:46 PM
 *  Author: MOHAMED ABDELSALAM
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "../../UTILITIES/registers.h"

#define normal 0xB7
#define no_clk 0x00
#define zero_intial 0x00
#define Intial_value 0x46  //25
#define ticks_214 0x2A  //2B
#define ticks_250 0x07  
#define pres_1 0x01
#define pres_8 0x02
#define pres_64 0x03
#define pres_256 0x04
#define pres_1024 0x05
#define clear 0x40
void TIMER_init (uint8_t Mode,uint8_t intial_value);
void TIMER_start (uint8_t prescaler_value);
void TIMER_set(uint8_t intial_value);
void TIMER_getStatus(uint8_t *value);
void TIMER_Stop (void);
#endif /* TIMER_H_ */