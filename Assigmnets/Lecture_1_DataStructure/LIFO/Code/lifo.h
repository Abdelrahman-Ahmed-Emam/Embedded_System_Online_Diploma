/*
 * LIFO.h
 *
 *  Created on: Feb 10, 2024
 *      Author: Abdelrahman
 */

#ifndef LIFO_H_
#define LIFO_H_
#include <stdlib.h>
#include "platforms_Type.h"
#define elementType uint32 /*we define the element type using the
							user-made platforms_types file
							we can also change the elementType by undefine the elementType
							then re-define it
							EX:
							#undef elementType
							#define elementType char*/

typedef enum
{
	LIFO_FULL,/*LIFO is full we can't push another element*/
	LIFO_ALLOCATION_ERROR,/*The address given is not valid we can't allocate the LIFO*/
	LIFO_NO_ALLOCATION_ERROR,/*We allocate the LIFO successfully*/
	LIFO_EMPTY,/*LIFO is empty you can't pop any element*/
	LIFO_SUCCESS_PUSH,/*You successfully pushed another element in the LIFO*/
	LIFO_FAILED_PUSH,/*You failed to push an element in the LIFO*/
	LIFO_SUCCESS_POP,/*You successfully pop an element*/
	LIFO_FAILED_POP, /*You failed to pop an element*/
	LIFO_READY /*LIFO is not empty or full*/
}LIFO_Status_t;

typedef struct
{
	uint32 lenght;/*Length of the LIFO*/
	elementType *base;/*Base address of LIFO (First pushed element)*/
	elementType *head; /*The address of first empty place*/
	uint32 count; /*count how many elements occupied in the LIFO*/

} LIFO_Buff_t;


extern LIFO_Status_t LIFO_check(LIFO_Buff_t *buffer);/*Check if given address is available*/
extern LIFO_Status_t LIFO_init(LIFO_Buff_t *buffer,elementType * start,uint32 size);/*Initialize the buffer*/
extern LIFO_Status_t LIFO_Status(LIFO_Buff_t *buffer);/*To know if it is full or not*/
extern LIFO_Status_t LIFO_push_item(LIFO_Buff_t *buffer,elementType item);/*Push item in the LIFO*/
extern LIFO_Status_t LIFO_pop_item(LIFO_Buff_t *buffer ,elementType *item);/*Pop item from the LIFO*/





#endif /* LIFO_H_ */
