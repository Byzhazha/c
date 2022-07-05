#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
int main()//主调函数
{
	int max(int x, int y);//被调函数 函数声明
	int a, b, c;
	scanf("%d,%d",&a,&b);
	c = max(a, b);
	printf("max=%d\n",c);
	return 0;
}
int max(int x, int y)//函数首部
{
	int z;                  //函数原型1
	if (x > y)z = x;		//2
	else z = y;				//3
	return (z);				//4
}