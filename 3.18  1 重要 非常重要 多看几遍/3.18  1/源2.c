//#define _CRT_SECURE_NO_WARNINGS	
//#include<stdio.h>
//int  main()
//{
//	int a;
//	double sv; //sales volume  销售额
//	double sum1, sum2, sum, sum3, s;//提成1  提成2  总提成
//	double bs = 10000; //Base salary10000元底薪
//	scanf_s("%lf", &sv);
//	if (sv < 10000);
//	{sum1 = sv * 0.1;
//	a = 1;
//	}
//	if (sv > 10000 && sv <= 20000)
//	{
//		sum1 = bs * 0.075;
//		sum2 = (sv - bs) * 0.1;
//		sum = sum1 + sum2;
//		a = 2;
//	}
//	else if (sv > 20000)
//	{
//
//		sum1 = bs * 0.075;
//		sum2 = bs * 0.1;
//		sum3 = (sv - 20000) * 0.05;
//		s = sum1 + sum2 + sum3;
//		a = 3;
//	}
//	switch (a)
//	{
//	case 1:printf("提成为：%.3lf\n", sum1); break;
//	case 2:printf("提成为：%.3lf\n", sum); break;
//	case 3:printf("提成为：%.3lf\n", s); break;
//	}
//	return 0;
//}