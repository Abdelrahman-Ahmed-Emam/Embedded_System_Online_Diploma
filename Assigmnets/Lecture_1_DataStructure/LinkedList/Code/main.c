/*
 ============================================================================
 Name        : LinkedList.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define _PRINTF(...) fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdout)

typedef struct
{
	int ID;
	char name[40];
	float height;
}S_data;
struct S_Student
{
	S_data student;
	struct S_Student * NextStudentPtr;
};
typedef struct S_Student S_Student_t;

S_Student_t *GPFirstStudent=NULL;

void FillRecord(S_Student_t *student)
{
	_PRINTF("Please enter student ID: ");
	scanf("%d",&(student->student.ID));
	fflush(stdin);
	_PRINTF("Please enter student name: ");
	gets(student->student.name);
	_PRINTF("Please enter student height: ");
	scanf("%f",&(student->student.height));
	fflush(stdin);
}
void addStudent()
{
	S_Student_t* PLastStudent=NULL;
	S_Student_t* PNewStudent=NULL;
	if(GPFirstStudent==NULL)
	{
		PNewStudent=(S_Student_t*)malloc(sizeof(S_Student_t));
		GPFirstStudent=PNewStudent;
	}
	else
	{
		PLastStudent=GPFirstStudent;
		while(PLastStudent->NextStudentPtr)
		{
			PLastStudent=PLastStudent->NextStudentPtr;
		}
		PNewStudent=(S_Student_t*)malloc(sizeof(S_Student_t));
		PLastStudent->NextStudentPtr=PNewStudent;
	}
	FillRecord(PNewStudent);
	PNewStudent->NextStudentPtr=NULL;
}

void deleteStudent()
{
	int ID_delete=0;
	_PRINTF("Please enter ID of student to be deleted : ");
	scanf("%d",&ID_delete);
	fflush(stdin);
	if(GPFirstStudent)
	{
		S_Student_t* P_Previous_Student=NULL;
		S_Student_t* P_Selected_Student=GPFirstStudent;
		while(P_Selected_Student)
		{
			if(P_Selected_Student->student.ID==ID_delete)
			{
				if(P_Previous_Student)
				{
					P_Previous_Student->NextStudentPtr=P_Selected_Student->NextStudentPtr;
				}
				else
				{
					GPFirstStudent=P_Selected_Student->NextStudentPtr;
				}
				free(P_Selected_Student);
				return;

			}
			P_Previous_Student=P_Selected_Student;
			P_Selected_Student=P_Selected_Student->NextStudentPtr;
		}
		_PRINTF("Could not find student\n");
	}
	else
	{
		_PRINTF("Empty List\n");
	}
}

void viewStudents()
{
	int count=0;
	if(GPFirstStudent==NULL)
	{
		_PRINTF("Empty List\n");
		return;
	}
	else
	{
		S_Student_t* P_Current_Student=GPFirstStudent;
		while(P_Current_Student)
		{
			_PRINTF("Student %d] ID: %d \n",count+1,P_Current_Student->student.ID);
			_PRINTF("            Name: %s \n",P_Current_Student->student.name);
			_PRINTF("            Height: %.2f \n",P_Current_Student->student.height);
			count++;
			P_Current_Student=P_Current_Student->NextStudentPtr;

		}
	}
}

void deleteALL()
{
	if(GPFirstStudent==NULL)
	{
		_PRINTF("Empty List\n");
		return;
	}
	else
	{
		S_Student_t* P_Current_Student=GPFirstStudent;
		S_Student_t* P_Temp_Student=P_Current_Student;
		while(P_Current_Student)
		{
			P_Current_Student=P_Current_Student->NextStudentPtr;
			free(P_Temp_Student);
			P_Temp_Student=P_Current_Student;
		}
		GPFirstStudent=NULL;
	}
}

void GethNth(int index, S_Student_t* placeToHold)
{
	int count=0;
	if(GPFirstStudent==NULL)
	{
		_PRINTF("Empty List\n");
		return;
	}
	else
	{
		S_Student_t* P_Current_Student=GPFirstStudent;
		while(count!=index && P_Current_Student)
		{
			P_Current_Student=P_Current_Student->NextStudentPtr;
			count++;
		}
		placeToHold=P_Current_Student;
		_PRINTF("ID: %d \n",P_Current_Student->student.ID);
		_PRINTF("Name: %s \n",P_Current_Student->student.name);
		_PRINTF("Height: %.2f \n",P_Current_Student->student.height);

	}
}

int GetLenght()
{
	int count=0;
	if(GPFirstStudent==NULL)
	{
		return 0;
	}
	else
	{
		S_Student_t *CurrentStudent=GPFirstStudent;
		while(CurrentStudent)
		{
			CurrentStudent=CurrentStudent->NextStudentPtr;
			count++;
		}
		return count;
	}

}
void GethNthBackward(int index, S_Student_t* placeToHold)
{
	if(GPFirstStudent==NULL)
	{
		_PRINTF("Empty List\n");
		return;
	}
	else
	{
		S_Student_t* main_Ptr=GPFirstStudent;
		S_Student_t* ref_Ptr=GPFirstStudent;
		int i=0;
		for(;i<index;i++)
		{
			ref_Ptr=ref_Ptr->NextStudentPtr;
		}
		while(ref_Ptr)
		{
			ref_Ptr=ref_Ptr->NextStudentPtr;
			main_Ptr=main_Ptr->NextStudentPtr;
		}
		placeToHold=main_Ptr;
		_PRINTF("ID: %d \n",placeToHold->student.ID);
		_PRINTF("Name: %s \n",placeToHold->student.name);
		_PRINTF("Height: %.2f \n",placeToHold->student.height);

	}
}
void Find_Middle(S_Student_t* placeToHold)
{
	if(GPFirstStudent==NULL)
	{
		_PRINTF("Empty List\n");
		return;
	}
	else
	{
		S_Student_t* Fast_ptr=GPFirstStudent;
		S_Student_t* Slow_ptr=GPFirstStudent;
		while(Fast_ptr)
		{
			Fast_ptr=Fast_ptr->NextStudentPtr;
			if(Fast_ptr)
			{
				Fast_ptr=Fast_ptr->NextStudentPtr;
				Slow_ptr=Slow_ptr->NextStudentPtr;
			}
		}
		placeToHold=Slow_ptr;
		_PRINTF("ID: %d \n",placeToHold->student.ID);
		_PRINTF("Name: %s \n",placeToHold->student.name);
		_PRINTF("Height: %.2f \n",placeToHold->student.height);
	}
}
void Find_Loop()
{
	if(GPFirstStudent==NULL)
	{
		_PRINTF("Empty List\n");
		return;
	}
	else
	{
		S_Student_t* Fast_ptr=GPFirstStudent;
		S_Student_t* Slow_ptr=GPFirstStudent;
		while(Fast_ptr)
		{
			Fast_ptr=Fast_ptr->NextStudentPtr;
			if(Fast_ptr)
			{
				Fast_ptr=Fast_ptr->NextStudentPtr;
				Slow_ptr=Slow_ptr->NextStudentPtr;
			}
			if(Fast_ptr==Slow_ptr)
			{
				_PRINTF("There is a loop\n");
				return;
			}
		}
		_PRINTF("There is no loop\n");
	}
}
void ReverseList()
{
	if(GPFirstStudent==NULL)
	{
		_PRINTF("Empty List\n");
		return;
	}
	else
	{
		S_Student_t* Prev_Ptr=GPFirstStudent;
		S_Student_t* Current_Ptr=GPFirstStudent->NextStudentPtr;
		S_Student_t* Next_Ptr=Current_Ptr->NextStudentPtr;
		GPFirstStudent->NextStudentPtr=NULL;
		while(Current_Ptr)
		{
			Next_Ptr=Current_Ptr->NextStudentPtr;
			Current_Ptr->NextStudentPtr=Prev_Ptr;
			Prev_Ptr=Current_Ptr;
			Current_Ptr=Next_Ptr;
		}
		GPFirstStudent=Prev_Ptr;
	}
}
void DisplayOptions()
{
	_PRINTF("\n---------Options--------\n");
	_PRINTF("1]Add Student\n");
	_PRINTF("2]Delete Student\n");
	_PRINTF("3]View all Students\n");
	_PRINTF("4]Delete All Students\n");
	_PRINTF("5]Get the Nth\n");
	_PRINTF("6]Find Linked List Length\n");
	_PRINTF("7]Get the Nth backward\n");
	_PRINTF("8]Get the middle\n");
	_PRINTF("9]Find the Loop or not\n");
	_PRINTF("10]Reverse list\n");
}
int main(void)
{
	int choice=0;
	int index=0;
	S_Student_t test;;
	while(1)
	{
		DisplayOptions();
		_PRINTF("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1: addStudent();
		break;
		case 2: deleteStudent();
		break;
		case 3: viewStudents();
		break;
		case 4: deleteALL();
		break;
		case 5:
			_PRINTF("Enter index: ");
			scanf("%d",&index);
			fflush(stdin);
			GethNth(index,&test);
			break;
		case 6:
			_PRINTF("Number of students are %d\n",GetLenght());
			break;
		case 7:
			_PRINTF("Enter index: ");
			scanf("%d",&index);
			fflush(stdin);
			GethNthBackward(index,&test);
			break;
		case 8: Find_Middle(&test);
		break;
		case 9: Find_Loop();
		break;
		case 10: ReverseList();
		break;
		default:
			_PRINTF("Invalid Option\n");
			break;

		}

	}



}
