#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
int main()
{
	
	printf("请输入矩形的长：\n");
	double a;
	scanf("%lf", &a);
	printf("请输入矩形的宽：\n");
	double b;
	scanf("%lf", &b);
	double c = a * b;
	prntf("矩形的面积为：%lf\n", c);
	return 0;

}
