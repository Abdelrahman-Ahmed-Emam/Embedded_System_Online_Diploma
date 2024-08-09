/*
 * FIFO.c
 *
 *  Created on: Feb 13, 2024
 *      Author: Abdelrahman
 */
#include "fifo.h"
FIFO_Status_t FIFO_init(FIFO_Buff_t * Buffer,uint32 size, elementType * start,FIFO_Type_t Type)
{
	if(!start || !Buffer)
		return FIFO_ALLOCATION_ERROR;/*Not valid addresses of starting the FIFO or FIFO not created*/
	else if(Type != Linear && Type != Circular)
		return FIFO_WRONG_TYPE;/*User entered wrong type of FIFO*/
	else/*Initialize the FIFO*/
	{
		Buffer->Base=start;
		Buffer->Head=start;
		Buffer->Tail=start;
		Buffer->count=0;
		Buffer->lenght=size;
		Buffer->type=Type;
		return FIFO_NO_ALLOCATION_ERROR;
	}
}
FIFO_Status_t FIFO_check(FIFO_Buff_t *Buffer)
{
	if(!Buffer || !Buffer->Base || !Buffer->Tail || !Buffer->Head)/*Make sure all has valid address*/
		return FIFO_ALLOCATION_ERROR;
	else
		return FIFO_NO_ALLOCATION_ERROR;
}
FIFO_Status_t FIFO_Status (FIFO_Buff_t *Buffer)
{	if(FIFO_check(Buffer)==FIFO_ALLOCATION_ERROR)/*Make sure the FIFO is valid*/
	return FIFO_ALLOCATION_ERROR;
else if(Buffer->count==Buffer->lenght)/*FIFO is full*/
	return FIFO_FULL;
else if(Buffer->count==0)/*We did not add any elements yet*/
	return FIFO_EMPTY;
else/*FIFO has empty places as well as used spaces ready to add or return elements*/
	return FIFO_READY;
}
FIFO_Status_t FIFO_enqueue(FIFO_Buff_t* Buffer , elementType *item)
{
	if(FIFO_check(Buffer)==FIFO_ALLOCATION_ERROR)
		return FIFO_FAILED_ADD;/*Can not add element*/
	else if(Buffer->type != Linear && Buffer->type != Circular)
		return FIFO_WRONG_TYPE;/*User entered wrong type of FIFO*/
	else
	{
		if(FIFO_Status(Buffer)==FIFO_FULL)
			return FIFO_FULL;/*FIFO is full*/
		else/*Add item normally*/
		{
			if(Buffer->Head==(elementType *)((uint32)Buffer->Base+(Buffer->lenght*sizeof(elementType))))/*Reaches end*/
			{
				if(Buffer->type==Linear)/*If linear and reaches end */
					return FIFO_REACH_END;
				else if(Buffer->type==Circular)/*If circular then head return to base when reach end*/
				{
					Buffer->Head=Buffer->Base;
					*(Buffer->Head)=*item;/*Add item*/
					Buffer->count++;/*Increase counter*/
					Buffer->Head++;
					return FIFO_RESTARTED;
				}
			}
			/*FIFO added the item and did not reach end yet*/
			*(Buffer->Head)=*item;/*Add item*/
			Buffer->count++;/*Increase counter*/
			Buffer->Head++;
			return FIFO_SUCCESS_ADD;


		}
	}
}
FIFO_Status_t FIFO_dequeue (FIFO_Buff_t* Buffer ,elementType *item)
{
	if(FIFO_check(Buffer)==FIFO_ALLOCATION_ERROR)
		return FIFO_FAILED_RETURN; /*Can not return element*/
	if(FIFO_Status(Buffer)==FIFO_EMPTY)
		return FIFO_EMPTY;/*No elements to return*/
	if(Buffer->type != Linear && Buffer->type != Circular)
		return FIFO_WRONG_TYPE;/*User entered wrong type of FIFO*/
	if(Buffer->Tail==(elementType *)((uint32)Buffer->Base+(Buffer->lenght*sizeof(elementType))))/*If tail reaches end*/
	{
		if(Buffer->type==Linear)
			return FIFO_REACH_END;/*Tell we reach end if linear*/
		else if(Buffer->type)
		{
			Buffer->Tail=Buffer->Base;/*Back to base address*/
			*item=*(Buffer->Tail);/*Return item*/
			Buffer->count--;/*decrement counter*/
			Buffer->Tail++;
			return FIFO_RESTARTED;
		}
	}
	/*FIFO is not empty or full so increment the Tail as it is ready to read*/
	*item=*(Buffer->Tail);/*Return item*/
	Buffer->count--;/*decrement counter*/
	Buffer->Tail++;
	return FIFO_SUCCESS_RETURN;
}

void FIFO_print(FIFO_Buff_t* Buffer)
{
	elementType *temp=Buffer->Tail;
	if(FIFO_check(Buffer)==FIFO_ALLOCATION_ERROR)
	{
		printf("Buffer is not located\n");
		return ;
	}
	else if(Buffer->type != Linear && Buffer->type != Circular)
	{
		printf("Buffer Wrong type\n");
		return ;
	}
	if(FIFO_Status(Buffer)== FIFO_EMPTY)
	{
		printf("FIFO is empty\n");
		fflush(stdout);
		return;
	}
	int i=0;
	for(;i<Buffer->count;i++)
	{
		if(temp==(elementType *)((uint32)Buffer->Base+(Buffer->lenght*sizeof(elementType))))
			temp=Buffer->Base;
		printf("%d location: %x\n",*(temp),temp);
		fflush(stdout);
		temp++;
		fflush(stdout);
	}
}

