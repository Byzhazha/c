//
//#include<stdio.h>
//#include<graphics.h>
//#include<conio.h>  //ʹ��getch
//#include<Windows.h>
//#include<mmsystem.h>//������ý���豸�ӿ��ļ�
//#pragma comment(lib,"winmm.lib")
//void Bgm()
//{
//	//�����֣��������� alias ȡ���� repeat �ظ�����
//	mciSendString("open ./��������001.mp3 alias Bgm ",0,0,0); 
//	mciSendString("play Bgm",0,0,0);
//	//if(0)
//	//{
//	//	mciSendString("close Bgm", 0, 0, 0);
//	//}
//}
//void change()
//{
//	//��ȡ���ھ��
//	HWND hnd = GetHWnd();
//	//���ô��ڱ���
//	SetWindowText(hnd, "������");
//	//�������� ��ʾ�û�����
//	int isok =MessageBox(NULL,"��ϲ�㣬�ɹ��ˣ�","��ʾ",MB_OKCANCEL);
//	if (isok == IDOK)
//	{
//		printf("�������ok\n");
//	}
//	else if (isok == IDCANCEL)
//	{
//		printf("�������ȡ��\n");
//	}
//}
//int main()
//{
//	initgraph(640,800, SHOWCONSOLE);
//	/*Bgm();*/
//	change();
//	setfillcolor(BROWN);
//	fillrectangle(100, 200, 500, 300);
//	settextstyle(30,0,"����");
//	setcolor(BLUE);
//	setbkmode(TRANSPARENT);
//	char butoon[] = "�밴�������ť";
//	int x = 400 / 2 - textwidth(butoon) / 2;
//	int y = 100 / 2 - textheight(butoon) / 2;
//	outtextxy(x + 100, y + 200, butoon);
//	ExMessage msg;
//	int a= 0, b = 0;
//	while (TRUE)
//	{
//		//˫�����ͼ ��Ҫ���ڻ�ͼ����֮ǰ��֮��
//		setfillcolor(BROWN);
//		fillcircle(a, b, 20);
//		EndBatchDraw();
//		//if (GetAsyncKeyState(VK_UP))
//		//{
//		//	b -= 5;
//		//}
//		//if (GetAsyncKeyState(VK_DOWN))
//		//{
//		//	b = b + 5;
//		//}
//		//if (GetAsyncKeyState(VK_LEFT))
//		//{
//		//	a -= 5;
//		//}
//		//if (GetAsyncKeyState(VK_RIGHT))
//		//{
//		//	a = +5;//���в���
//		//}
//		if (kbhit())//�ж���û�м��̰���
//		{
//
//		
//		char key =_getch();//������������������һֱ�����
//
//		printf("%d,%c\n", key, key);
//		switch (key)
//		{
//		case 72://��
//		case'w':
//		case'W':
//			b -= 5;
//			printf("��\n");
//			break;
//		case 80://��
//		case's':
//		case'S':
//			b += 5;
//			printf("��\n");
//			break;
//		case 75://��
//		case'a':
//		case'A':
//			a -= 5;
//			printf("��\n");
//			break;
//		case 77://��
//		case'd':
//		case'D':
//			a += 5;
//			printf("��\n");
//			break;
//		}
//
//		}
//		if (peekmessage(&msg, EM_MOUSE))//���������� ��Ϊ��
//		{
//			switch (msg.message)
//			{
//			case WM_LBUTTONDOWN:
//				if (msg.x >= 100 && msg.x <= 100 + 500 && msg.y >= 200 && msg.y <= 200 + 300)
//				{
//					printf("��ϲ��\n");
//					outtextxy(200, 300, "���");
//				}
//			default:
//				break;
//			}
//		}
//	}
//
//
//	getchar();
//	closegraph();
//}