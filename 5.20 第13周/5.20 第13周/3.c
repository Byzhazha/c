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
	char Number[10];  //ѧ��
	char Name;   //����
	struct subject score;       //�����Ŀ
};

int main()
{
	int i, n;
	scanf("%d", &n);          //n��ѧ��
	struct information student[50];   //��಻����50��ѧ��
	for (i = 0; i < n; i++)
	{
		scanf("%s,%c,%f,%f,%f,%f,%f",
			&student[i].Number,
			student[i].Name,
			&student[i].score.English,
			&student[i].score.Math,
			&student[i].score.Philosophy,
			&student[i].score.Computer,
			&student[i].score.Electronic);  //����

		printf("%s%c%f%f%f%f%f\n",
			student[i].Number,
			student[i].Name,
			student[i].score.English,
			student[i].score.Math,
			student[i].score.Philosophy,
			student[i].score.Computer,
			student[i].score.Electronic);  //���
	}
	return 0;
}