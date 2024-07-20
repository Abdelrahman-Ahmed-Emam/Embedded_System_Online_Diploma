/*
 * AlarmMonitor.c
 *
 *  Created on: Jul 19, 2024
 *      Author: abdel
 */
#include "AlarmMonitor.h"
void(*Alarm_Monitor_State)();

STATE_DEFINE_FUNC(alarm_ON)
{
	AlarmMonitorStateID=alarmon;
	start_alarm();
	Delay(SIXETY_SECONDS);
	AlarmMonitorStateID=Monitor_waiting;
	stop_alarm();
	Alarm_Monitor_State=STATE(alarm_OFF);

}
STATE_DEFINE_FUNC(alarm_OFF)
{
		AlarmMonitorStateID=alarmoff;
		stop_alarm();
		AlarmMonitorStateID=Monitor_waiting;
}
void high_pressure_detection()
{
	Alarm_Monitor_State=STATE(alarm_ON);
}
