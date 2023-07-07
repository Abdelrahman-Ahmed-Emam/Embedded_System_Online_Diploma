///*
// * EX2.c
// *
// *  Created on: 7 Jul 2023
// *      Author: HP
// */
//#include<stdio.h>
//struct Sdistance
//{
//	float feet;
//	float inch;
//};
//struct Sdistance add(struct Sdistance a[],int size)
//{
//	struct Sdistance sum={0};
//	int i=0;
//	for(;i<size;i++)
//	{
//		sum.feet+=a[i].feet;
//		sum.inch+=a[i].inch;
//		if(sum.inch>12)
//		{
//			sum.inch-=12;
//			sum.feet++;
//		}
//	}
//	return sum;
//}
//int main(void)
//{
//	struct Sdistance Distances[2]={0};
//	int i=0;
//	for(;i<2;i++)
//	{
//		printf("Enter data for Distance %d\n",i+1);
//		printf("Enter feet: ");
//		fflush(stdout);fflush(stdin);
//		scanf("%f",&Distances[i].feet);
//		fflush(stdout);fflush(stdin);
//		printf("Enter inch: ");
//		fflush(stdout);fflush(stdin);
//		scanf("%f",&Distances[i].inch);
//	}
//	struct Sdistance sum=add(Distances,sizeof(Distances)/sizeof(Distances[0]));
//	printf("Sum of distance : %.3f feet - %.3f inch",sum.feet,sum.inch);
//
//	return 0;
//}
//
