/*
 * state.h
 *
 *  Created on: Jun 2, 2024
 *      Author: Abdelrahman
 */

#ifndef STATE_H_
#define STATE_H_
#include "stdlib.h"
#include "stdio.h"

#define STATE_DEFINE_FUNC(_state_func_) void _state_func_()
#define STATE(_state_func_) _state_func_

void Get_Ultrasonic_reading(int UltrasonicReading);
void DC_motor_set_speed(int DC_motor_speed);

#endif /* STATE_H_ */
