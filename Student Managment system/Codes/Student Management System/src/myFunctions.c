/*
 * myFunctions.c

 *
 *  Created on: Jul 31, 2024
 *      Author: abdel
 */
#include "myFunctions.h"
/*print array until reaching -1 or reaching max size*/
void printArray(int array[],int size)
{
	int i=0;
	while(array[i]!=-1&&i<size)
	{
		_PRINTF("%d\t",array[i]);
		i++;
	}
	_PRINTF("\n");
}

/*we fill the array until we add -1 or reaching max size */
void fillArray(int array[],int size)
{

	int input=0;
	int i=0;
	for(;i<size;i++)
	{
		_PRINTF("Press -1 when finishing adding course\n");
		_PRINTF("Enter course ID: ");
		_SCANF("%d",&input);
		array[i]=input;
		if(input==-1)
		{
			_PRINTF("Finished taking course\n");
			break;
		}
	}

}

/*copy string from source to destination*/
void myStrCpy(char *source,char *destination)
{

	char *src=source;
	char *des=destination;
	while((*src)!='\0')/*until reaching null character*/
	{
		(*des)=(*src);
		des++;
		src++;
	}
	*des='\0';
}

/*copy data from an array to another*/
void arrcpy(int source[] ,int destination[],int size)
{

	int i=0;
	for(;i<size;i++)
	{
		destination[i]=source[i];
	}

}
/*Compare between two strings return 0 if equal , return 1 if string1 is bigger , return -1 if string2 is bigger*/
int myStrCmp(char *string1,char *string2)
{
	char *str1=string1;
	char *str2=string2;
	while(*(str1)!='\0'&&*(str2)!='\0')
	{
		if((*str1)>(*str2))/*string1 is bigger return 1*/
			return 1;
		else if((*str1)<(*str2))/*string2 is bigger return -1*/
			return -1;
		str1++;
		str2++;
	}
	return 0;/*If both equal until one reach null then return 0*/
}
/*Change a string to numbers*/
int myAtoi(char*source)
{
	char *src=source;
	int number=0;
	while((*src)!='\0')
	{
		number*=10;/*increase unit*/
		number+=(*src)-48;/*convert to number*/
		src++;
	}
	return number;
}

/*Change a string to float numbers*/
float myAtof(char *source)
{
	char *src=source;
	float number=0;
	_Bool decimal =0;
	float decimalPlaces=1;
	while((*src)!='\0')
	{
		if((*src)=='.')/*if decimal point reached*/
		{
			decimal=1;/*make this true*/
			src++;
			continue;
		}
		number*=10.0;
		number+=(*src)-48;
		if(decimal==1)
		{
			decimalPlaces*=10.0;
		}
		src++;
	}
	return number/decimalPlaces;/*return number divided by decimal places as a float*/
}
