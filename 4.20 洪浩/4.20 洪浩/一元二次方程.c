#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
#include<math.h>
main()
{

	float a, b, c, he, x1, x2=0;
	scanf("%f%f%f", &a, &b, &c);
	he = (b * b) - (4 * a * c);
	if (he >= 0)
	{
		x1 = (-b + sqrt(he)) / (2 * a);
		x2 = (-b - sqrt(he)) / (2 * a);
		printf("x1=%.2f x2=%.2f\n", x1, x2);
	}
	else
	{
		he = sqrt(he * -1);
		float q;
		q = -b / (2 * a);
		printf("q=%.2f\n", q);
		x1 = he / (2 * a);
		x2 = -he / (2 * a);
		printf("x1=%.2f+%.2fi x2=%.2f%.2fi\n", q, x1, q, x2);

	}
}