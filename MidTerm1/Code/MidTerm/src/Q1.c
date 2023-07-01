//
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int Method1(char arr[],int size)
//{
//	int i=0;
//	int number=0;
//	for(;i<size;i++)
//	{
//		number+=arr[i]-'0';
//	}
//	return number;
//}
//
//int Method2(int number)
//{
//	int result=0;
//	while (number!=0)
//	{
//		result+=number%10;
//		number/=10;
//	}
//	return result;
//}
//int main()
//{
//	char arr[100];
//	int number=0;
//	printf("Please enter the number : ");
//	fflush(stdout);fflush(stdin);
//	gets(arr);
//	number=atoi(arr);
//	printf("Method 1 results : %d\n",Method1(arr,strlen(arr)));
//	fflush(stdout);fflush(stdin);
//	printf("Method 2 results : %d\n",Method2(number));
//	return 0;
//}
