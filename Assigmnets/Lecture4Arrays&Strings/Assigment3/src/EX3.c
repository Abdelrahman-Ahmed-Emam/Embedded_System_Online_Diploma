///*
// * EX3.c
// *
// *  Created on: 14 Apr 2023
// *      Author: HP
// */
//
//#include<stdio.h>
//#include<stdlib.h>
//int main(void)
//{
//	float matrix[100][100]={0};
//	float transpose[100][100]={0};
//	int rows,columns=0;
//	do
//	{
//		printf("Enter rows of matrix (between 1 and 100) : ");
//		fflush(stdout);fflush(stdin);
//		scanf("%d",&rows);
//		fflush(stdout);fflush(stdin);
//		printf("Enter columns of the matrix (between 1 and 100) : ");
//		fflush(stdout);fflush(stdin);
//		scanf("%d",&columns);
//
//	}while(columns <=0 && rows <=0);
//	int i=0;
//	int j=0;
//	for(i=0;i<rows;i++)
//		{
//			for(j=0;j<columns;j++)
//			{
//				printf("Enter element of matrix [%d][%d] : ",i+1,j+1);
//				fflush(stdout);fflush(stdin);
//				scanf("%f",&matrix[i][j]);
//			}
//
//		}
//	printf("Matrix entered : \n");
//	for(i=0;i<rows;i++)
//			{
//				for(j=0;j<columns;j++)
//				{
//					printf("%.2f\t",matrix[i][j]);
//				}
//				printf("\n");
//			}
//	printf("Matrix Transpose : \n");
//	for(i=0;i<columns;i++)
//	{
//		for(j=0;j<rows;j++)
//		{
//			transpose[i][j]=matrix[j][i];
//			printf("%.2f\t",transpose[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
