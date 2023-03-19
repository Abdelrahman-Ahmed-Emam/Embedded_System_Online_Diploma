/*
 * EX5.c
 *
 *  Created on: 19 Mar 2023
 *      Author: HP
 */

#include<stdio.h>
void main()
{
	char input='0';
	printf("Please enter a character: ");
	fflush(stdout);fflush(stdin);
	scanf("%c",&input);
	if((input>=65 && input<=90)|| (input>=97 && input<=122))//ASCII code if((input>='A' && input<='Z')||
		//(input>='a' && input<='z'))
			printf("%c is an alphabet",input);
	else
		printf("%c is not a alphabet",input);

}
