#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	double a, b, c;   //a=��� b=����  c=BMI
	a, b, c = 0;
	printf("������������ߣ�����λ���ף�\n");
	scanf("%lf",&a);
	printf("�������������أ�����λ��ǧ�ˣ�\n");
	scanf("%lf",&b);
	c = b/(a*a);
	printf("����BMIָ��Ϊ:%lf\n", c);
	return 0;
	system("pause");
}