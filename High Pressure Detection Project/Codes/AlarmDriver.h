/*
 * AlarmDriver.h
 *
 *  Created on: Jul 19, 2024
 *      Author: abdel
 */

#ifndef ALARMDRIVER_H_
#define ALARMDRIVER_H_
#include "driver.h"
#include "Platforms_Type.h"
#include "state.h"
#define ON 0
#define OFF 1
enum
{
	init,
	waiting,
	alarmON,
	alarmOFF
}AlarmDriverStateID;
extern void(*Alarm_Driver_State)();
STATE_DEFINE_FUNC(alarm_init);
STATE_DEFINE_FUNC(alarm_on);
STATE_DEFINE_FUNC(alarm_off);


#endif /* ALARMDRIVER_H_ */
