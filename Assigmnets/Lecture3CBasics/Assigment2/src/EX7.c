/*
 * EX7.c
 *
 *  Created on: 19 Mar 2023
 *      Author: HP
 */
#include<stdio.h>
void main()
{
	int num=0,product=1;

	printf("Please enter an integer:");
	fflush(stdout);fflush(stdin);
	scanf("%d",&num);
	if(num<0)
		printf("Error!!! Factorial of negative number does not exist");
	else if(num==0)
		printf("Factorial = 1");
	else
	{
		int i=1;
		for(;i<=num;i++)
			product*=i;
		printf("Factorial = %d",product);
	}
}

