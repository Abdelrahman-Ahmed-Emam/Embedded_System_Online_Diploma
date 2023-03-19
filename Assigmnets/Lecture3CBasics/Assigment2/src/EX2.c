/*
 * EX2.c
 *
 *  Created on: 19 Mar 2023
 *      Author: HP
 */
#include<stdio.h>
void main()
{
	char input=0;
	printf("Please enter an alphabet: ");
	fflush(stdout);fflush(stdin);
	scanf("%c",&input);
	if(input=='a'||input=='A'||input=='e'||input=='E'
			||input=='i'||input=='I'||input=='o'||input=='O'|| input=='u'||input=='U')
		printf("%c is a vowel",input);
	else
		printf("%c is a consonant",input);
}


