/*
 ============================================================================
 Name        : Assigment2.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int number=0;
	printf("Please enter a number : ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&number);
	fflush(stdout);fflush(stdin);
	if(number%2==0)
		printf("%d is even",number);
	else
		printf("%d is odd",number);
	return 0;
}
