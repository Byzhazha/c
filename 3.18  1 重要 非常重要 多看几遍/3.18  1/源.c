#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
int main()
{
	double sv; //sales volume  ���۶�
	double sum1,sum2,sum,sum3;//���1  ���2  �����
	double bs=10000; //Base salary10000Ԫ��н
	scanf("%lf",&sv);
	if (sv>=0&&sv <= 10000)
	{
		sum = sv * 0.1;
		printf("sum is %lf ",sum);
	}
	else
		if (sv > 10000 && sv <= 20000)
		{
			sum1 = bs * 0.075;
			sum2 = (sv - bs) * 0.1;
			sum = sum1 + sum2;
			printf("sum is %lf", sum);
		}
		else if (sv > 20000)
		{

			sum1 = bs * 0.075;
			sum2 = bs * 0.1;
			sum3 = (sv - 20000) * 0.05;
			sum = sum1 + sum2 + sum3;
			printf("�������Ϊ�� %.3lf\n", sum);
	}
	system("pause");
}