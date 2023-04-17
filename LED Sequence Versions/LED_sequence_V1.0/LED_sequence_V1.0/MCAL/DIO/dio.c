/*
 * dio.c
 *
 * Created: 4/8/2023 11:45:35 PM
 *  Author: MOHAMED ABDELSALAM
 */ 
#include "dio.h"
void DIO_init (uint8_t portNumber,uint8_t pinNumber,uint8_t direction){
	switch(portNumber)
	{
		case 'A':
		if (direction == OUT)
		{
			DDRA |= (1<<pinNumber);    //set
		}
		else if (direction == IN)
		{
			DDRA &= ~(1<<pinNumber);   //clear
		}		
		break;
		case 'B':
		if (direction == OUT)
		{
			DDRB |= (1<<pinNumber);
		}
		else if (direction == IN)
		{
			DDRB &= ~(1<<pinNumber);
		}
		break;
		case 'C':
			if (direction == OUT)
			{
				DDRC |= (1<<pinNumber);
			}
			else if (direction == IN)
			{
				DDRC &= ~(1<<pinNumber);
			}
		break;				
		case 'D':
			if (direction == OUT)
			{
				DDRD |= (1<<pinNumber);
			}
			else if (direction == IN)
			{
				DDRD &= ~(1<<pinNumber);
			}
		break;		
		}
	
}
void DIO_write (uint8_t portNumber,uint8_t pinNumber,uint8_t value){
	switch(portNumber)
	{
		case 'A':
			if (value == HIGH)
			{
				PORTA |= (1<<pinNumber);
			}
			else if (value == LOW)
			{
				PORTA &= ~(1<<pinNumber);
			}
		break;
		case 'B':
			if (value == HIGH)
			{
				PORTB |= (1<<pinNumber);
			}
			else if (value == LOW)
			{
				PORTB &= ~(1<<pinNumber);
			}
		break;
		case 'C':
			if (value == HIGH)
			{
				PORTC |= (1<<pinNumber);
			}
			else if (value == LOW)
			{
				PORTC &= ~(1<<pinNumber);
			}
		break;
		case 'D':
			if (value == HIGH)
			{
				PORTD |= (1<<pinNumber);
			}
			else if (value == LOW)
			{
				PORTD &= ~(1<<pinNumber);
			}
		break;
	}	
}
void DIO_read (uint8_t portNumber,uint8_t pinNumber,uint8_t *data){
	
		switch(portNumber)
		{
			case 'A':
			
				*data = ((PINA &(1<<pinNumber))>>pinNumber);
				
			break;
			case 'B':
				*data = ((PINB &(1<<pinNumber))>>pinNumber);
			break;
			case 'C':
				*data = ((PINC &(1<<pinNumber))>>pinNumber);
			break;
			case 'D':
				*data = ((PIND &(1<<pinNumber))>>pinNumber);
			break;
		}
}
void DIO_toggle (uint8_t portNumber,uint8_t pinNumber){
			switch(portNumber)
			{
				case 'A':
				PORTA ^= (1<<pinNumber);
				break;
				case 'B':
				PORTB ^= (1<<pinNumber);
				break;
				case 'C':
				PORTC ^= (1<<pinNumber);
				break;
				case 'D':
				PORTD ^= (1<<pinNumber);
				break;
			}
}