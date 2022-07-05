#define _CRT_SECURE_NO_WARNINGS	
#include <stdio.h>
int main()
{
	int i, n, s;
	s = 0;
	int fact(int n);

	printf("%d\n", s);
	return 0;
}
int fact(int n)
{
	int i, n, s;
	s = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		s += i;
	}
	return (s);
}