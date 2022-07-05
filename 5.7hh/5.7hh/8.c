#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	if (n > 0)
		printf("恭喜你，回答正确！\n");
	else
		printf("请重新输入！\n");

}