/*
 * AlarmMonitor.h
 *
 *  Created on: Jul 19, 2024
 *      Author: abdel
 */

#ifndef ALARMMONITOR_H_
#define ALARMMONITOR_H_
#include "driver.h"
#include "Platforms_Type.h"
#include "state.h"
#define SIXETY_SECONDS 60000
#define ALARM_PERIOD SIXETY_SECONDS
enum
{
	Monitor_waiting,
	alarmon,
	alarmoff
}AlarmMonitorStateID;
extern void(*Alarm_Monitor_State)();
STATE_DEFINE_FUNC(alarm_ON);
STATE_DEFINE_FUNC(alarm_OFF);

#endif /* ALARMMONITOR_H_ */
