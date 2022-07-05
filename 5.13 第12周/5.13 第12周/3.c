#define _CRT_SECURE_NO_WARNINGS	
#include<stdlib.h>
#include<stdio.h>
int max123(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    int a, b;
    int max123(int a, int b);
    printf("请输入两个整数\n");
    scanf("%d%d", &a, &b);
    printf("max=%d\n", max123(a, b));
    return 0;
}