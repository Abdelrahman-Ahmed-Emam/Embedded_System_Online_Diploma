/*
 * PressureSensorDriver.h
 *
 *  Created on: Jul 19, 2024
 *      Author: abdel
 */

#ifndef PRESSURESENSORDRIVER_H_
#define PRESSURESENSORDRIVER_H_
#include "driver.h"
#include "Platforms_Type.h"
#include "state.h"
#define HUNDRED_SECOND 10000000
#define PULL_TIME HUNDRED_SECOND
enum
{
	sensor_init,
	readingPressure,
	notWorking
}PressureSensorStateID;
extern void(*Pressure_Sensor_State)();
STATE_DEFINE_FUNC(pressure_sensor_init);
STATE_DEFINE_FUNC(read_pressure);


#endif /* PRESSURESENSORDRIVER_H_ */
