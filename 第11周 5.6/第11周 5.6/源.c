#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
int m, n;//m为餐桌号，n为菜编号
int* pm = &m;
int* pn = &n;
int print()
{
	printf("\n请点菜\n宫保鸡丁--1\n清炒油菜--2\n可口可乐--3\n");
	printf("请输入要点菜的编号：");
}
int get_switch()
{
	scanf("%d", &n);
	switch (*pn)
	{
	case 1:
		printf("\n餐桌号: %d，  ", *pm);  printf("已点菜：宫保鸡丁\n");
		break;
	case 2:
		printf("\n餐桌号: %d，  ", *pm); printf("已点菜：清炒油菜\n");
		break;
	case 3:
		printf("\n餐桌号: %d，  ", *pm); printf("已点菜：可口可乐\n");
	}
}

int main()
{
	do
	{
		printf("请输入您所在的餐桌号:");
		scanf("%d", &m);
		print();
		get_switch();
		printf("\n");
	} while (1);
		return 0;
}
