#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
int main()
{
	printf("������500�����֣�");
	int arr[500], b = 0;
	int zero = 0;
	int p = 0, n = 0;//Positive number����  negative ����
	for (b = 0; b <500; b++)
		scanf("%d", &arr[b]);
	printf("\n");
	for (b = 0; b <500; b++)
	{

		if (arr[b] < 0)
			n++;
	}
	printf("����:%d��\n",n);
}