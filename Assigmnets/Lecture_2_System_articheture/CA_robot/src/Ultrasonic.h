/*
 * Ultrasonic.h
 *
 *  Created on: Jun 2, 2024
 *      Author: Abdelrahman
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include "state.h"

enum {
	Ultrasonic_Reading
}Ultrasonic_state_id;
void Ultrasonic_init();
STATE_DEFINE_FUNC(Ultrasonic_reading);

extern void(*Ultrasonic_state_ptr)();
#endif /* ULTRASONIC_H_ */
