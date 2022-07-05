#define _CRT_SECURE_NO_WARNINGS	
#include <stdio.h>
int main()
{
	int i, n, sum;
	sum = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		sum += i;
	}
	printf("%d\n", sum);
	return 0;
}