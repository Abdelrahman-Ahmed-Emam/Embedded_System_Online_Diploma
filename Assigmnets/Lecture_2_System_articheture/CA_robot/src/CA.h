/*
 * CA.h
 *
 *  Created on: Jun 2, 2024
 *      Author: Abdelrahman
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"
enum
{
	CA_waiting,
	CA_moving
}CA_state_id;

STATE_DEFINE_FUNC(CA_Waiting);
STATE_DEFINE_FUNC(CA_Moving);
extern void (*CA_state_ptr)();


#endif /* CA_H_ */
