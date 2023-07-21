/*
 * EX5.c
 *
 *  Created on: 21 Jul 2023
 *      Author: HP
 */

#include<stdio.h>
struct STest
{
	char name[50];
	int ID;
};
int main(void)
{
	struct STest emp1={"Joe",123},emp2={"Alex",1002},emp3={"Abdo",1209};;
	struct STest (*arr[])={&emp1,&emp2,&emp3};
	struct STest (*(*parr)[3])=(arr);
    printf("Employee name : %s\n",(*(*parr+1))->name);
    printf("Employee ID : %d\n",(*(*parr+1))->ID);



	return 0;
}
