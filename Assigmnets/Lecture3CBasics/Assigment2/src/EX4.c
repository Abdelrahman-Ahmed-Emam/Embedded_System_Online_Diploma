/*
 * EX4.c
 *
 *  Created on: 19 Mar 2023
 *      Author: HP
 */
#include<stdio.h>
void main()
{
	float num=0;
	printf("Please enter a number : ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&num);
	if(num>0)
		printf("%.2f is positive",num);
	else if(num<0)
		printf("%.2f is negative",num);
	else
		printf("You have entered zero");
}

