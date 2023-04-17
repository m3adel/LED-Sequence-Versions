/*
 * application.c
 *
 * Created: 4/11/2023 4:51:29 AM
 *  Author: MOHAMED ABDELSALAM
 */ 


#include "application.h"

#define number_of_states 7
#define number_of_blink_states 4
uint8_t state_number = 0;
uint8_t blink_state = 0;

uint16_t blink_states[5] = {10,20,30,50,80};

void EX_INT0_ISR (void){
	if (state_number < number_of_states){
		state_number++;
		
	}
	else{
		state_number =0;
	}

}
void EX_INT1_ISR (void){
	if (state_number < number_of_blink_states){
		blink_state++;
			
	}
	else{
		blink_state =0;
	}
	
}
void APP_init(void)
{		
		BUTTON_init (EX_INT0_PORT, EX_INT0_PIN);
		BUTTON_init (EX_INT1_PORT, EX_INT1_PIN);	
		EX_INT_init(INT0 , rising_edge);
		EX_INT_init(INT1 , rising_edge);
		EX_INT0_SET_CALLBACK (EX_INT0_ISR);
		EX_INT1_SET_CALLBACK (EX_INT1_ISR);
		PWM_init ();
		
}

void APP_start(void){
	PWM_start(blink_states[blink_state]);	
	while(1){
		PWM_set ((blink_states[blink_state]) , state_number);
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

