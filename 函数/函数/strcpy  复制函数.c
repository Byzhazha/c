#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
#include<string.h>
int main()
{
	char arr1[20];
	char arr2[]="共产主义万岁！";
	strcpy(arr1,arr2);
	printf("%s", arr1);
	return 0;
}