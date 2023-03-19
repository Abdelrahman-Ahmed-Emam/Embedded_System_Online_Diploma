/*
 * EX6.c
 *
 *  Created on: 19 Mar 2023
 *      Author: HP
 */
#include<stdio.h>
void main()
{
	unsigned int num=0,sum=0;

	printf("Please enter a number: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&num);
	int i=0;
	for(;i<=num;i++)
	{
		sum+=i;
	}
	printf("Sum is %d",sum);
}
