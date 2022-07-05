#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
int flag(int n)
{
	if ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0))
		return 1;
	else
		return 0;
}
int main()
{
	int year, month, day;
	scanf("%d%d%d", &year, &month, &day);


}