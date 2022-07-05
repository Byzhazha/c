#define _CRT_SECURE_NO_WARNINGS	
#define _CRT_SECURE_NO_WARNINGS	
/*****************************************************************************************
*����Ϊһ������C���Ե�ѧ��������쵵������ϵͳ��ƣ������ʵ�ֵĹ����м�¼�Ļ�����Ϣ���� *
*ѧ����ѧ�š��������������ڡ�ϵ���Ա�������ڡ���ߡ����ء��λ������������ۣ���ͨ��  *
*�˵�����ϵͳ����ѡ��¼�������Ϣ���޸�¼�������Ϣ���޸ĺ�ɾ��ָ��ѧ�ŵļ�¼��ʵ����Ϣ*
*��������ܰ�������ڽ��в�ѯ�����������.												 *
*******************************************************************************************/
#include<stdio.h>/*I/O����*/
#include<string.h>/*�ַ�������*/
#include<stdlib.h>/*��׼�⺯��*/

#define M 50 //��Ա����


/*�������ݽṹ*/
typedef struct//����Info�ṹ��
{
	char  id[20];//ѧ��
	char name[20];//����
	char birth[20];//��������
	char department[20];//ϵ��
	char sex[20];//�Ա�(��orŮ)
	char date[20];//�������(��ʽ��20220621)
	char weight[20];//����
	char pulmonary[20];//�λ���
	char health[20];//��������
	int height;//���Ϊ���� 
}Info;

Info member[M];    //����ṹ������
int num = 0;    //��ǰ��Ա��


/*���������б�*/
void mainface();//��Ϣ����Ա����
void Input_Info(Info* p);//�����¼ 
void Info_Rebuild();//�½���Ϣ 
void Info_Add();//�����Ϣ 
void Info_Dele();//ɾ����Ϣ 
void Delete(char id[]);//ɾ�������� Info_Dele()���� 
void Info_Change();//�޸���Ϣ 
void Info_Show();//�����Ϣ 
void Info_Find();//��ѯ��Ϣ 
void bubbleSort();//ð�ݷ� 
void Info_Sort();//bubbleSort()�������ã������������ 
void Info_Export();//������Ϣ���ļ� 


//��Ϣ����Ա���棨���˵��� 
void mainface()
{
	printf("            ��ѡ�����Ĳ���\n");
	printf("            1       ¼����Ϣ\n");
	printf("            2       ������Ϣ\n");
	printf("            3       ɾ����Ϣ\n");
	printf("            4       �޸���Ϣ\n");
	printf("            5       �����Ϣ\n");
	printf("            6       ��ѯ��Ϣ\n");
	printf("            7       ����	\n");
	printf("            8       ������Ϣ\n");
	printf("            9       �˳�ϵͳ\n");
}


//������Ϣ
void Input_Info(Info* p)//Input_Info()���������������������Ϣ������Ӧ�ĵ�ַ 
{
	printf("������ѧ��\n");
	scanf("%s", &p->id);//���������Ϣ����id��Ӧ�Ľṹ���� 
	printf("����������\n");
	scanf("%s", &p->name);
	printf("�������������\n");
	scanf("%s", &p->birth);
	printf("������ϵ��\n");
	scanf("%s", &p->department);
	printf("�������Ա�(��orŮ)\n");
	scanf("%s", &p->sex);
	printf("�������������(��ʽ��20220621)\n");
	scanf("%s", &p->date);
	printf("���������\n");
	scanf("%d", &p->height);
	printf("����������\n");
	scanf("%s", &p->weight);
	printf("������λ���\n");
	scanf("%s", &p->pulmonary);
	printf("�����뽡������\n");
	scanf("%s", &p->health);
}

//��û�д�����Ϣʱ������Ϣ��
void Info_Rebuild()
{
	printf("---------------����Ϣ��--------------\n");
	char aa;//aa���ַ����� 
	int i = 0;//iΪ������ֵΪ0 
	for (i = 0; i < M; i++)//������Ϣ 
	{
		Input_Info(&member[i]);//���� Input_Info()���� 
		printf("¼��ɹ���\n");
		num++;
		if (i == M - 1) {//�ж��Ƿ�������Ա��Ϣ������ʮ����������ʾ����Ա���������������˵��� 
			printf("��Ա���������������˵�\n");
			system("pause");
			break;
		}
		aa = getchar();
		printf("�س�����¼�룬������'0'�ɷ��ز˵�\n");
		aa = getchar();
		if (aa == '0') {//���ز˵� 
			system("cls");
			break;
		}
	}
}

//������Ϣ
void Info_Add()
{
	char aa;//aa���ַ����� 
	while (1)//����ѭ��������Ϊ1 
	{
		if (num == 0)//����Ϊnum==0 ��������ϵͳ��û��������Ա��Ϣ��ʱ��ִ��if��� 
		{
			printf("������Ϣ�����ǿյģ���������Ϣ\n���س�������������\n");
			getchar();//���ջس�
			getchar();
			system("cls");//����
			break;
		}
		Input_Info(&member[num]);//������Ϣ�� Input_Info()���� 
		printf("¼��ɹ���\n");
		num++;
		aa = getchar();
		printf("�س�����¼�룬������'0'�ɷ��ز˵�\n");
		aa = getchar();
		if (aa == '0')//���ز˵� 
		{
			system("cls");
			break;
		}
	}
}



//ɾ����Ϣ
void Info_Dele()
{
	printf("---------------- ɾ����Ϣ----------------\n");
	char id[20];//ѧ��Ϊ�ַ����� 
	printf("������Ҫɾ����id��");
	scanf("%s", &id);
	Delete(id);//����ɾ������
}



//ɾ������
void Delete(char id[])
{
	int i = 0;//iΪ������ֵΪ0 
	for (i = 0; i < num; i++)//��ɾ����Ϣ����С����������� 
	{
		if (i == num - 1)//�����һ��Ԫ�ش�ɾ��
		{
			printf("ɾ���ɹ���\n");
			num--;//ɾ����������һ 
			return;
		}
		else if (strcmp(member[i].id, id) == 0)//�����һ��Ԫ�ش�ɾ����strcmpΪ�ַ����ȽϺ�����ͨ��ASCII��Ƚ��ַ������鿴�Ƿ��Ǵ洢����id 
		{
			int j = i;//��j=i���Ҷ�Ϊ���� 
			for (j = i; j < num - 1; j++)//���ṹ�е�ѧ����Ϣ��ǰ�ƶ�һλ 
			{
				member[j] = member[j + 1];
			}
			printf("ɾ���ɹ���\n");
			num--;//ɾ����������һ 
			return;
		}
	}
	printf("�Ҳ���Ҫɾ����id.\n");
}



//�޸���Ϣ
void Info_Change()
{
	printf("---------------�޸���Ϣ---------------\n");
	char id[20];//ѧ��Ϊ�ַ����� 
	printf("������Ҫ�޸ĵ�id��");
	scanf("%s", &id);
	char aa;
	while (1)//����ѭ������������Ѱ�Ҵ��޸Ľ��
	{
		if (num == 0)//��ѯ���й��������Ϣ 
		{
			printf("δ�ҵ���id\n���س�������������\n");
			getchar();
			getchar();
			system("cls");
			break;
		}
		int i = 0;
		for (i = 0; i < num; i++)
		{
			if (strcmp(member[i].id, id) == 0)//�Ƚ������ѧ���Ƿ����Դ洢��ѧ����ͬ 
			{
				Input_Info(&member[i]);//Ϊ�ó�Ա������Ϣ
				printf("�޸ĳɹ�\n");
				return;
			}
		}
	}
}

//չʾ��Ϣ
void Info_Show()
{
	printf("��Ϣ���£�\n");
	if (num == 0)
	{
		printf("������Ϣ����ȥ�����Ϣ��\n���س�������\n");
		getchar();
		system("cls");
	}
	else {
		int i = 0;
		for (i = 0; i < num; i++)//��ÿһ����Ա���ݴ�ӡ����
		{
			printf("id��%s\t", member[i].id);//ÿ����Ϣ֮��հ˸��� 
			printf("���֣�%s\t", member[i].name);
			printf("�������ڣ�%s\t", member[i].birth);
			printf("ϵ��%s\t", member[i].department);
			printf("�Ա�%s\t", member[i].sex);
			printf("������ڣ�%s\t", member[i].date);
			printf("��ߣ�%d\t", member[i].height);
			printf("���أ�%s\t", member[i].weight);
			printf("�λ�����%s\t", member[i].pulmonary);
			printf("�������ۣ�%s\t\n", member[i].health);
		}
	}
}

//��ѯ��Ϣ
void Info_Find()
{
	printf("��������\n");
	char date[20];//�����������Ϊ�ַ����� 
	scanf("%s", &date);//�������� 
	printf("������Ϣ���£�\n");
	if (num == 0)//��δ�������Ϣʱ��� ������Ϣ����ȥ�����Ϣ��
	{
		printf("������Ϣ����ȥ�����Ϣ��\n���س�������\n");
		getchar();
		getchar();
		system("cls");
	}
	else {//���������¼ʱ 
		int i = 0;
		for (i = 0; i < num; i++)// ��������
		{
			if (strcmp(member[i].date, date) == 0)//�ҵ���������Ľ��
			{
				printf("id��%s\t", member[i].id);
				printf("���֣�%s\t", member[i].name);
				printf("�������ڣ�%s\t", member[i].birth);
				printf("ϵ��%s\t", member[i].department);
				printf("�Ա�%s\t", member[i].sex);
				printf("������ڣ�%s\t", member[i].date);
				printf("��ߣ�%d\t", member[i].height);
				printf("���أ�%s\t", member[i].weight);
				printf("�λ�����%s\t", member[i].pulmonary);
				printf("�������ۣ�%s\t\n", member[i].health);
			}
		}
	}
}

//����ð�����򣨴�С�����ţ�
void bubbleSort() {
	int i = -1;
	int j = 0;
	int tail = num;
	while (i + 1 != tail) {
		i = -1;
		j = 0;
		Info t;//tΪһ����ʱ�ṹ�壬����������Ϣ 
		while (j + 1 != tail) {
			if (member[j].height > member[j + 1].height) //��Ҫ�Ӵ�С�����>��Ϊ<
			{
				t = member[j];//�� member[j]�����Ϣ�洢��t�ڣ���ʱmember[j]��Ϊ�� 
				member[j] = member[j + 1];//��member[j]��member[j + 1]�ڵ�ֵ 
				member[j + 1] = t;//t��ֵ���� member[j + 1]
			}
			else
				j++;
			i++;
		}
		tail = j;
	}
}

//��Ϣ�������������ֵ������ bubbleSort()�� Info_Show()���� 
void Info_Sort()
{
	bubbleSort();//����������
	Info_Show();//չʾ����������
}

//������Ϣ���ļ��� infomation.txt�� 
void Info_Export()
{
	Info* p;
	FILE* fp = fopen("infomation.txt", "w");//��ֻд�ļ�
	int i = 0;
	for (i = 0; i < num; i++)
	{
		fprintf(fp, "ѧ��:%s,����:%s,��������:%s,ϵ��:%s,�Ա�:%s,�������:%s,���:%d,����:%s,�λ���:%s,��������:%s\n",
			member[i].id, member[i].name, member[i].birth, member[i].department, member[i].sex, member[i].date, member[i].height,
			member[i].weight, member[i].pulmonary, member[i].health);//���ļ��ڴ洢��Ϣ 
	}
	fclose(fp);//�ر��ļ� 
}

int main()
{
	while (1) { //����ѭ�� 
		mainface();//mainface()���� 
		int a, flag = 0; //����a��flagΪ���� 
		scanf("%d", &a);//����һ�����浽��ַa���� 
		switch (a) {//switch() ��� 
		case 1://¼����Ϣ
			system("cls");//���� 
			Info_Rebuild();//Info_Rebuild()���� 
			system("cls"); break;
		case 2://�����Ϣ
			system("cls");
			Info_Add();
			system("cls"); break;
		case 3://ɾ����Ϣ
			system("cls");
			Info_Dele();
			system("pause"); system("cls"); break;
		case 4://�޸���Ϣ
			system("cls");
			Info_Change();
			system("pause"); system("cls"); break;
		case 5://�����Ϣ
			system("cls");
			Info_Show();
			system("pause"); system("cls"); break;
		case 6://��ѯ��Ϣ
			system("cls");
			Info_Find();
			system("pause"); system("cls"); break;
		case 7://�������
			system("cls");
			Info_Sort();
			system("pause"); system("cls"); break;
		case 8://������Ϣ
			system("cls");
			Info_Export();
			system("pause"); system("cls"); break;
		default: flag = 1; break;//��������������������� ִ�д���� 
		}
		if (flag)break;//��flag=1�������벻Ϊ1��8������һ����ʱ�˳�ѭ�����������
	}
	return 0;
}
