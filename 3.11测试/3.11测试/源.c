#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
int main()
{
	do {

		printf("��������εĳ���\n");
		double a;
		scanf("%lf", &a);
		printf("��������εĿ�\n");
		double b;
		scanf("%lf", &b);
		double c = a * b;
		printf("���ε����Ϊ��%lf\n", c);
	} while (1);
	return 0;

}

