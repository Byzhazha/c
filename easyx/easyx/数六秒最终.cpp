//#include<graphics.h>
//#include <stdio.h> 
//#include<string.h>
//#include <conio.h> 
//#include <windows.h> 
//#include <stdlib.h>
//#include<mmsystem.h>
//#pragma comment(lib,"winmm.lib")
//#pragma warning(disable : 4996)
//
//char TimeShow[16]; // ��ʾʱ��
//IMAGE img;//����һ�����󣨱���)
//void image()//����ͼƬ���
//{
//    loadimage(&img, "42.jpeg", 800, 640);//������ΪͼƬ��С
//    putimage(0, 0, &img);
//}
//void title()//����
//{
//    settextcolor(BLACK);
//    setbkmode(TRANSPARENT);//���ֱ���͸��
//    settextstyle(80, 0, "����");
//    outtextxy(120, 60, "��ս����С��Ϸ");
//    settextstyle(30, 0, "����");
//    settextcolor(RED);
//    outtextxy(0, 200, "��������         ��Ϸ�����뿴doc����");
//    settextcolor(GREEN);
//    settextstyle(90, 0, "���Ĳ���");
//    outtextxy(8, 390, "�ûس�����ʼ��ϷŶ");
//}
//
//void print()//doc���
//{
//    printf("----------------��Ϸ���ܺ͹���------------------\n");
//    printf("�����Ϸ���ճ������кܳ�������������ϲ���Ŀ��Ͼ������Ƶ���Ϸ��\n");
//    printf("�û���һ�ν��а�������ʱ����ʱ��ʼ���ٴΰ�����������ʱ������\n");
//    printf("׼ȷ��ͣ��������������ս�ɹ�\n");
//}
//void change()//����easy�������
//{
//    HWND hnd = GetHWnd();//��ȡ���ھ��
//    SetWindowText(hnd, "������С��Ϸ");//���ô��ڱ���
//    //MessageBox(NULL, "������", "������", MB_OK);//��������
//}
//void music()//����
//{
//    mciSendString("open ./����.mp3 alias Bgm ", 0, 0, 0);
//    mciSendString("play Bgm", 0, 0, 0);
//}
//struct tm     //����ʱ��ṹ�壬����ʱ�����10���� 
//{
//    int hours, minutes, seconds;
//    int hscd;
//}time, tmp, total;    //time���Լ�ʱ��ʾ��tmp���Դ洢��һ�׶�ʱ�䣬total����ʱ�� 
//int cnt;
//FILE* fout;
////ÿ�ε���update�������൱��ʱ�����10ms 
//void update(struct tm* t)
//{
//
//    (*t).hscd++;    //10ms��λʱ���1  
//    cnt++;
//    if ((*t).hscd == 100)   //��ʱ��1s����λ 
//    {
//        (*t).hscd = 0;
//        (*t).seconds++;
//    }
//    if ((*t).seconds == 60)   //��ʱ��һ�֣���λ 
//    {
//        (*t).seconds = 0;
//        (*t).minutes++;
//    }
//    if ((*t).minutes == 60)        //��ʱ��һСʱ����λ 
//
//    {
//        (*t).minutes = 0;
//        (*t).hours++;
//    }
//    if ((*t).hours == 24) (*t).hours = 0;
//    Sleep(10);  //Sleep��windows�ṩ�ĺ�������������ͣ���򣬵�λ���룬���Դ˴���ͣ10ms 
//}
//void display(struct tm* t)
//{
//    BeginBatchDraw(); // �ڴ滺��
//    putimage(0, 0, &img);
//    settextcolor(BLACK);
//    settextstyle(80, 0, "����");
//    outtextxy(120, 60, "��ս����С��Ϸ");
//    settextstyle(30, 0, "����");
//    settextcolor(RED);
//    outtextxy(0, 200, "��������         ��Ϸ�����뿴doc����");
//    sprintf(TimeShow, "%d : %d : %d : %d", (*t).hours, (*t).minutes, (*t).seconds, (*t).hscd);//�ַ�����ʽ��
//    settextstyle(100, 0, "����");
//    settextcolor(BLUE);
//    outtextxy(60, 320, TimeShow);
//    settextcolor(GREEN);
//    settextstyle(60, 0, "���Ĳ���");
//    outtextxy(34, 260, "��ͣ����������Ϊ��ս�ɹ�Ŷ");
//    EndBatchDraw();
//
//}
//void time_init()  //��ʼ��ʱ�� 
//{
//    time.hours = time.minutes = time.seconds = time.hscd = 0;
//}
//void get_total()   //������ʱ�� 
//{
//    total.hscd = cnt % 100;
//    cnt /= 100;
//    total.seconds = cnt % 60;
//    cnt /= 60;
//    total.minutes = cnt % 60;
//    cnt /= 60;
//    total.hours = cnt;
//}
//
//void display2(struct tm* t)
//{
//    if ((*t).seconds < 5||(*t).seconds>=7)
//    {
//        settextcolor(RGB(127, 127, 127));
//        settextstyle(150, 0, "��������");
//        outtextxy(200, 450, "ʧ�ܣ�");
//    }
//    if ((*t).seconds == 5 && (*t).hscd > 80)
//    {
//        settextcolor(RGB(127, 127, 127));
//        settextstyle(150, 0, "��������");
//        outtextxy(100, 450, "̫�ż��ˣ�");
//    }
//    if ((*t).seconds == 6 && (*t).hscd > 20)
//    {
//        settextcolor(RGB(127, 127, 127));
//        settextstyle(150, 0, "��������");
//        outtextxy(100, 450, "�е���Ŷ");
//    }
//    if ((*t).seconds ==6 && (*t).hscd ==0)
//    {
//        settextcolor(RED);
//        settextstyle(100, 0, "��������");
//        outtextxy(68, 450, "��ϲ����ս�ɹ�!");
//    }
//}
//
//int main()
//{
//    initgraph(800, 640, SHOWCONSOLE);
//    system("mode con cols=69 lines=45");//��һ��doc���ڴ�С
//    setbkcolor(RGB(191, 147, 52));//������ɫ��������ͼƬȫ������������
//    cleardevice();//�������ñ�����ɫ
//    image();
//    title();
//    music();
//    change();
//    print();
//    char m;
//    time_init();
//    cnt = 0;
//    fout = fopen("timeout.txt", "w");
//    printf("���س�����ʼ��ʱ!\n");
//    while (1)
//    {
//        m = getch();
//        if (m != '\r') //����һ�����룬����ǻس�����ô������ѭ��
//
//            printf("������󣬽�������س���!\n");
//        else
//            break;
//
//    }
//    printf("�Ѿ���ʼ��ʱ����������԰��ո���Էֶμ�ʱ!\n");
//    while (1)
//    {
//        if (kbhit())    //�˴�����Ƿ��м������� 
//        {
//            m = getch();
//            if (m == '\r')//������ڻس�����ô��ʱ����������ѭ��
//                break;
//            else if (m == ' ')  //������ڿո���ʾ�˴μ�ʱ����ʼ����ʱ�� 
//            {
//                tmp = time;      //��¼��һ�μ�ʱ����� 
//                fprintf(fout, "%d:%d:%d:%d\n", tmp.hours, tmp.minutes, tmp.seconds, tmp.hscd); //д���ļ� 
//                time_init();
//                printf("\n");
//            }
//            else
//            {
//                printf("������󣬽�֧������س������߿ո��!\n");
//            }
//        }
//        update(&time);//���¼�ʱ�� 
//
//        display(&time);//��ʾ��ʱ��ʱ�� 
//    }
//    display2(&time);
//
//    tmp = time;       //������һ�μ�ʹ�����д���ļ� 
//    fprintf(fout, "%d:%d:%d:%d\n", tmp.hours, tmp.minutes, tmp.seconds, tmp.hscd);
//    get_total();      //�����ܵ�ʱ�䣬��ʾ����д���ļ� 
//    printf("\n��ʱ��:%d:%d:%d:%d\n", total.hours, total.minutes, total.seconds, total.hscd);
//    fprintf(fout, "ͳ��ʱ��:%d:%d:%d:%d\n", total.hours, total.minutes, total.seconds, total.hscd);
//    fclose(fout);
//    printf("�Ѿ����浽��ǰĿ¼�µ�timeout.txt�ļ��а����������!");
//    getch();
//    getchar();
//    closegraph();
//}
//
//
