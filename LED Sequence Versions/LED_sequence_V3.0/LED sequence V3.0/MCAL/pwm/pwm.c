/*
 * pwm.c
 *
 * Created: 4/6/2023 11:18:12 PM
 *  Author: MOHAMED ABDELSALAM
 */ 
#include "pwm.h"
#define PWM_F             1            //the frequency in Hz
#define PWM_PinB           3
volatile uint32_t PWM_count_ON=0;
volatile uint32_t PWM_count_OFF=0;
uint32_t select_pwm;
uint32_t PWM_Count=0;
void PWM_gen(void)
{
	PWM_Count++;
	if (PWM_Count==PWM_count_OFF)
	{
		switch(select_pwm)
		{
			case 0:
			
				PORTA &= ~(1<<LED0_PIN_);
				PORTA &= ~(1<<LED1_PIN_);
				PORTA &= ~(1<<LED2_PIN_);
				PORTA &= ~(1<<LED3_PIN_);
			break;
			case 1:
				PORTA |= (1<<LED0_PIN_);
				PORTA &= ~(1<<LED1_PIN_);
				PORTA &= ~(1<<LED2_PIN_);
				PORTA &= ~(1<<LED3_PIN_);
			break;
			case 2:
			
				PORTA |= (1<<LED0_PIN_);
				PORTA |= (1<<LED1_PIN_);
				PORTA &= ~(1<<LED2_PIN_);
				PORTA &= ~(1<<LED3_PIN_);
			break;
			case 3:
				PORTA |= (1<<LED0_PIN_);
				PORTA |= (1<<LED1_PIN_);
				PORTA |= (1<<LED2_PIN_);
				PORTA &= ~(1<<LED3_PIN_);
			break;
			case 4:
				PORTA |= (1<<LED0_PIN_);
				PORTA |= (1<<LED1_PIN_);
				PORTA |= (1<<LED2_PIN_);
				PORTA |= (1<<LED3_PIN_);
			break;
			case 5:
			PORTA &= ~(1<<LED0_PIN_);
			PORTA |= (1<<LED1_PIN_);
			PORTA |= (1<<LED2_PIN_);
			PORTA |= (1<<LED3_PIN_);
			break;
			case 6:
			PORTA &= ~(1<<LED0_PIN_);
			PORTA &= ~(1<<LED1_PIN_);
			PORTA |= (1<<LED2_PIN_);
			PORTA |= (1<<LED3_PIN_);
			break;
			case 7:
			PORTA &= ~(1<<LED0_PIN_);
			PORTA &= ~(1<<LED1_PIN_);
			PORTA &= ~(1<<LED2_PIN_);
			PORTA |= (1<<LED3_PIN_);
			break;
			
		}
	}
	else if (PWM_Count==(PWM_count_OFF+PWM_count_ON))
	{
		PORTA &= ~(1<<LED0_PIN_);
		PORTA &= ~(1<<LED1_PIN_);
		PORTA &= ~(1<<LED2_PIN_);
		PORTA &= ~(1<<LED3_PIN_);
		PWM_Count=0;
	}
	TCNT0=Intial_value_PWM;
}
void PWM_init (void){
	
	//
	DDRA |= (1<<LED0_PIN_);
	DDRA |= (1<<LED1_PIN_);
	DDRA |= (1<<LED2_PIN_);
	DDRA |= (1<<LED3_PIN_);
	//choose PWM mode
	TCCR0 &= Normal;
	TCCR0 |= Normal;
	SREG |= (1<<I_BIT);//enable global interrupt
	TIMSK |= (1<<TOIE0); //enable interrupt overflow of timer 0
	TCNT0 = Intial_value_PWM; // start counting from 6
	Timer0_Ovf_CALLBACK (PWM_gen);
}

void PWM_start (uint8_t duty_percent){
	uint32_t temp=0;
	temp=((f32)1/PWM_F)*((f32)duty_percent/100)*1000*1000;
	PWM_count_ON=temp/250;
	temp=((f32)1/PWM_F)*((f32)(100-duty_percent)/100)*1000*1000;
	PWM_count_OFF=temp/250;
	PWM_Count=0;
	TCNT0=Intial_value_PWM;
	TCCR0 |= pres_8;  //Set Pre_scaler, for ex:ck(8MHz)/1 to get,
}

void PWM_set (uint8_t duty_percent , uint8_t blinks){
	select_pwm = blinks;
	uint32_t temp=0;
	temp=((f32)1/PWM_F)*((f32)duty_percent/100)*1000*1000;
	PWM_count_ON=temp/250;
	temp=((f32)1/PWM_F)*((f32)(100-duty_percent)/100)*1000*1000;
	PWM_count_OFF=temp/250;
}
void PWM_Stop (void)
{
	//Timer Stop
	TCCR0 = no_clk;
}