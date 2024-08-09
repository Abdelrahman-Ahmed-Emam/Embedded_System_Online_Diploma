/*
 * FIFO.h
 *
 *  Created on: Feb 13, 2024
 *      Author: Abdelrahman
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "Platforms_Type.h"
#include "stdio.h"
#define NUMBER_OF_STUDENTS 50
#define MAX_COURSES_NUMBER 10
struct student_info
{
	char first_name[50];
	char last_name[50];
	int roll_number;
	float GPA;
	int course_id[MAX_COURSES_NUMBER];
}students[NUMBER_OF_STUDENTS];

#define elementType  struct student_info /*we define the element type using the
							user-made platforms_types file
							we can also change the elementType by undefine the elementType
							then re-define it
							EX:
							#undef elementType
							#define elementType char*/

typedef enum
{
	FIFO_FULL,/*FIFO is full can not add more elements*/
	FIFO_READY,/*FIFO has still empty places*/
	FIFO_SUCCESS_ADD,/*Successfully add an element to the FIFO*/
	FIFO_FAILED_ADD,/*Failure in adding an element*/
	FIFO_SUCCESS_RETURN,/*Successfully returning an element*/
	FIFO_FAILED_RETURN,/*Failure in returning an element*/
	FIFO_EMPTY,/*FIFO has no elements*/
	FIFO_ALLOCATION_ERROR,/*Error in FIFO allocation not valid memory address*/
	FIFO_NO_ALLOCATION_ERROR,/*No error in FIFO allocation*/
	FIFO_WRONG_TYPE,/*If user initialized the buffer with wrong type*/
	FIFO_REACH_END,/*If FIFO type is linear and reaches its end*/
	FIFO_RESTARTED/*If FIFO type is circular and return back to beginning*/
}FIFO_Status_t;

typedef enum
{
	Linear,/*FIFO when reach end has to be re-allocated*/
	Circular/*Will return again to base and see if available to write or not*/
}FIFO_Type_t;

typedef struct
{
	uint32 lenght;/*Total length of FIFO*/
	uint32 count;/*How many elements in the FIFO*/
	elementType *Head;/*The address will write data in if empty*/
	elementType *Tail;/*The address will read data from*/
	elementType *Base;/*The start of the FIFO*/
	FIFO_Type_t type;/*Type of FIFO*/
}FIFO_Buff_t;


extern FIFO_Status_t FIFO_init(FIFO_Buff_t * Buffer,uint32 size, elementType * start,FIFO_Type_t Type);
/*Initialize the FIFO buffer getting its starting address making sure it is valid and
  know the size of it and linear or circular*/
extern FIFO_Status_t FIFO_enqueue(FIFO_Buff_t* Buffer , elementType *item);
/*Add item to the FIFO*/
extern FIFO_Status_t FIFO_dequeue (FIFO_Buff_t* Buffer ,elementType *item);
/*Return element from the FIFO*/
extern FIFO_Status_t FIFO_Status (FIFO_Buff_t *Buffer);
/*To know if FIFO is empty,full or ready to add or return elements*/
extern FIFO_Status_t FIFO_check(FIFO_Buff_t *Buffer);
/*Check addresses in FIFO is valid */
extern void FIFO_print(FIFO_Buff_t* Buffer);
/*Print data in buffer*/
#endif /* FIFO_H_ */
