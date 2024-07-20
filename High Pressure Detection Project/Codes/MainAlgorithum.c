/*
 * MainAlgorithum.c
 *
 *  Created on: Jul 19, 2024
 *      Author: abdel
 */

#include "MainAlgorithum.h"

void(*Main_Algorithum_State)();
void set_pressure_value(uint32 pressureValue)
{
	MainAlgorithumStateID=pressureRecognition;
	if(pressureValue>THRESHOLD)
		high_pressure_detection();
}
