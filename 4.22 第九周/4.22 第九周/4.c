#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
int main()//��������
{
	int max(int x, int y);//�������� ��������
	int a, b, c;
	scanf("%d,%d",&a,&b);
	c = max(a, b);
	printf("max=%d\n",c);
	return 0;
}
int max(int x, int y)//�����ײ�
{
	int z;                  //����ԭ��1
	if (x > y)z = x;		//2
	else z = y;				//3
	return (z);				//4
}