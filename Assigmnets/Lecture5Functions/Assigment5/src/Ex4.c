/*
 * Ex4.c
 *
 *  Created on: 26 Jun 2023
 *      Author: HP
 */

#include<stdio.h>
int Power(int Number,int power)
{
	if(power==1)
		return Number;
	else
		return Number*Power(Number,power-1);
}
int main()
{
	int Number=0,power=0;
    printf("Please enter the Number : ");
    fflush(stdout);fflush(stdin);
    scanf("%d",&Number);
    printf("Please enter the Power : ");
       fflush(stdout);fflush(stdin);
       scanf("%d",&power);
       printf("%d ^ %d = %d ",Number,power, Power(Number,power));

	return 0;
}
