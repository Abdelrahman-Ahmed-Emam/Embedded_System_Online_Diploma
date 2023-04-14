/*
 * EX3.c
 *
 *  Created on: 15 Apr 2023
 *      Author: HP
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
	char string[100]={0};
	char string1[100]={0};
	printf("Enter a string: ");
	fflush(stdout);fflush(stdin);
	gets(string);
	int i=0;
	for(i=0;i<strlen(string);i++)
	{
		string1[i]=string[strlen(string)-1-i];
	}
	printf("Reverse string is %s",string1);

	return 0;
}

