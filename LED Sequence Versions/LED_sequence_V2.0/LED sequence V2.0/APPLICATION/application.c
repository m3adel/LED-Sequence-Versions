/*
 * application.c
 *
 * Created: 4/11/2023 4:51:29 AM
 *  Author: MOHAMED ABDELSALAM
 */ 

#include "application.h"

#define number_of_states 7
uint8_t state_number = 0;


void EX_INT0_ISR (void){
	if (state_number < number_of_states){
		state_number++;
		
	}
	else{
		state_number =0;
	}
}
void APP_init(void)
{
		LED_init(LED0_PORT,LED0_PIN);
		LED_init(LED1_PORT,LED1_PIN);
		LED_init(LED2_PORT,LED2_PIN);
		LED_init(LED3_PORT,LED3_PIN);
		BUTTON_init (EX_INT0_PORT, EX_INT0_PIN);	
		EX_INT0_SET_CALLBACK (EX_INT0_ISR);
		
		EX_INT_init(INT0 , rising_edge);
		
}

void APP_start(void){	
	while(1){
		switch(state_number)
		{
			case 0:
			LED_off(LED0_PORT,LED0_PIN);
			LED_off(LED1_PORT,LED1_PIN);
			LED_off(LED2_PORT,LED2_PIN);
			LED_off(LED3_PORT,LED3_PIN);			
			break;
			case 1:
			LED_on(LED0_PORT,LED0_PIN);
			break;
			case 2:
			LED_on(LED1_PORT,LED1_PIN);
			break;
			case 3:
			LED_on(LED2_PORT,LED2_PIN);
			break;
			case 4:
			LED_on(LED3_PORT,LED3_PIN);
			break;
			case 5:
			LED_off(LED0_PORT,LED0_PIN);
			break;
			case 6:
			LED_off(LED1_PORT,LED1_PIN);
			break;
			case 7:
			LED_off(LED2_PORT,LED2_PIN);
			break;
						
		}
}

		
}
void APP_stop(void){
				LED_off(LED0_PORT,LED0_PIN);
				LED_off(LED1_PORT,LED1_PIN);
				LED_off(LED2_PORT,LED2_PIN);
				LED_off(LED3_PORT,LED3_PIN);
				EX_INT_Disable(INT0);
				CLI();
}

