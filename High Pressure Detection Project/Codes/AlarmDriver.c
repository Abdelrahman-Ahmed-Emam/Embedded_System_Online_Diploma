/*
 * AlarmDriver.c
 *
 *  Created on: Jul 19, 2024
 *      Author: abdel
 */

#include "AlarmDriver.h"
void(*Alarm_Driver_State)();
STATE_DEFINE_FUNC(alarm_init)
{
	//Alarm initialization
	AlarmDriverStateID=init;
	Alarm_Driver_State=STATE(alarm_init);
}
STATE_DEFINE_FUNC(alarm_on)
{

	AlarmDriverStateID=alarmON;
	Set_Alarm_actuator(ON);
	AlarmDriverStateID=waiting;
}
STATE_DEFINE_FUNC(alarm_off)
{

	AlarmDriverStateID=alarmOFF;
	Set_Alarm_actuator(OFF);
	AlarmDriverStateID=waiting;
}
void stop_alarm()
{
	Alarm_Driver_State=STATE(alarm_off);
	Alarm_Driver_State();
}

void start_alarm()
{
	Alarm_Driver_State=STATE(alarm_on);
	Alarm_Driver_State();
}
