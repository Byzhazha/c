#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	if (n % 3 == 0 && n % 5 == 0)
		printf("YES/n");
	else
		printf("No/n");
	return 0;
}