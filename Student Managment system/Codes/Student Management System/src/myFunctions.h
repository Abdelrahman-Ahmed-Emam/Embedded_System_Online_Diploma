/*
 * myFunctions.h
 *
 *  Created on: Jul 31, 2024
 *      Author: abdel
 */

#ifndef MYFUNCTIONS_H_
#define MYFUNCTIONS_H_

#include "stdio.h"
/* due to eclipse bug thats help with printf but do not forget to add brackets in if conditions*/
#define _PRINTF(...) fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdout)

/* due to eclipse bug thats help with scanf but do not forget to add brackets in if conditions*/
#define _SCANF(...) fflush(stdin);\
		scanf(__VA_ARGS__);\
		fflush(stdin)

extern void printArray(int array[],int size);/*print elements in the array until reaching -1 or reaching size*/
extern void fillArray(int array[],int size);/*we fill the array until we add -1 or reaching max size */
extern void myStrCpy(char *source,char *destination);/*copy string from source to destination*/
extern void arrcpy(int *source ,int *destination,int size);/*copy data from an array to another*/
extern int myStrCmp(char *string1,char *string2);/*Compare between two strings return 0 if equal return 1 if string1 is bigger return -1 if string2 is bigger*/
extern int myAtoi(char*source);/*Change a string to integer numbers*/
extern float myAtof(char *source);/*Change a string to float numbers*/
#endif /* MYFUNCTIONS_H_ */
