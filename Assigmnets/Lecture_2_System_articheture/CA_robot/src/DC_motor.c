#include "DC_motor.h"
static int DC_motor_speed=0;
void (*DC_motr_state_ptr)();
void DC_init()
{
	printf("DC motor being initialized\n");
	fflush(stdout);
}

void DC_motor_set_speed(int speed)
{
	DC_motor_speed=speed;
	DC_motr_state_ptr=STATE(Moving_DC_Motor);
	printf("CA->speed=%d->DC motor\n",DC_motor_speed);
}

STATE_DEFINE_FUNC(DC_Idle)
{
	printf("DC motor in idle state\n");
	DC_motor_state_id=DC_idle;
	DC_motr_state_ptr=STATE(DC_Idle);
}
STATE_DEFINE_FUNC(Moving_DC_Motor)
{
	DC_motor_state_id=Moving_DC_motor;
	DC_motr_state_ptr=STATE(DC_Idle);
	printf("DC motor moving with speed= %d\n\n\n\n",DC_motor_speed);
}
