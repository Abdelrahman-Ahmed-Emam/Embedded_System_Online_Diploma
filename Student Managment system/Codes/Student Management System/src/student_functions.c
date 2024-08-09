/*
 * functions.c
 *
 *  Created on: Jul 22, 2024
 *      Author: abdel
 */


#include "student_functions.h"
#define ERROR 1
#define NO_ERROR 0
#define TRUE 1
#define FALSE 0
/*Check fifo is empty or not to see if we can delete or show or search for a student*/
int checkFIFOempty(FIFO_Buff_t * Buffer)
{
	if(FIFO_Status(Buffer)== FIFO_EMPTY)
	{
		_PRINTF("[ERROR] There is no students data\n");
		return ERROR;
	}
	return NO_ERROR;
}
/*Check fifo is full or not to see if we can add student*/
int checkFIFOfull(FIFO_Buff_t * Buffer)
{
	if(FIFO_Status(Buffer)==FIFO_FULL)
	{
		_PRINTF("[ERROR] There is no enough places to add students\n");
		return ERROR;
	}
	return NO_ERROR;
}
/*we check that the roll number is not entered previously*/
int check_student(FIFO_Buff_t * Buffer,int numberTocheck)
{
	int i=0;
	elementType *temp=Buffer->Tail;
	/*check with element roll number that is unique*/
	for(;i<Buffer->count;i++)
	{
		if(numberTocheck==temp->roll_number)
			{
				return ERROR;
			}
		temp++;
	}
	return NO_ERROR;
}
/*print student info*/
void printStudent(struct student_info *student)
{
	_PRINTF("[INFO]        First Name: %s\n",student->first_name);
	_PRINTF("[INFO]        Last Name: %s\n",student->last_name);
	_PRINTF("[INFO]        GPA: %.2f\n",student->GPA);
	_PRINTF("[INFO]        Roll Number: %d\n",student->roll_number);
	_PRINTF("[INFO]        Courses enrolled: ");
	printArray(student->course_id,MAX_COURSES_NUMBER);
}


/*update student data*/
void update_data(elementType*student,FIFO_Buff_t * Buffer)
{
	/*We take student from the function then we take the new data and assign it to the correct field*/
	int choice=0;
	_PRINTF("Select field to be updated\n");
	_PRINTF("1]First Name\n2]Last Name\n3]GPA\n4]Courses ID\n5]Roll Number\n");
	_PRINTF("Enter your choice: ");
	_SCANF("%d",&choice);
	int rollnumber=0;
	switch(choice)
	{
	case 1:
		_PRINTF("Enter student First Name: ");
		_SCANF("%s",student->first_name);
		_PRINTF("[INFO]First Name changed to %s\n",student->first_name);
		break;
	case 2:
		_PRINTF("Enter student Last Name: ");
		_SCANF("%s",student->last_name);
		_PRINTF("[INFO]Last Name changed to %s\n",student->last_name);
		break;
	case 3:
		_PRINTF("Enter student GPA: ");
		_SCANF("%f",&student->GPA);
		_PRINTF("[INFO]GPA changed to %.2f\n",student->GPA);
		break;
	case 4:
		_PRINTF("Enter student courses again: ");
		fillArray(student->course_id, MAX_COURSES_NUMBER);
		_PRINTF("[INFO]Courses currently enrolled in :");
		printArray(student->course_id, MAX_COURSES_NUMBER);
		break;
	case 5:
		/*Make sure that this roll number not already in use*/
		_PRINTF("Enter student Roll Number: ");
		_SCANF("%d",&rollnumber);
		if(check_student(Buffer, rollnumber)==NO_ERROR)
		{
			student->roll_number=rollnumber;
			_PRINTF("[INFO] Roll Number changed to %d\n",student->roll_number);
		}
		else
		{
			_PRINTF("[ERROR] Roll Number already assigned to another student \nRoll Number entered %d\n",rollnumber);
		}
		break;
	default:
		_PRINTF("[ERROR] Entered Wrong Choice\n Exiting...\n");
	}
}
/*add student to the queue checking that queue had enough space and his roll number is unique*/
void addToFIFO(elementType *element,FIFO_Buff_t * Buffer)
{

	if(Buffer->Head==(elementType *)((uint32)Buffer->Base+(Buffer->lenght*sizeof(elementType))))/*Reaches end*/
	{
		if(Buffer->type==Linear)/*If linear and reaches end */
		{
			_PRINTF("[INFO] Reached end\n");
			return ;
		}
		else if(Buffer->type==Circular)/*If circular then head return to base when reach end*/
		{
			Buffer->Head=Buffer->Base;
			Buffer->count++;/*Increase counter*/
			/*Copying student data*/
			Buffer->Head->GPA=element->GPA;
			Buffer->Head->roll_number=element->roll_number;
			myStrCpy(element->first_name,Buffer->Head->first_name);
			myStrCpy(element->last_name,Buffer->Head->last_name);
			arrcpy(element->course_id,Buffer->Head->course_id,10);
			Buffer->Head++;
			_PRINTF("[INFO] Back on Top\n");
		}
	}
	/*If we did not reach the end of the queue*/
	Buffer->Head->GPA=element->GPA;
	Buffer->Head->roll_number=element->roll_number;
	myStrCpy(element->first_name,Buffer->Head->first_name);
	myStrCpy(element->last_name,Buffer->Head->last_name);
	arrcpy(element->course_id,Buffer->Head->course_id,10);
	Buffer->count++;/*Increase counter*/
	Buffer->Head++;
	_PRINTF("[INFO] Student added successfully\n");
}
/*Get student data from files*/
void getData(char *line,FIFO_Buff_t * Buffer)
{
	char holdingData[50];
	elementType student;
	int counter=-1;
	int i=0;
	int j=0;
	int rollnumber=0;
	float GPA=0;
	while((*line)!='\n' && (*line)!='\0' &&(*line)!=EOF)
	{
		j=0;
		counter++;
		while((*line)!=' ')
		{
			holdingData[j]=(*line);
			line++;
			j++;
		}
		holdingData[j]='\0';
		line++;
		switch(counter)
		{
		case 0:
			rollnumber=myAtoi(holdingData);
			if(check_student(Buffer, rollnumber)==NO_ERROR)
			{
				student.roll_number=rollnumber;

			}
			else
			{
				_PRINTF("[ERROR] Roll number already exists\n");
				return;
			}
			break;
		case 1:
			myStrCpy(holdingData,student.first_name);
			break;
		case 2:
			myStrCpy(holdingData, student.last_name);
			break;
		case 3:
			GPA=myAtof(holdingData);
			student.GPA=GPA;
			break;
		default:
			student.course_id[i]=myAtoi(holdingData);
			i++;
			break;
		}
		student.course_id[i]=-1;
	}

	addToFIFO(&student, Buffer);
}
void add_student_from_file(FIFO_Buff_t * Buffer)
{
	char filename[20];
	if(checkFIFOfull(Buffer)==ERROR)
		return;
	_PRINTF("Enter file to read from with its extension: ");/*Take file name from user*/
	fflush(stdin);
	gets(filename);
	FILE *myFile=fopen(filename,"r");/*open file to read*/
	if(myFile==NULL)
	{
		_PRINTF("[ERROR] Cannot open file\n");
	}
	else
	{
		char line[300];

		while(fgets(line,300,myFile)!=NULL)/*Reach file end*/
		{
			if(checkFIFOfull(Buffer)==ERROR)
					return;
			getData(line,Buffer);
		}

		fclose(myFile);/*close file at the end*/
		total_number_of_students(Buffer);
	}
}
/*Take student data manually from the user directly from terminal*/
void add_student_manually(FIFO_Buff_t * Buffer)
{
	/*check fifo is not full first*/
	if(checkFIFOfull(Buffer)==ERROR)
		return;
	_PRINTF("Adding Student Data:-\n");
	_PRINTF("------------------------------\n");
	struct student_info newStudent;/*variable to store the student data*/
	_PRINTF("Enter roll number: ");
	_SCANF("%d",&newStudent.roll_number);/*take the student roll number*/
	if(check_student(Buffer,newStudent.roll_number)==NO_ERROR)/*we proceed with our data entry if the roll number is unique*/
	{
		/*take the student data*/
		_PRINTF("Enter Student First Name: ");
		_SCANF("%s",newStudent.first_name);
		_PRINTF("Enter Student Last Name: ");
		_SCANF("%s",newStudent.last_name);
		_PRINTF("Enter Student GPA: ");
		_SCANF("%f",&newStudent.GPA);
		fillArray(newStudent.course_id,MAX_COURSES_NUMBER);
		addToFIFO(&newStudent,Buffer);
	}
	else
	{
		printf("[ERROR] Roll number entered twice\n");
	}
	total_number_of_students(Buffer);
}

/*Search for student by his roll number*/
void find_student_roll_number(FIFO_Buff_t * Buffer)
{
	elementType *temp=Buffer->Tail;/*Variable holding current data*/
	int rollNumber=0;
	if(checkFIFOempty(Buffer)==NO_ERROR)/*Make sure fifo is not empty*/
	{
		_PRINTF("Searching for student using Roll number:-\n");
		_PRINTF("---------------------------------------------------------\n");
		_PRINTF("Enter student roll number: ");
		_SCANF("%d",&rollNumber);
		int i=0;
		for(;i<Buffer->count;i++)/*Loop to search*/
		{
			if(temp==(elementType *)((uint32)Buffer->Base+(Buffer->lenght*sizeof(elementType))))/*if we reach end we return back*/
			{
				temp=Buffer->Base;
			}
			if(temp->roll_number==rollNumber)/*if we found the student with roll number*/
			{
				printStudent(temp);/*print student*/
				return;/*Exit function*/
			}
			temp++;
		}
		/*We reach here if we can't find the student so we give an error message*/
		_PRINTF("[ERROR] Student is not found make sure that student is in the system previously "
				"or check roll number is correct \n Roll number entered is : %d\n",rollNumber);
	}
}
/*Search for student by his First Name*/
void find_student_first_name(FIFO_Buff_t * Buffer)
{
	elementType *temp=Buffer->Tail;/*Variable holding current data*/
	char firstName[50];
	_Bool found=FALSE;/*we did not found any student with this first name*/
	if(checkFIFOempty(Buffer)==NO_ERROR)/*Make sure fifo is not empty*/
	{
		_PRINTF("Searching for student using First Name:-\n");
		_PRINTF("---------------------------------------------------------\n");
		_PRINTF("Enter student First Name: ");
		_SCANF("%s",firstName);
		int i=0;
		for(;i<Buffer->count;i++)/*Loop to search*/
		{
			if(temp==(elementType *)((uint32)Buffer->Base+(Buffer->lenght*sizeof(elementType))))/*if we reach end we return back*/
			{
				temp=Buffer->Base;
			}
			if(myStrCmp(temp->first_name,firstName)==0)/*if we found the student with the first name*/
			{
				printStudent(temp);/*print student*/
				_PRINTF("********************************\n");/*just a separator*/
				found=TRUE;
			}
			temp++;/*increment to next student*/
		}
		/*We reach here if we can't find the student so we give an error message*/
		if(found==FALSE)
		{
			_PRINTF("[ERROR] Student is not found make sure that student is in the system previously "
					"or check First Name is correct \n First Name entered is : %s\n",firstName);
		}
	}
}
/*Search for student by his course number*/
void find_student_course(FIFO_Buff_t * Buffer)
{
	elementType *temp=Buffer->Tail;/*Variable holding current data*/
	int courseID=0;
	int counter=0;
	_Bool found=FALSE;/*we did not found any student with this course ID*/
	if(checkFIFOempty(Buffer)==NO_ERROR)/*Make sure fifo is not empty*/
	{
		/*Take course ID from user*/
		_PRINTF("Searching for students using course ID:-\n");
		_PRINTF("---------------------------------------------------------\n");
		_PRINTF("Enter course ID: ");
		_SCANF("%d",&courseID);
		int i=0;
		for(;i<Buffer->count;i++)/*Loop to search*/
		{
			if(temp==(elementType *)((uint32)Buffer->Base+(Buffer->lenght*sizeof(elementType))))/*if we reach end we return back*/
			{
				temp=Buffer->Base;
			}
			int j=0;
			for(;j<MAX_COURSES_NUMBER;j++)
			{
				if(temp->course_id[j]==courseID)
				{
					printStudent(temp);/*print student*/
					_PRINTF("********************************\n");/*just a separator*/
					found=TRUE;
					counter++;
				}
			}
			temp++;/*increment to next student*/
		}
		/*We reach here if we can't find the student so we give an error message*/
		if(found==FALSE)
		{
			_PRINTF("[ERROR] Student is not found make sure that student is in the system previously "
					"or check course ID is correct \n Course ID entered is : %d\n",courseID);
		}
		else
		{
			_PRINTF("[INFO] Number of students in the course is %d\n",counter);
		}
	}

}
/*Print total number of students in the system , print number of available places to add students and
 * Max number of students you can add
 */
void total_number_of_students(FIFO_Buff_t * Buffer)
{
	_PRINTF("Print total number of students on the system:-\n");
	_PRINTF("--------------------------------------------------------------\n");
	_PRINTF("Number of students you have : %d\n",Buffer->count);
	_PRINTF("Total Available spaces : %d\n",Buffer->lenght-Buffer->count);
	_PRINTF("MAX NUMBER OF STUDENTS TO ADD : %d\n",Buffer->lenght);
}
/*Delete student by his roll number*/
void delete_student(FIFO_Buff_t * Buffer)
{
	elementType *temp=Buffer->Tail;/*Variable holding current data*/
	int rollNumber=0;
	if(checkFIFOempty(Buffer)==NO_ERROR)/*Make sure fifo is not empty*/
	{
		_PRINTF("Searching for student to delete using roll number:-\n");
		_PRINTF("---------------------------------------------------------\n");
		_PRINTF("Enter student roll number to delete: ");
		_SCANF("%d",&rollNumber);
		int i=0;
		for(;i<Buffer->count;i++)/*Loop to search*/
		{
			if(temp==(elementType *)((uint32)Buffer->Base+(Buffer->lenght*sizeof(elementType))))/*if we reach end we return back*/
			{
				temp=Buffer->Base;
			}
			if(temp->roll_number==rollNumber)/*if we found the student with roll number*/
			{/*Start shifting data left by 1 from place we found the student*/
				int j=i;
				elementType *temp2=temp+1;/*Variable holding next data*/
				for(;j<Buffer->count-1;j++)
				{
					if(temp==(elementType *)((uint32)Buffer->Base+(Buffer->lenght*sizeof(elementType))))/*if we reach end we return back*/
					{
						temp=Buffer->Base;
					}
					if(temp2==(elementType *)((uint32)Buffer->Base+(Buffer->lenght*sizeof(elementType))))/*if we reach end we return back*/
					{
						temp2=Buffer->Base;
					}
					temp->GPA=temp2->GPA;
					temp->roll_number=temp2->roll_number;
					myStrCpy(temp2->first_name, temp->first_name);
					myStrCpy(temp2->last_name, temp->last_name);
					arrcpy(temp2->course_id, temp->course_id, MAX_COURSES_NUMBER);
					temp++;
					temp2++;

				}
				Buffer->count--;/*Decrease count by 1*/
				Buffer->Head--;/*Return head 1 place as we can re-write in this place*/
				_PRINTF("[INFO] Student deleted successfully\n");
				return;/*exit loop after it*/
			}
			temp++;
		}
		/*We reach here if we can't find the student so we give an error message*/
		_PRINTF("[ERROR] Student is not found make sure that student is in the system previously "
				"or check roll number is correct \n Roll number entered is : %d\n",rollNumber);
	}

}
/*Update student data by searching for him by roll number*/
void update_student(FIFO_Buff_t * Buffer)
{
	elementType *temp=Buffer->Tail;/*Variable holding current data*/
	int rollNumber=0;
	if(checkFIFOempty(Buffer)==NO_ERROR)/*Make sure fifo is not empty*/
	{
		_PRINTF("Searching for student using Roll number to update:-\n");
		_PRINTF("---------------------------------------------------------\n");
		_PRINTF("Enter student roll number: ");
		_SCANF("%d",&rollNumber);
		int i=0;
		for(;i<Buffer->count;i++)/*Loop to search*/
		{
			if(temp==(elementType *)((uint32)Buffer->Base+(Buffer->lenght*sizeof(elementType))))/*if we reach end we return back*/
			{
				temp=Buffer->Base;
			}
			if(temp->roll_number==rollNumber)/*if we found the student with roll number*/
			{
				update_data(temp,Buffer);/*update student data*/
				_PRINTF("Data updated successfully\nStudent now:\n");
				printStudent(temp);/*print the student with changed data*/
				return;/*Exit function*/
			}
			temp++;
		}
		_PRINTF("[ERROR] Student is not found make sure the roll number is entered perviosuly or correct \n"
				"Roll number entered %d\n",rollNumber);
	}
}
/*Print all students data*/
void show_all(FIFO_Buff_t * Buffer)
{
	elementType *temp=Buffer->Tail;
	if(checkFIFOempty(Buffer)==NO_ERROR)/*we check fifo is not empty*/
	{
		_PRINTF("Printing students data:-\n");
		_PRINTF("-----------------------------------\n");
		int i=0;
		for(;i<Buffer->count;i++)
		{
			if(temp==(elementType *)((uint32)Buffer->Base+(Buffer->lenght*sizeof(elementType))))/*reach end of queue*/
			{
				temp=Buffer->Base;
			}
			/*print student data*/
			printStudent(temp);
			_PRINTF("********************************\n");/*just a separator*/
			temp++;/*increment to next student*/
		}
	}
}

