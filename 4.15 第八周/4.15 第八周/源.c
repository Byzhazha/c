#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
#include<stdio.h>
int main()
{
    float  arr[2][3];
    int b, h;
    float c = 1;
    do
    {
        printf("请输入水池长宽高：\n");
        for (h = 0; h < 2; h++)
        {
            for (b = 0; b < 3; b++)
                scanf("%f", &arr[h][b]);
        }
        for (h = 0; h < 2; h++)
        {
            for (b = 0; b < 3; b++)
                c *= arr[h][b];
            printf("蓄水量：%f\n", c);
            c = 1;
        }

    } while (1);
}

