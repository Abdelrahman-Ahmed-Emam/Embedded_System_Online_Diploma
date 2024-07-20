/*
 * PressureSensorDriver.c
 *
 *  Created on: Jul 19, 2024
 *      Author: abdel
 */

#include "PressureSensorDriver.h"
uint32 pressureValue=0;
void(*Pressure_Sensor_State)();
STATE_DEFINE_FUNC(read_pressure)
{
	Delay(HUNDRED_SECOND);
	pressureValue=getPressureVal();
	PressureSensorStateID=readingPressure;
	set_pressure_value(pressureValue);
	PressureSensorStateID=notWorking;
}
STATE_DEFINE_FUNC(pressure_sensor_init)
{
	//sensor initialization
	PressureSensorStateID=sensor_init;
	Pressure_Sensor_State=STATE(read_pressure);
}

