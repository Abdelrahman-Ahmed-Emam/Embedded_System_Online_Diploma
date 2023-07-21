///*
// ============================================================================
// Name        : Pointers.c
// Author      : Abdo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
// ============================================================================
// */
//
//#include <stdio.h>
//#include <stdlib.h>
//
//int main(void)
//{
//	unsigned int m=0;// integer m
//	m=29;// assign 29 to variable m
//	printf("Address of m: 0x%p\n",&m);
//	fflush(stdout);fflush(stdin);
//	printf("Value of m: %d\n",m);
//	fflush(stdout);fflush(stdin);
//	unsigned int* ab=&m;// ab is a pointer to integer which contain address m
//	printf("Now ab is assigned with address of m.\n");
//	fflush(stdout);fflush(stdin);
//	printf("Address of pointer ab is pointing to : 0x%p\n",ab);
//	fflush(stdout);fflush(stdin);
//	printf("Content of ab: %d\n",*ab);
//	fflush(stdout);fflush(stdin);
//	m=34;
//	printf("The value m assigned to %d now\n",m);
//	fflush(stdout);fflush(stdin);
//	printf("Address of pointer ab it's self 0x%p [should be different"
//			" as address of the pointer its self not the address stored]\n",&ab);
//	fflush(stdout);fflush(stdin);
//	printf("Content of pointer ab: %d\n",*ab);
//	fflush(stdout);fflush(stdin);
//	*ab=7;
//	printf("The variable ab is assigned with the value %d now\n",*ab);
//	fflush(stdout);fflush(stdin);
//	printf("Address of m : 0x%p\n",ab);
//	fflush(stdout);fflush(stdin);
//	printf("Value of m is %d\n",m);
//	return 0;
//}
