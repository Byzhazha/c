#define _CRT_SECURE_NO_WARNINGS	
#include "stdio.h"
#include <math.h>
main()
{
	int day = 0;
	do
	{ 
	scanf("%d",&day);
	switch (day)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("996\n");
		break;
	case 6:
	case 7:
		printf("Еїан\n");
		break;
	}
	} while (day == 2);
	return 0;
}