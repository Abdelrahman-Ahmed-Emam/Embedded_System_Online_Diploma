/*
 * CA.c
 *
 *  Created on: Jun 3, 2024
 *      Author: Abdelrahman
 */
#include "CA.h"
static int CA_threshold=50;
static int Ultrasonic_reading=0;
static int DC_motor_speed=0;
void (*CA_state_ptr)();
void Get_Ultrasonic_reading(int UltrasonicReading)
{
	Ultrasonic_reading=UltrasonicReading;
	(Ultrasonic_reading<=CA_threshold) ? (CA_state_ptr=STATE(CA_Waiting)) : (CA_state_ptr=STATE(CA_Moving));
	printf("Ultrasonic-distance=%d->CA\n",Ultrasonic_reading);
}

STATE_DEFINE_FUNC(CA_Waiting)
{
	CA_state_id=CA_waiting;
	DC_motor_speed=0;
	printf("CA_waiting speed=%d distance=%d\n",DC_motor_speed,Ultrasonic_reading);
	DC_motor_set_speed(DC_motor_speed);
}

STATE_DEFINE_FUNC(CA_Moving)
{
	CA_state_id=CA_moving;
	DC_motor_speed=30;
	printf("CA_moving speed=%d distance=%d\n",DC_motor_speed,Ultrasonic_reading);
	DC_motor_set_speed(DC_motor_speed);
}
