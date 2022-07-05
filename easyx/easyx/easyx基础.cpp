//#define _CRT_SECURE_NO_WARNINGS	
//#include<stdio.h>
//#include<graphics.h>
//int main()
//{
//	initgraph(700,700,SHOWCONSOLE);//显示控制台 
//	setbkcolor(WHITE);
//	cleardevice();
//	setfillcolor(YELLOW);
//	setlinecolor(BLUE);//线条颜色
//	setlinestyle(PS_SOLID,5);//线条样式 实线  宽度 5个像素的宽度
//	circle(50,50,50);
//	fillcircle(250, 100, 50);
//	solidcircle(300, 400, 50);
//	//设置填充颜色   settifillcolor 
//	//绘制文字和颜色
//	settextcolor(RED);
//	settextstyle(50,0,"楷体");//高度 宽度 字体
//	//设置背景模式 trans parent
//	setbkmode(TRANSPARENT);
//	settextcolor(RGB(100, 100, 100));
//	outtextxy(50,50,"我爱你");
//	//把文字居中
//	fillrectangle(200, 50, 500, 100);
//	settextcolor(RGB(100, 100, 173));
//	char arr[] = "我是居中显示";
//	int width=300/2-textwidth(arr)/2;
//	int height = 50/2-textheight(arr) / 2;
//	outtextxy(width+200,height+50,arr);
//	//输出图片
//	IMAGE img;//定义一个对象（变量)
//	//加载图片
//	//loadimage(&img, "./1234.jpg",250,250);
//	//putimage(1,2, &img);
//	getchar();
//	closegraph();
//	return 0;
//}