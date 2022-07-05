#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
int main()
{
	int arr[10];
	int i = 0;
		for (i = 0; i <=9; i++)
		{
			scanf("%d", &arr[i]);
		}
		
	for(i=0;i<=9;i++)
	printf("%d,",arr[i]);
	return 0;
}