/*
 * EX5.c
 *
 *  Created on: 17 Mar 2023
 *      Author: HP
 */
#include<stdio.h>
#include<stdlib.h>
void main()
{
	char a=0;
	printf("##########Console-output###\nEnter a character: ");
	fflush(stdout);fflush(stdin);
	scanf("%c",&a);
	fflush(stdout);fflush(stdin);
	printf("ASCII value of %c = %d",a,a);
}

