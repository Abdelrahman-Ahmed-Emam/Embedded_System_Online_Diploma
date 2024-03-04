/*
 * lifi.c
 *
 *  Created on: Feb 10, 2024
 *      Author: Abdelrahman
 */

#include "lifo.h"

LIFO_Status_t LIFO_check(LIFO_Buff_t *buffer)/*Check if given address is available*/
{
	if(!buffer || !buffer->base || !buffer->head)
		return LIFO_ALLOCATION_ERROR; /*if the address is not available then error in allocation*/
	else
		return LIFO_NO_ALLOCATION_ERROR;/*There is no error*/
}
LIFO_Status_t LIFO_init(LIFO_Buff_t *buffer,elementType * start,uint32 size)/*Initialize the buffer*/
{
	if(!buffer || !start)/*make sure both addresses are available*/
		return LIFO_ALLOCATION_ERROR;
	else/*if available then assign addresses and initialize length and count*/
	{
		buffer->base=start;
		buffer->head=start;
		buffer->count=0;
		buffer->lenght=size;
		return LIFO_NO_ALLOCATION_ERROR;
	}

}
LIFO_Status_t LIFO_Status(LIFO_Buff_t *buffer)/*To know if it is full or not or ready for pop or push*/
{
	if(LIFO_check(buffer)==LIFO_ALLOCATION_ERROR)
		return LIFO_ALLOCATION_ERROR;
	else if(buffer->lenght==buffer->count)
		return LIFO_FULL;/*can not push more elements*/
	else if(buffer->count==0)
		return LIFO_EMPTY;/*can not pop more elements*/
	else
		return LIFO_READY;/*not full or empty*/
}
LIFO_Status_t LIFO_push_item(LIFO_Buff_t *buffer,elementType item)/*Push item in the LIFO*/
{
	if(LIFO_check(buffer)==LIFO_NO_ALLOCATION_ERROR)/*user forget to initialize the buffer*/
	{
		if(LIFO_Status(buffer)!=LIFO_FULL)/*Not full so we can add elements*/
		{
			*(buffer->head)=item;/*add variable*/
			buffer->count++;/*increase counter*/
			buffer->head++;/*move to next available place*/
			return LIFO_SUCCESS_PUSH;/*Tell this a successful push*/
		}
		else
			return LIFO_FULL;/*No available space*/
	}
	else
		return LIFO_FAILED_PUSH; /*Error in pushing data*/
}
LIFO_Status_t LIFO_pop_item(LIFO_Buff_t *buffer ,elementType *item)
{
	if(LIFO_check(buffer)==LIFO_NO_ALLOCATION_ERROR)/*user forget to initialize the buffer*/
	{
		if(LIFO_Status(buffer)!=LIFO_EMPTY)
		{
			buffer->head--;/*go to last element*/
			*item=*(buffer->head);/*pop it to given variable*/
			buffer->count--;/*decrement count*/
			return LIFO_SUCCESS_POP; /*Successful pop*/
		}
		else
			return LIFO_EMPTY; /*No elements to pop*/
	}
	else
		return LIFO_FAILED_POP; /*Error retrieving data*/

}
