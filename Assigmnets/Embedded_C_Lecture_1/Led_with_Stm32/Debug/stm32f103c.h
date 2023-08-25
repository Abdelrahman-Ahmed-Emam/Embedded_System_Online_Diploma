/*
 * stm32f103c.h
 *
 *  Created on: Aug 22, 2023
 *      Author: HP
 */

#ifndef STM32F103C_H_
#define STM32F103C_H_
#include "Platforms_Types.h"

#define RCC 				0x40021000
#define GPIO_Port_A 		0x40010800
#define APB2ENR 			0x18
#define CRH 				0x04
#define ODR 				0x0C
#define RCC_APB2ENR 		*(vuint32_t* )(RCC + APB2ENR)
#define GPIO_Port_A_CRH 	*(vuint32_t*)(GPIO_Port_A + CRH)
#define GPIO_Port_A_ODR 	*(vuint32_t*)(GPIO_Port_A + ODR)


typedef union
{
	vuint32_t All_Pins;
	struct
	{
		vuint32_t pin0:1;
		vuint32_t pin1:1;
		vuint32_t pin2:1;
		vuint32_t pin3:1;
		vuint32_t pin4:1;
		vuint32_t pin5:1;
		vuint32_t pin6:1;
		vuint32_t pin7:1;
		vuint32_t pin8:1;
		vuint32_t pin9:1;
		vuint32_t pin10:1;
		vuint32_t pin11:1;
		vuint32_t pin12:1;
		vuint32_t pin13:1;
		vuint32_t pin14:1;
		vuint32_t pin15:1;
		vuint32_t pin16:1;
		vuint32_t pin17:1;
		vuint32_t pin18:1;
		vuint32_t pin19:1;
		vuint32_t pin20:1;
		vuint32_t pin21:1;
		vuint32_t pin22:1;
		vuint32_t pin23:1;
		vuint32_t pin24:1;
		vuint32_t pin25:1;
		vuint32_t pin26:1;
		vuint32_t pin27:1;
		vuint32_t pin28:1;
		vuint32_t pin29:1;
		vuint32_t pin30:1;
		vuint32_t pin31:1;


	}pins;
}Registers ;

#endif /* STM32F103C_H_ */
