/*
 ============================================================================
 Name        : FIFO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"
#define _PRINTF(...) fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdout)
FIFO_Buff_t DATA;
elementType data[4];
FIFO_Buff_t ITEM;
elementType items[4];
FIFO_Buff_t* chosen=0;
void DisplayOptions()
{
	_PRINTF("\n\n----------\nOptions\n------------\n");
	_PRINTF("1] add item\n");
	_PRINTF("2] return item\n");
	_PRINTF("3] show status\n");
	_PRINTF("4] show items\n");
	_PRINTF("5] change buffer\n");
}
void addItem(FIFO_Buff_t *Buffer)
{
	FIFO_Status_t check=0;
	_PRINTF("Enter your item please : ");
	elementType item=0;
	scanf("%lu",&item);
	fflush(stdin);
	check=FIFO_enqueue(Buffer ,item);
	if(check==FIFO_FAILED_ADD)
	{
		_PRINTF("Fail to add items\n");
	}
	else if(check==FIFO_WRONG_TYPE)
	{
		_PRINTF("Wrong type for FIFO\n");
	}
	else if(check==FIFO_FULL)
	{
		_PRINTF("FIFO is full\n");
	}
	else if(check==FIFO_REACH_END)
	{
		_PRINTF("You can read only from FIFO\n");
	}
	else if(check==FIFO_RESTARTED)
	{
		_PRINTF("FIFO returned to the beginning\n");
	}
	else if(check ==FIFO_SUCCESS_ADD)
	{
		_PRINTF("Data is added successfully\n");
	}
}

elementType getItem(FIFO_Buff_t*Buffer)
{
	FIFO_Status_t check=0;
	elementType item=0;
	check=FIFO_dequeue(Buffer,&item);
	if(check==FIFO_FAILED_RETURN)
	{
		_PRINTF("Fail to return items\n");
	}
	else if(check==FIFO_WRONG_TYPE)
	{
		_PRINTF("Wrong type for FIFO\n");
	}
	else if(check==FIFO_EMPTY)
	{
		_PRINTF("FIFO is empty\n");
	}
	else if(check==FIFO_REACH_END)
	{
		_PRINTF("FIFO finished\n");
	}
	else if(check==FIFO_RESTARTED)
	{
		_PRINTF("FIFO returned to the beginning\n");
	}
	else if(check ==FIFO_SUCCESS_RETURN)
	{
		_PRINTF("Data is returned successfully\n");
	}
	return item;
}
void ShowStaus(FIFO_Buff_t *Buffer)
{
	FIFO_Status_t check=0;
	check=FIFO_Status(Buffer);
	if(check==FIFO_ALLOCATION_ERROR)
	{
		_PRINTF("Allocation error of FIFO\n");
	}
	else if(check==FIFO_FULL)
	{
		_PRINTF("FIFO is full\n");
	}
	else if(check==FIFO_EMPTY)
	{
		_PRINTF("FIFO is empty\n");
	}
	else if(check==FIFO_READY)
	{
		_PRINTF("FIFO is available for read or write\n");
	}
}
void chooseBuffer()
{
	_PRINTF("Choose buffer\n 1]DATA\t2]ITEM\n choice: ");
	int choice=0;
	scanf("%d",&choice);
	fflush(stdin);
	if(choice==1)
		chosen=&DATA;
	else
		chosen=&ITEM;
}
int main(void)
{
	FIFO_Status_t dataCheck=0,itemCheck=0;
	dataCheck=FIFO_init(&DATA,4,data,Circular);
	itemCheck=FIFO_init(&ITEM,4,items,Linear);
	if(dataCheck==FIFO_ALLOCATION_ERROR || itemCheck==FIFO_ALLOCATION_ERROR)
	{
		_PRINTF("Error initializing the 2 FIFOs\n");
		return 1;
	}
	chooseBuffer();
	uint8 option=0;
	elementType item=0;
	while(1)
	{
		DisplayOptions();
		_PRINTF("Enter your option : ");
		scanf("%c",&option);
		fflush(stdin);
		_PRINTF("\n");
		switch(option)
		{
		case '1': addItem(chosen);
		break;
		case '2': item=getItem(chosen);
		break;
		case '3': ShowStaus(chosen);
		break;
		case '4': FIFO_print(chosen);
		break;
		case '5': chooseBuffer();
		break;
		default:
			_PRINTF("Invalid option\n");
			break;
		}



	}
}
