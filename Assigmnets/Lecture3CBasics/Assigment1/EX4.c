/*
 * EX4.c
 *
 *  Created on: 17 Mar 2023
 *      Author: HP
 */
#include<stdio.h>
#include<stdlib.h>
void main()
{
	float num1=0,num2=0;
	printf("##########Console-output###\nEnter first float number: ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&num1);
	fflush(stdout);fflush(stdin);
	printf("Enter second float number: ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&num2);
	fflush(stdout);fflush(stdin);
	printf("Product of the 2 floats %f",num1*num2);
}

