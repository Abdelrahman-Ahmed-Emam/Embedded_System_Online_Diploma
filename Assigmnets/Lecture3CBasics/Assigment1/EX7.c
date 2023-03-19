/*
 * EX7.c
 *
 *  Created on: 17 Mar 2023
 *      Author: HP
 */
#include<stdio.h>

void main()
{
	float num1=0,num2=0;
	printf("##########Console-output(Trick)###\nEnter value of a: ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&num1);
	fflush(stdout);fflush(stdin);
	printf("Enter value of b: ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&num2);
	num1+=num2;
	num2=num1-num2;
	num1-=num2;
	printf("After swapping value of a is : %f \n After swapping value of b is : %f \n",num1,num2);
}

