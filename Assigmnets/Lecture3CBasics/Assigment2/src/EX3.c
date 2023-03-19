/*
 * EX3.c
 *
 *  Created on: 19 Mar 2023
 *      Author: HP
 */
#include<stdio.h>
void main()
{
	float num1=0,num2=0,num3=0;
	printf("Please enter First Number: ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&num1);
	fflush(stdout);fflush(stdin);
	printf("Please enter the second number: ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&num2);
	fflush(stdout);fflush(stdin);
	printf("Please enter the third number: ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&num3);
	if(num1>num2 && num1>num3)
		printf("%.2f is the largest",num1);//.2f to print 2 decimal places like output
	else if(num2>num1&&num2>num3)
		printf("%.2f is the largest",num2);
	else if(num3>num1&&num3>num2)
		printf("%.2f is the largest",num3);
}

