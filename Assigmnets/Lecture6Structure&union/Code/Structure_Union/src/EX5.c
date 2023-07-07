/*
 * EX5.c
 *
 *  Created on: 7 Jul 2023
 *      Author: HP
 */
#include<stdio.h>
#define pi 3.14
#define Area(r)(pi*r*r)
int main(void)
{
	float radius=0,area=0;
	printf("Enter radius : ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&radius);
	area=Area(radius);
	printf("Area is %.2f",area);
	return 0;

}

