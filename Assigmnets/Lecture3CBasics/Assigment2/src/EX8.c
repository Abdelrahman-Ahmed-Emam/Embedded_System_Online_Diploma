/*
 * EX8.c
 *
 *  Created on: 19 Mar 2023
 *      Author: HP
 */
#include<stdio.h>
void main()
{
	char operator=0;
	float num1=0,num2=0,answer=0;
	printf("Please enter operator either + or - or * or / :");
	fflush(stdout);fflush(stdin);
	scanf("%c",&operator);
	fflush(stdout);fflush(stdin);
	printf("Enter first number: ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&num1);
	fflush(stdout);fflush(stdin);
	printf("Enter second number: ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&num2);
	switch(operator)
	{
	case '-':
		answer=num1-num2;
		break;
	case '+':
		answer=num1+num2;
		break;
	case '/':
		answer=num1/num2;
		break;
	case '*':
		answer=num1*num2;
		break;
	default:
		printf("Error operator %c has no match",operator);
		break;
	}
	printf("%.1f %c %.1f = %.1f",num1,operator,num2,answer);
}

