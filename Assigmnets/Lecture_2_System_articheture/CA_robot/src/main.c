/*
 ============================================================================
 Name        : CA_robot.c
 Author      : Abdelrahman
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Ultrasonic.h"
#include "state.h"
#include "CA.h"
#include "DC_motor.h"
void setup()
{
	DC_init();
	Ultrasonic_init();
	CA_state_ptr=STATE(CA_Waiting);
	DC_motr_state_ptr=STATE(DC_Idle);
	Ultrasonic_state_ptr=STATE(Ultrasonic_reading);
}
int main(void) {
	setup();
	while(1)
	{
		Ultrasonic_state_ptr();
		CA_state_ptr();
		DC_motr_state_ptr();
	}
	return 0;
}
