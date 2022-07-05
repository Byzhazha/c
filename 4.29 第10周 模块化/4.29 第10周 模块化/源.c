#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int fact(int n);
int main()
{
    int fact(int n), n;
    scanf("%d", &n);
    printf("%d\n", fact(n));
    return 0;
}
int fact(int n)
{
    int i, m, s = 0;
    m = 1;
    for (i = 1; i <= n; i++)
    {
        m *= i;
        s += m;
    }
    return (s);
}