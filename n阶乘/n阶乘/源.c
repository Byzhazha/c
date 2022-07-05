
#include<stdio.h>
int main()
{
	int i = 1;
	int a = 1;
	int n = 0;
	int sum = 1;
	scanf("%d",&n);
	for (i = 1; i <= n; i++)
	{
		sum = sum * i;
	}
	printf("%d", sum);
}
 