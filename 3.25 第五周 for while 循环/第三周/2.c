#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
int main()
{
	int n ;
	double sum=0;
	for (n = 1; n=100; n++)
		if (n % 2 == 0)
			sum = sum-1;
		else
			sum = 1+sum;
	printf("sum is : %lf",sum);
	return 0;
	system("pause");
}