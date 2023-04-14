///*
// * EX4.c
// *
// *  Created on: 14 Apr 2023
// *      Author: HP
// */
//
//
//#include<stdio.h>
//#include<stdlib.h>
//int main (void)
//{
//	float arr[40]={0};
//	int Nelements=0;
//	int location=0;
//	printf("Enter number of elements : ");
//	fflush(stdout);fflush(stdin);
//	scanf("%d",&Nelements);
//	int i=0;
//	for(i=0;i<Nelements;i++)
//	{
//		printf("Enter element %d] : ",i+1);
//		fflush(stdout);fflush(stdin);
//		scanf("%f",&arr[i]);
//	}
//	for(i=0;i<Nelements;i++)
//			{
//				printf("%.2f \t",arr[i]);
//
//			}
//
//	printf("\nEnter element to be inserted : ");
//	fflush(stdout);fflush(stdin);
//	scanf("%f",&arr[i]);
//	fflush(stdout);fflush(stdin);
//	printf("Enter the location : ");
//	fflush(stdout);fflush(stdin);
//	scanf("%d",&location);
//	arr[location-1]-=arr[i];
//	arr[i]+=arr[location-1];
//	arr[location-1]=arr[i]-arr[location-1];
//	Nelements++;
//	for(i=0;i<Nelements;i++)
//		{
//		printf("%.2f \t",arr[i]);
//
//		}
//	return 0;
//}
