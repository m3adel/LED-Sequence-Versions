/*
 * external_interrupt.c
 *
 * Created: 4/14/2023 12:02:42 PM
 *  Author: MOHAMED ABDELSALAM
 */ 
#include "external_interrupt.h"
/************************************************************************/
/*                                                                      */
/************************************************************************/


//Enable Global Interrupt by setting bit 7 in status register (1)
void SIE(void)
{
	SREG |= (1<<I_BIT);
}

//Disable Global Interrupt by setting bit 7 in status register   (2)
void CLI(void)
{
	SREG &= ~(1<<I_BIT);
}

//Choose Interrupt Sense : Level (LOW/HIGH), (FALLING/RISING) Edges    (3)
void INT_SENSE(uint8_t inerrupt_number,uint8_t sense)
{
	switch (inerrupt_number)
	{
		case INT0:
		if(sense == rising_edge){
			MCUCR |= (1<<ISC01); //Rising edge mode
			MCUCR |= (1<<ISC00);
		}
		else if(sense == falling_edge){
			MCUCR |= (1<<ISC01); //Falling edge mode
			MCUCR &= ~(1<<ISC00);
		}
		break;
		case INT1:
			if(sense == rising_edge){
				MCUCR |= (1<<ISC11); //Rising edge mode
				MCUCR |= (1<<ISC10);
			}
			else if(sense == falling_edge){
				MCUCR |= (1<<ISC11); //Falling edge mode
				MCUCR &= ~(1<<ISC10);
		
			}
		break;
		case INT2:
		if(sense == rising_edge_2){
			MCUCSR |= (1<<ISC2); //Rising edge mode
		}
		else if(sense == falling_edge_2){
			MCUCSR &= ~(1<<ISC10);	 //Falling edge mode
		}
		break;
	}
}

//Enable External Interrupts int0/1/2                                      (4)
void EX_INT_Enable(uint8_t inerrupt_number)
{
	if (inerrupt_number == INT0){
		GICR |= (1<<INT0);
		GIFR |= (1<<INTF0);
	}
	else if (inerrupt_number == INT1){
		GICR |= (1<<INT1);
	}
	else if (inerrupt_number == INT2){
		GICR |= (1<<INT2);
	}
}
//Disable External Interrupts int0/1/2
void EX_INT_Disable(uint8_t inerrupt_number)
{
	CLI();
	if (inerrupt_number == INT0){
		GICR &= ~(1<<INT0);
	}
	else if (inerrupt_number == INT1){
		GICR &= ~(1<<INT1);
	}
	else if (inerrupt_number == INT2){
		GICR &= ~(1<<INT2);
	}
}
void EX_INT_init(uint8_t interrupt , uint8_t sense)
	{

			SIE();     //Enable Global Interrupt by setting bit 7 in status register
			INT_SENSE(interrupt,sense);
			EX_INT_Enable(interrupt);
		
	}
	static void (*Callbackptr0) (void) = 0;
	static void (*Callbackptr1) (void) = 0;
	static void (*Callbackptr2) (void) = 0;
	static void (*Callbackptr9) (void) = 0;
	static void (*Callbackptr10) (void) = 0;
	void EX_INT0_SET_CALLBACK (void (*copyFuncptr) (void)){
		Callbackptr0 = copyFuncptr;
	}
	void EX_INT1_SET_CALLBACK (void (*copyFuncptr) (void)){
		Callbackptr1 = copyFuncptr;
	}
	void EX_INT2_SET_CALLBACK (void (*copyFuncptr) (void)){
		Callbackptr2 = copyFuncptr;
	}	void Timer0_Comp_CALLBACK (void (*copyFuncptr) (void)){
		Callbackptr9 = copyFuncptr;
	}	void Timer0_Ovf_CALLBACK (void (*copyFuncptr) (void)){
		Callbackptr10 = copyFuncptr;
	}
	ISR (EXT_INT_0){
		if(Callbackptr0 == 0){
				
		}
		else{
			Callbackptr0();
		}
	}
	ISR (EXT_INT_1){
		if(Callbackptr1 == 0){
				
		}
		else{
			Callbackptr1();
		}
	}
	ISR (EXT_INT_2){
		if(Callbackptr2 == 0){
			
		}
		else{
			Callbackptr2();
		}
	}
	ISR (TIMER0_COMP){
		if(Callbackptr9 == 0){
			
		}
		else{
			Callbackptr9();
		}
	}
	ISR (TIMER0_OVF){
		if(Callbackptr10 == 0){
		}
		else{
			Callbackptr10();
		}
	}
