#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
int m, n;//mΪ�����ţ�nΪ�˱��
int* pm = &m;
int* pn = &n;
int print()
{
	printf("\n����\n��������--1\n�峴�Ͳ�--2\n�ɿڿ���--3\n");
	printf("������Ҫ��˵ı�ţ�");
}
int get_switch()
{
	scanf("%d", &n);
	switch (*pn)
	{
	case 1:
		printf("\n������: %d��  ", *pm);  printf("�ѵ�ˣ���������\n");
		break;
	case 2:
		printf("\n������: %d��  ", *pm); printf("�ѵ�ˣ��峴�Ͳ�\n");
		break;
	case 3:
		printf("\n������: %d��  ", *pm); printf("�ѵ�ˣ��ɿڿ���\n");
	}
}

int main()
{
	do
	{
		printf("�����������ڵĲ�����:");
		scanf("%d", &m);
		print();
		get_switch();
		printf("\n");
	} while (1);
		return 0;
}
