#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
int main()
{
	int max(int x, int y,int t);
	int a, b, c, d;
	scanf("%d%d%d", &a, &b, &c);
	int num1 = a + b;
	int num2 = b + c;
	int num3 = a + c;
	d = max(num1, num2,num3);
	printf("max=%d\n", d);
	return 0;
}
int max(int x, int y, int t)
{
	int z;
	if (x > y && x > t)z = x;
	else z = t;
	return (z);
}
