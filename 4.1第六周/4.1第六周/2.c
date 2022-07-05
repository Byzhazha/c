#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
int main()
{
	int i, m, arr[10];
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	m = arr[0];
	for (i = 1; i < 10; i++)
	{
		if (arr[i] >m)
		{
			m = arr[i];
		
		}
	}
	printf("最大数为：%d\n", m);

}
