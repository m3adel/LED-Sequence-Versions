/*
 * LED_sequence_V1.0.c
 *
 * Created: 4/11/2023 4:19:24 AM
 * Author : MOHAMED ABDELSALAM
 */ 

#include "APPLIICATION/application.h"


int main(void)
{
	
	APP_init();
	
    /* Replace with your application code */
    while (1) 
    {
		APP_start();
    }
}






/*
#include "MCAL/DIO/dio.h"
uint8_t x;

//while
		DIO_read('A',7,&x);
		if (x==1)
		{
			DIO_write('A',7,HIGH);
		}
		else
		{
			DIO_write('A',7,LOW);
		}
		*/