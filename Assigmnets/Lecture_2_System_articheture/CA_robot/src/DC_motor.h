/*
 * DC_motor.h
 *
 *  Created on: Jun 2, 2024
 *      Author: Abdelrahman
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "state.h"
enum
{
	DC_idle,
	Moving_DC_motor
}DC_motor_state_id;

void DC_init();
STATE_DEFINE_FUNC(DC_Idle);
STATE_DEFINE_FUNC(Moving_DC_Motor);
extern void (*DC_motr_state_ptr)();

#endif /* DC_MOTOR_H_ */
