/*
 ============================================================================
 Name        : Detect_High_Pressure_Project.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "Platforms_Type.h"
#include "AlarmDriver.h"
#include "AlarmMonitor.h"
#include "PressureSensorDriver.h"
#include "MainAlgorithum.h"



int main()
{
	GPIO_INITIALIZATION();
	Pressure_Sensor_State=STATE(pressure_sensor_init);
	Alarm_Monitor_State=STATE(alarm_OFF);
	Alarm_Driver_State=STATE(alarm_init);
	while(1)
	{
		Pressure_Sensor_State();
		Alarm_Monitor_State();
	}
}
