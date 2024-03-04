/*
 ============================================================================
 Name        : LIFI.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "platforms_Type.h"
#include "lifo.h"
#define _PRINTF(...) fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdout)
elementType DataUart[4];/*elements size of 32 bit */
LIFO_Buff_t UART;
void DisplayOptions()
{
	_PRINTF("\n\n----------\nOptions\n------------\n");
	_PRINTF("1] add item\n");
	_PRINTF("2] pop item\n");
	_PRINTF("3] show status\n");
	_PRINTF("4] show items\n");
}
void addItem(LIFO_Buff_t *buffer)
{
	_PRINTF("Enter your item please : ");
	elementType item=0;
	scanf("%lu",&item);
	fflush(stdin);
	LIFO_Status_t check=0;
	check=LIFO_push_item(buffer,item);
	if(check==LIFO_FAILED_PUSH )
	{
		_PRINTF("LIFO failed to push\n");
	}
	else if(check==LIFO_FULL)
	{
		_PRINTF("LIFO is full\n");
	}
	else if(check==LIFO_SUCCESS_PUSH)
	{
		_PRINTF("LIFO success fully pushed\n");
	}


}
elementType getItem(LIFO_Buff_t *buffer)
{
	LIFO_Status_t check=0;
	elementType item=0;
	check=LIFO_pop_item(buffer,&item);
	if(check==LIFO_FAILED_POP)
	{
		_PRINTF("LIFO failed to pop\n");
	}
	else if(check== LIFO_EMPTY)
	{
		_PRINTF("LIFO is empty\n");
	}
	else if(check == LIFO_SUCCESS_POP)
	{
		_PRINTF("LIFO success pop\n");
	}
	return item;
}
void viewLIFO(LIFO_Buff_t *buffer)
{
	elementType *pointer=buffer->base;
	int i=0;
	if(LIFO_Status(buffer)!=LIFO_EMPTY)
	{
		for(i=0;i<buffer->count;i++)

		{
			_PRINTF("Data %d] %lu\n",i+1,*pointer);
			pointer++;
		}
	}
	else
	{
		_PRINTF("Empty list\n");
	}
}

LIFO_Status_t getStatus(LIFO_Buff_t*buffer)
{
	LIFO_Status_t check= LIFO_Status(buffer);
	if(check==LIFO_FULL)
	{
		_PRINTF("LIFO is full\n");
	}
	else if(check==LIFO_EMPTY)
	{
		_PRINTF("LIFO is empty\n");
	}
	else if(check==LIFO_READY)
	{
		_PRINTF("LIFO is available for pop or push\n");
	}
	else if(check==LIFO_ALLOCATION_ERROR)
	{
		_PRINTF("LIFO ALLOCATION ERROR\n");
	}
	return check;
}

int main(void)
{

	LIFO_Status_t checkUart=0;
	uint8 option=0;
	elementType item=0;
	checkUart=LIFO_init(&UART,DataUart,4);
	if(checkUart==LIFO_ALLOCATION_ERROR)
		return 0;
	while(1)
	{
		DisplayOptions();
		_PRINTF("Enter your option : ");
		scanf("%c",&option);
		fflush(stdin);
		switch(option)
		{
		case '1': addItem(&UART);
		break;
		case '2': item=getItem(&UART);
		break;
		case '3': checkUart=getStatus(&UART);
		break;
		case '4': viewLIFO(&UART);
		break;
		default:
			_PRINTF("Invalid option\n");
			break;
		}

	}

	return 0;
}
