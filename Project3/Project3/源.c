#define _CRT_SECURE_NO_WARNINGS	
#define _CRT_SECURE_NO_WARNINGS	
/*****************************************************************************************
*下面为一个基于C语言的学生健康体检档案管理系统设计，程序可实现的功能有记录的基本信息包括 *
*学生的学号、姓名、出生日期、系别、性别、体检日期、身高、体重、肺活量、健康评价，可通过  *
*菜单进行系统功能选择，录入基本信息，修改录入过的信息，修改和删除指定学号的记录，实现信息*
*的浏览功能按体检日期进行查询，按身高排序.												 *
*******************************************************************************************/
#include<stdio.h>/*I/O函数*/
#include<string.h>/*字符串函数*/
#include<stdlib.h>/*标准库函数*/

#define M 50 //成员上限


/*定义数据结构*/
typedef struct//定义Info结构体
{
	char  id[20];//学号
	char name[20];//姓名
	char birth[20];//出生日期
	char department[20];//系别
	char sex[20];//性别(男or女)
	char date[20];//体检日期(形式如20220621)
	char weight[20];//体重
	char pulmonary[20];//肺活量
	char health[20];//健康评价
	int height;//身高为整型 
}Info;

Info member[M];    //定义结构体数组
int num = 0;    //当前成员数


/*函数声明列表*/
void mainface();//信息管理员界面
void Input_Info(Info* p);//输入记录 
void Info_Rebuild();//新建信息 
void Info_Add();//添加信息 
void Info_Dele();//删除信息 
void Delete(char id[]);//删除函数， Info_Dele()复用 
void Info_Change();//修改信息 
void Info_Show();//浏览信息 
void Info_Find();//查询信息 
void bubbleSort();//冒泡法 
void Info_Sort();//bubbleSort()函数复用，并输出排序结果 
void Info_Export();//导出信息至文件 


//信息管理员界面（主菜单） 
void mainface()
{
	printf("            请选择您的操作\n");
	printf("            1       录入信息\n");
	printf("            2       增加信息\n");
	printf("            3       删除信息\n");
	printf("            4       修改信息\n");
	printf("            5       浏览信息\n");
	printf("            6       查询信息\n");
	printf("            7       排序	\n");
	printf("            8       导出信息\n");
	printf("            9       退出系统\n");
}


//输入信息
void Input_Info(Info* p)//Input_Info()函数，将下面所输入的信息存入相应的地址 
{
	printf("请输入学号\n");
	scanf("%s", &p->id);//将输入的信息存入id对应的结构体中 
	printf("请输入姓名\n");
	scanf("%s", &p->name);
	printf("请输入出生日期\n");
	scanf("%s", &p->birth);
	printf("请输入系别\n");
	scanf("%s", &p->department);
	printf("请输入性别(男or女)\n");
	scanf("%s", &p->sex);
	printf("请输入体检日期(形式如20220621)\n");
	scanf("%s", &p->date);
	printf("请输入身高\n");
	scanf("%d", &p->height);
	printf("请输入体重\n");
	scanf("%s", &p->weight);
	printf("请输入肺活量\n");
	scanf("%s", &p->pulmonary);
	printf("请输入健康评价\n");
	scanf("%s", &p->health);
}

//当没有存入信息时建立信息库
void Info_Rebuild()
{
	printf("---------------建信息库--------------\n");
	char aa;//aa是字符类型 
	int i = 0;//i为整型且值为0 
	for (i = 0; i < M; i++)//输入信息 
	{
		Input_Info(&member[i]);//调用 Input_Info()函数 
		printf("录入成功！\n");
		num++;
		if (i == M - 1) {//判断是否输入人员信息超过五十，若超过提示“成员已满！将返回主菜单” 
			printf("成员已满！将返回主菜单\n");
			system("pause");
			break;
		}
		aa = getchar();
		printf("回车继续录入，若输入'0'可返回菜单\n");
		aa = getchar();
		if (aa == '0') {//返回菜单 
			system("cls");
			break;
		}
	}
}

//增加信息
void Info_Add()
{
	char aa;//aa是字符类型 
	while (1)//无限循环，条件为1 
	{
		if (num == 0)//条件为num==0 ，当管理系统中没有输入人员信息的时候执行if语句 
		{
			printf("您的信息现在是空的，请增加信息\n按回车键返回主程序\n");
			getchar();//吸收回车
			getchar();
			system("cls");//清屏
			break;
		}
		Input_Info(&member[num]);//增加信息， Input_Info()函数 
		printf("录入成功！\n");
		num++;
		aa = getchar();
		printf("回车继续录入，若输入'0'可返回菜单\n");
		aa = getchar();
		if (aa == '0')//返回菜单 
		{
			system("cls");
			break;
		}
	}
}



//删除信息
void Info_Dele()
{
	printf("---------------- 删除信息----------------\n");
	char id[20];//学号为字符数组 
	printf("请输入要删除的id：");
	scanf("%s", &id);
	Delete(id);//调用删除函数
}



//删除函数
void Delete(char id[])
{
	int i = 0;//i为整型且值为0 
	for (i = 0; i < num; i++)//可删除信息必须小于输入的人数 
	{
		if (i == num - 1)//若最后一个元素待删除
		{
			printf("删除成功！\n");
			num--;//删除后人数减一 
			return;
		}
		else if (strcmp(member[i].id, id) == 0)//非最后一个元素待删除，strcmp为字符串比较函数，通过ASCII码比较字符串，查看是否是存储过的id 
		{
			int j = i;//令j=i，且都为整型 
			for (j = i; j < num - 1; j++)//将结构中的学生信息向前移动一位 
			{
				member[j] = member[j + 1];
			}
			printf("删除成功！\n");
			num--;//删除后人数减一 
			return;
		}
	}
	printf("找不到要删除的id.\n");
}



//修改信息
void Info_Change()
{
	printf("---------------修改信息---------------\n");
	char id[20];//学号为字符数组 
	printf("请输入要修改的id：");
	scanf("%s", &id);
	char aa;
	while (1)//无限循环，遍历数组寻找待修改结点
	{
		if (num == 0)//查询是有过输入的信息 
		{
			printf("未找到该id\n按回车键返回主程序\n");
			getchar();
			getchar();
			system("cls");
			break;
		}
		int i = 0;
		for (i = 0; i < num; i++)
		{
			if (strcmp(member[i].id, id) == 0)//比较输入的学号是否与以存储的学号相同 
			{
				Input_Info(&member[i]);//为该成员输入信息
				printf("修改成功\n");
				return;
			}
		}
	}
}

//展示信息
void Info_Show()
{
	printf("信息如下：\n");
	if (num == 0)
	{
		printf("暂无信息，快去添加信息吧\n按回车键返回\n");
		getchar();
		system("cls");
	}
	else {
		int i = 0;
		for (i = 0; i < num; i++)//将每一个成员数据打印出来
		{
			printf("id：%s\t", member[i].id);//每条信息之间空八个格 
			printf("名字：%s\t", member[i].name);
			printf("出生日期：%s\t", member[i].birth);
			printf("系别：%s\t", member[i].department);
			printf("性别：%s\t", member[i].sex);
			printf("体检日期：%s\t", member[i].date);
			printf("身高：%d\t", member[i].height);
			printf("体重：%s\t", member[i].weight);
			printf("肺活量：%s\t", member[i].pulmonary);
			printf("健康评价：%s\t\n", member[i].health);
		}
	}
}

//查询信息
void Info_Find()
{
	printf("输入日期\n");
	char date[20];//体检日期类型为字符数组 
	scanf("%s", &date);//输入日期 
	printf("当天信息如下：\n");
	if (num == 0)//当未输入过信息时输出 暂无信息，快去添加信息吧
	{
		printf("暂无信息，快去添加信息吧\n按回车键返回\n");
		getchar();
		getchar();
		system("cls");
	}
	else {//当有输入记录时 
		int i = 0;
		for (i = 0; i < num; i++)// 遍历数组
		{
			if (strcmp(member[i].date, date) == 0)//找到日期相符的结点
			{
				printf("id：%s\t", member[i].id);
				printf("名字：%s\t", member[i].name);
				printf("出生日期：%s\t", member[i].birth);
				printf("系别：%s\t", member[i].department);
				printf("性别：%s\t", member[i].sex);
				printf("体检日期：%s\t", member[i].date);
				printf("身高：%d\t", member[i].height);
				printf("体重：%s\t", member[i].weight);
				printf("肺活量：%s\t", member[i].pulmonary);
				printf("健康评价：%s\t\n", member[i].health);
			}
		}
	}
}

//链表冒泡排序（从小到大排）
void bubbleSort() {
	int i = -1;
	int j = 0;
	int tail = num;
	while (i + 1 != tail) {
		i = -1;
		j = 0;
		Info t;//t为一个临时结构体，用来储存信息 
		while (j + 1 != tail) {
			if (member[j].height > member[j + 1].height) //若要从大到小排请把>改为<
			{
				t = member[j];//将 member[j]里的信息存储到t内，此时member[j]内为空 
				member[j] = member[j + 1];//给member[j]赋member[j + 1]内的值 
				member[j + 1] = t;//t的值赋给 member[j + 1]
			}
			else
				j++;
			i++;
		}
		tail = j;
	}
}

//信息排序并输出排序后的值，调用 bubbleSort()和 Info_Show()函数 
void Info_Sort()
{
	bubbleSort();//调用排序函数
	Info_Show();//展示排序后的数据
}

//导出信息至文件（ infomation.txt） 
void Info_Export()
{
	Info* p;
	FILE* fp = fopen("infomation.txt", "w");//打开只写文件
	int i = 0;
	for (i = 0; i < num; i++)
	{
		fprintf(fp, "学号:%s,姓名:%s,出生日期:%s,系别:%s,性别:%s,体检日期:%s,身高:%d,体重:%s,肺活量:%s,健康评价:%s\n",
			member[i].id, member[i].name, member[i].birth, member[i].department, member[i].sex, member[i].date, member[i].height,
			member[i].weight, member[i].pulmonary, member[i].health);//向文件内存储信息 
	}
	fclose(fp);//关闭文件 
}

int main()
{
	while (1) { //无限循环 
		mainface();//mainface()函数 
		int a, flag = 0; //定义a，flag为整型 
		scanf("%d", &a);//输入一个数存到地址a里面 
		switch (a) {//switch() 语句 
		case 1://录入信息
			system("cls");//清屏 
			Info_Rebuild();//Info_Rebuild()函数 
			system("cls"); break;
		case 2://添加信息
			system("cls");
			Info_Add();
			system("cls"); break;
		case 3://删除信息
			system("cls");
			Info_Dele();
			system("pause"); system("cls"); break;
		case 4://修改信息
			system("cls");
			Info_Change();
			system("pause"); system("cls"); break;
		case 5://浏览信息
			system("cls");
			Info_Show();
			system("pause"); system("cls"); break;
		case 6://查询信息
			system("cls");
			Info_Find();
			system("pause"); system("cls"); break;
		case 7://身高排序
			system("cls");
			Info_Sort();
			system("pause"); system("cls"); break;
		case 8://导出信息
			system("cls");
			Info_Export();
			system("pause"); system("cls"); break;
		default: flag = 1; break;//除了上面输入的数字以外 执行此语句 
		}
		if (flag)break;//当flag=1，即输入不为1至8的任意一个数时退出循环，程序结束
	}
	return 0;
}
