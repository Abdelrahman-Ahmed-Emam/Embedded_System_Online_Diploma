/*
 * state.h
 *
 *  Created on: Jun 2, 2024
 *      Author: Abdelrahman
 */

#ifndef STATE_H_
#define STATE_H_
#include "Platforms_Type.h"

#define STATE_DEFINE_FUNC(_state_func_) void _state_func_()
#define STATE(_state_func_) _state_func_

void set_pressure_value(uint32 pressureValue);
void high_pressure_detection();
void stop_alarm();
void start_alarm();

#endif /* STATE_H_ */
