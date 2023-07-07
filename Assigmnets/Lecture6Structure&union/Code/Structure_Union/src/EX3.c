///*
// * EX3.c
// *
// *  Created on: 7 Jul 2023
// *      Author: HP
// */
//#include<stdio.h>
//struct Scomplex
//{
//	float real;
//	float imag;
//};
//struct Scomplex add(struct Scomplex a[],int size)
//{
//	struct Scomplex sum={0};
//	int i=0;
//	for(;i<size;i++)
//	{
//		sum.real+=a[i].real;
//		sum.imag+=a[i].imag;
//	}
//	return sum;
//}
//int main(void)
//{
//	struct Scomplex Complex[2]={0};
//	int i=0;
//	for(;i<2;i++)
//	{
//		printf("Enter Complex number %d\n",i+1);
//		printf("Enter real: ");
//		fflush(stdout);fflush(stdin);
//		scanf("%f",&Complex[i].real);
//		fflush(stdout);fflush(stdin);
//		printf("Enter imaginary: ");
//		fflush(stdout);fflush(stdin);
//		scanf("%f",&Complex[i].imag);
//	}
//	struct Scomplex sum=add(Complex,sizeof(Complex)/sizeof(Complex[0]));
//	printf("Sum= %.2f + %.2fi",sum.real,sum.imag);
//
//	return 0;
//}
//
