///*
// * Q6.c
// *
// *  Created on: 1 Jul 2023
// *      Author: HP
// */
//
//#include<stdio.h>
//int Unique(int arr[],int size)
//{
//	if(arr[0]!=arr[1])
//		{
//			return arr[0];
//		}
//	if(arr[size-1]!=arr[size-2])
//		return arr[size-1];
//	int check=0;
//	int i=1;
//	for(;i<size-1;i++)
//	{
//		if(arr[i-1]==arr[i]|| arr[i+1]==arr[i])
//			check=0;
//		else
//			{
//				check=1;
//			}
//		if(check==1)
//			return arr[i];
//	}
//	return 0;
//}
//void Sort(int arr[],int size)
//{
//	int i=0;
//	for(;i<size;i++)
//	{   int j=i+1;
//		for(;j<size;j++)
//		{
//			if(arr[i]>arr[j])
//			{
//				int temp;
//				temp=arr[j];
//				arr[j]=arr[i];
//				arr[i]=temp;
//			}
//		}
//
//	}
//}
//int main()
//{
//	int arr[]={4,2,5,2,5,7,4};
//	Sort(arr,sizeof(arr)/4);
//	printf("%d",Unique(arr,sizeof(arr)/4));
//
//}
