/*
 ============================================================================
 Name        : Student.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"
#include "student_functions.h"

FIFO_Buff_t student_queue;/*our queue*/
int choice=0;/*user choice*/
/*This function just display options for the user to choose from*/
void display_options()
{
	_PRINTF("Choose The Task to be be performed\n");
	_PRINTF("------------------------------------------\n");
	_PRINTF("1] Add Students Details Manually\n");
	_PRINTF("2] Add Students Details From Text File\n");
	_PRINTF("3] Find Student Details by Roll Number\n");
	_PRINTF("4] Find Student Details by First Name\n");
	_PRINTF("5] Find Student Details by Course\n");
	_PRINTF("6] Find Total Number of Students\n");
	_PRINTF("7] Delete Students Details by Roll Number\n");
	_PRINTF("8] Update Students Details by Roll Number\n");
	_PRINTF("9] Show All Information\n");
	_PRINTF("10] Exit\n");
	_PRINTF("Enter your choice: ");


}
int main(void)
{
	FIFO_Status_t student_queue_status;/*that is a variable to store the queue status*/
	student_queue_status=FIFO_init(&student_queue,NUMBER_OF_STUDENTS,students,Circular);
	/*we initialize the queue to be circular giving number of element and place in memory to Be stored*/
	if(student_queue_status==FIFO_ALLOCATION_ERROR )
	{ /*Make sure memory is accessible*/
		_PRINTF("[ERROR] Initializing the buffer\n");
		return 0;/*Exit if not*/
	}
	if(student_queue_status==FIFO_WRONG_TYPE)
	{/*Make sure queue is correct data type linear or circular*/
		_PRINTF("[ERROR] Wrong buffer type\n");
		return 0;/*Exit if not*/
	}
	if(student_queue.type==Linear)
	{/*WARN user that his fifo is linear*/
		_PRINTF("[WARNING] You chose fifo to be linear so you cannot exceed adding [number of students = %d]\n",NUMBER_OF_STUDENTS);
	}

	/*Welcome user*/
	_PRINTF("Welcome to the Student Management System\n");
	while(1)
	{/*Display options for user*/
		display_options();
		/*Take user choice*/
		scanf("%d",&choice);
		/*After we take user input we do the task he chose*/
		switch(choice)
		{
		case 1: add_student_manually(&student_queue);
		break;
		case 2: add_student_from_file(&student_queue);
		break;
		case 3: find_student_roll_number(&student_queue);
		break;
		case 4: find_student_first_name(&student_queue);
		break;
		case 5: find_student_course(&student_queue);
		break;
		case 6: total_number_of_students(&student_queue);
		break;
		case 7: delete_student(&student_queue);
		break;
		case 8: update_student(&student_queue);
		break;
		case 9: show_all(&student_queue);
		break;
		case 10:
			_PRINTF("Bye\n");
			return 0;
		default: _PRINTF("[ERROR] Invalid option try again\n");
		break;
		}
		_PRINTF("________________________________________________________________\n\n");
	}

	return 0;
}
