#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	double a, b, c;   //a=身高 b=体重  c=BMI
	a, b, c = 0;
	printf("请输入您的身高：（单位：米）\n");
	scanf("%lf",&a);
	printf("请输入您的体重：（单位：千克）\n");
	scanf("%lf",&b);
	c = b/(a*a);
	printf("您的BMI指数为:%lf\n", c);
	return 0;
	system("pause");
}