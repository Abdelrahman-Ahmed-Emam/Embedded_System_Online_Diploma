/*
 * Q10.c
 *
 *  Created on: 1 Jul 2023
 *      Author: HP
 */
#include<stdio.h>
int HowManyOne(int Number)
{	int count=0;
	int max=0;
	while(Number!=0)
	{
		if(Number%2==1)
			count++;
		Number/=2;
		if(Number%2==0)
		{
			if(max<count)
			{
				max=count;
				count=0;
			}
		}

	}
	return max;
}
int main()
{
	int Number=0;
	printf("Please enter a number: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&Number);
	fflush(stdout);fflush(stdin);
	printf("%d",HowManyOne(Number));
}
