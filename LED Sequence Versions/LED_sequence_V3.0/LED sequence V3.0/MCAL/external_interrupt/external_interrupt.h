/*
 * external_interrupt.h
 *
 * Created: 4/14/2023 12:02:27 PM
 *  Author: MOHAMED ABDELSALAM
 */ 


#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_
#include "../../UTILITIES/registers.h"
#include "../../SERVICES/interrupt_serivce.h"
/****************************/

/************************************************************************/
/* APIs                                                                 */
/************************************************************************/
void SIE(void);
void CLI(void);
void INT_SENSE(uint8_t inerrupt_number,uint8_t sense);
void EX_INT_Enable(uint8_t inerrupt_number);
void EX_INT_Disable(uint8_t inerrupt_number);
void EX_INT0_SET_CALLBACK (void (*copyFuncptr) (void));
void EX_INT1_SET_CALLBACK (void (*copyFuncptr) (void));
void EX_INT_init(uint8_t interrupt , uint8_t sense);
void EX_INT2_SET_CALLBACK (void (*copyFuncptr) (void));
void Timer0_Comp_CALLBACK (void (*copyFuncptr) (void));
void Timer0_Ovf_CALLBACK (void (*copyFuncptr) (void));
/************************************************************************/
/*                       interrupt pins & ports                         */
/************************************************************************/
#define EX_INT0_PORT 'D'
#define EX_INT0_PIN   2
#define EX_INT1_PORT 'D'
#define EX_INT1_PIN   3
#define EX_INT2_PORT 'B'
#define EX_INT2_PIN   2
#endif /* EXTERNAL_INTERRUPT_H_ */