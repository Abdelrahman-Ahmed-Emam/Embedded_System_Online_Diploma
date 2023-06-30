/*
 * Q8.c
 *
 *  Created on: 30 Jun 2023
 *      Author: HP
 */
#include<stdio.h>
int Last(int arr[7],int search,int size)
{
	int i=0;
	int place=-1;
	for(;i<size;i++)
	{
		if(arr[i]==search)
			place=i;
	}
	return place;
}
int main(void)
{	int arr[]={1,2,3,4,5,6,4};
printf("%d",Last(arr,4,sizeof(arr)/4));
	return 0;
}

