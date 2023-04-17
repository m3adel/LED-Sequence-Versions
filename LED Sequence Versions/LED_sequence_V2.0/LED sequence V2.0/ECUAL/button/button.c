/*
 * button.c
 *
 * Created: 4/9/2023 9:10:35 AM
 *  Author: MOHAMED ABDELSALAM
 */ 
#include "button.h"
void BUTTON_init (uint8_t buttonport, uint8_t buttonpin){
	DIO_init(buttonport,buttonpin,IN);
}
void BUTTON_read (uint8_t buttonport, uint8_t buttonpin, uint8_t *value){
	DIO_read(buttonport,buttonpin,value);
}