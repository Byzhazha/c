#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
int main ()
{
	int a = 1;
	int sum=0;
	while (a <= 100)
	{
		sum = sum + a;
		a++;
	}
	printf("%d",sum);
	system("pause");
}
