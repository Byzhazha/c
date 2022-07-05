//
//#include<stdio.h>
//#include<graphics.h>
//#include<conio.h>  //使用getch
//#include<Windows.h>
//#include<mmsystem.h>//包含多媒体设备接口文件
//#pragma comment(lib,"winmm.lib")
//void Bgm()
//{
//	//打开音乐，播放音乐 alias 取别名 repeat 重复播放
//	mciSendString("open ./隋唐演义001.mp3 alias Bgm ",0,0,0); 
//	mciSendString("play Bgm",0,0,0);
//	//if(0)
//	//{
//	//	mciSendString("close Bgm", 0, 0, 0);
//	//}
//}
//void change()
//{
//	//获取窗口句柄
//	HWND hnd = GetHWnd();
//	//设置窗口标题
//	SetWindowText(hnd, "数六秒");
//	//弹出窗口 提示用户操作
//	int isok =MessageBox(NULL,"恭喜你，成功了！","提示",MB_OKCANCEL);
//	if (isok == IDOK)
//	{
//		printf("您点击了ok\n");
//	}
//	else if (isok == IDCANCEL)
//	{
//		printf("您惦记了取消\n");
//	}
//}
//int main()
//{
//	initgraph(640,800, SHOWCONSOLE);
//	/*Bgm();*/
//	change();
//	setfillcolor(BROWN);
//	fillrectangle(100, 200, 500, 300);
//	settextstyle(30,0,"宋体");
//	setcolor(BLUE);
//	setbkmode(TRANSPARENT);
//	char butoon[] = "请按下这个按钮";
//	int x = 400 / 2 - textwidth(butoon) / 2;
//	int y = 100 / 2 - textheight(butoon) / 2;
//	outtextxy(x + 100, y + 200, butoon);
//	ExMessage msg;
//	int a= 0, b = 0;
//	while (TRUE)
//	{
//		//双缓冲绘图 需要放在绘图代码之前和之后
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
//		//	a = +5;//运行不了
//		//}
//		if (kbhit())//判断有没有键盘按下
//		{
//
//		
//		char key =_getch();//阻塞函数，不输入则一直在这等
//
//		printf("%d,%c\n", key, key);
//		switch (key)
//		{
//		case 72://上
//		case'w':
//		case'W':
//			b -= 5;
//			printf("上\n");
//			break;
//		case 80://下
//		case's':
//		case'S':
//			b += 5;
//			printf("下\n");
//			break;
//		case 75://左
//		case'a':
//		case'A':
//			a -= 5;
//			printf("左\n");
//			break;
//		case 77://右
//		case'd':
//		case'D':
//			a += 5;
//			printf("右\n");
//			break;
//		}
//
//		}
//		if (peekmessage(&msg, EM_MOUSE))//如果有鼠标点击 就为真
//		{
//			switch (msg.message)
//			{
//			case WM_LBUTTONDOWN:
//				if (msg.x >= 100 && msg.x <= 100 + 500 && msg.y >= 200 && msg.y <= 200 + 300)
//				{
//					printf("恭喜你\n");
//					outtextxy(200, 300, "你好");
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