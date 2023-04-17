/*
 * delay.c
 *
 * Created: 4/16/2023 8:16:02 PM
 *  Author: lenovo
 */ 
#include "delay.h"
void Delay(uint32_t milliseconds)
{
	TIMER_init (normal,ticks_250);
	TIMER_start (pres_8);
	uint32_t i;
	uint8_t counter;
	
	for(i=0;i< milliseconds ;i++){
		
		// N = (1000us)/(250u);  //= 4 without approximation
		//for one millisecond delay iterate 4 times of timer2 overflow
		counter = 0;
		while(counter<4){
			
			while((TIFR & clear) == 0);
			TIMER_set(ticks_250);
			TIFR |= clear;
			counter++;
		}
		

	}
	TIMER_Stop ();
}