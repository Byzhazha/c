#define _CRT_SECURE_NO_WARNINGS	
#include<string.h>
#include<stdio.h>
struct subject
{
	float English;
	float Math;
	float Philosophy;
	float Computer;
	float Electronic;
};
struct information
{
	char Number[10];  //学号
	char Name;   //姓名
	struct subject score;       //五个科目
};

int main()
{
	int i, n;
	scanf("%d", &n);          //n个学生
	struct information student[50];   //最多不超过50个学生
	for (i = 0; i < n; i++)
	{
		scanf("%s,%c,%f,%f,%f,%f,%f",
			&student[i].Number,
			student[i].Name,
			&student[i].score.English,
			&student[i].score.Math,
			&student[i].score.Philosophy,
			&student[i].score.Computer,
			&student[i].score.Electronic);  //输入

		printf("%s%c%f%f%f%f%f\n",
			student[i].Number,
			student[i].Name,
			student[i].score.English,
			student[i].score.Math,
			student[i].score.Philosophy,
			student[i].score.Computer,
			student[i].score.Electronic);  //输出
	}
	return 0;
}