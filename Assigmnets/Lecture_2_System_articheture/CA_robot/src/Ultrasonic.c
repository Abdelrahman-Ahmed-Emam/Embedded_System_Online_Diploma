/*
 * Ultrasonic.c
 *
 *  Created on: Jun 2, 2024
 *      Author: Abdelrahman
 */
#include "Ultrasonic.h"
void(*Ultrasonic_state_ptr)();
void Ultrasonic_init()
{
	printf("Initialize the Ultrasonic \n");
	fflush(stdout);
}

STATE_DEFINE_FUNC(Ultrasonic_reading)
{
	Ultrasonic_state_id=Ultrasonic_Reading;
	Ultrasonic_state_ptr=STATE(Ultrasonic_reading);
	int distance=40+(rand()%(60-40+1));
	printf("Ultrasonic reading is %d\n",distance);
	Get_Ultrasonic_reading(distance);
	Ultrasonic_state_ptr=STATE(Ultrasonic_reading);
}
