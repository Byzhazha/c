#define _CRT_SECURE_NO_WARNINGS	
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>

#define length 100  //蛇长度

//坐标属性，蛇属性，食物属性

//坐标属性
typedef struct pointXY
{
	int x;
	int y;
}MYPOINT;

//蛇属性
struct Snake
{
	int num;//蛇的节数
	MYPOINT xy[length]; //蛇最多有100节
	char postion;//蛇的方向
};

//食物的属性
struct Food
{
	MYPOINT fdxy;
	int eatgrade;//吃食物的分数
	int flag;//食物是否存在，0表示存在，1表示不存在
};

//方向
enum movePostion { right = 77, left = 75, down = 80, up = 72 };

//开始界面
void startInterface();
//初始化蛇和食物
void initSnakeFood(struct Snake* snake, struct Food* food);
//画蛇
void drawSnake(struct Snake* snake);
//移动蛇
void moveSnake(struct Snake* snake);
//按键处理
void keyDown(struct Snake* snake);
//初始化食物
void initFood(struct Food* food, struct Snake* snake);
//画食物
void drawFood(struct Food* food);

//吃食物
void eatFood(struct Food* food, struct Snake* snake);

//判断是否游戏结束
int snakeDie(struct Snake* snake);

//判断游戏是否胜利
int winGame(struct Snake* snake);

//展示分数
void showGrade(struct Food* food);

//按空格键暂停
void pauseMoment();

int main()
{
	struct Snake snake;//创建蛇
	struct Food food = { 0 };//创建食物

	srand((unsigned int)time(NULL));//随机数种子
	initgraph(640, 480);//初始化窗口
	setbkcolor(WHITE);//设置窗口为白色
	int key = 0;//接收最终的弹窗指令，判断是否继续游戏
	int start = 1;

	do
	{
		initSnakeFood(&snake, &food);//初始化蛇和食物的分数
		key = 0;
		start = 1;
		while (1)
		{
			BeginBatchDraw(); //缓冲区打印，防止闪屏
			cleardevice();//刷新
			if (food.flag == 0)
				initFood(&food, &snake);

			drawFood(&food);//画食物
			eatFood(&food, &snake);//是否吃食物
			showGrade(&food);//打印食物
			drawSnake(&snake);//画蛇
			EndBatchDraw();//缓冲区打印
			if (snakeDie(&snake))//判断是否四方
				break;

			if (winGame(&snake))//判断是否胜利
				break;

			while (_kbhit())//如果有按键则进入，否则不进入循环
			{
				pauseMoment();//暂停
				keyDown(&snake);
			}
			moveSnake(&snake);//移动蛇
			if (start)
			{
				startInterface();
				start = 0;
			}
			Sleep(100);
		}
		key = MessageBox(NULL, "点击确定重新开始", "游戏结束", MB_OKCANCEL);

	} while (key == IDOK);//如果点击确定，则重新开始游戏
	closegraph();//关闭图形模式，释放由图形系统分配的所有内存
	system("pause");
	return 0;
}


void startInterface()
{
	outtextxy(180, 200, "使用方向键控制蛇的上、下、左、右移动");
	outtextxy(190, 230, "当蛇撞到自己，或撞到四周，游戏结束");
	outtextxy(245, 260, "吃到食物可以获得得分");
	outtextxy(270, 290, "按任意键开始");

	while (!_kbhit());
	while (_kbhit()) _getch();
}

void initSnakeFood(struct Snake* snake, struct Food* food)
{
	//把前三节的属性写出来，初始化数据
	snake->xy[2].x = 0;
	snake->xy[2].y = 0;

	snake->xy[1].x = 10;
	snake->xy[1].y = 0;

	snake->xy[0].x = 20;
	snake->xy[0].y = 0;

	snake->num = 3;//开始有三节

	snake->postion = right;//初始化方向为右

	food->eatgrade = 0;
}

void drawSnake(struct Snake* snake)
{
	for (int i = 0; i < snake->num; i++)
	{
		setlinecolor(BLACK);//矩形边框线的颜色
		setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));//内部填充颜色
		fillrectangle(snake->xy[i].x, snake->xy[i].y, snake->xy[i].x + 10, snake->xy[i].y + 10);
	}
}

void moveSnake(struct Snake* snake)
{
	//除了第一节之外，后面每一节都是前面一节的坐标
	for (int i = snake->num; i > 0; i--)
	{
		snake->xy[i].x = snake->xy[i - 1].x;
		snake->xy[i].y = snake->xy[i - 1].y;
	}
	//第一节的处理
	switch (snake->postion)
	{
	case right:
		snake->xy[0].x += 10;
		break;
	case left:
		snake->xy[0].x -= 10;
		break;
	case down:
		snake->xy[0].y += 10;
		break;
	case up:
		snake->xy[0].y -= 10;
	default:
		break;
	}
}

void keyDown(struct Snake* snake)
{
	char userkey = 0;
	userkey = _getch();
	switch (userkey)
	{
	case right:
		if	(snake->postion != left)
			snake->postion = right;
		break;
	case left:
		if (snake->postion != right)
			snake->postion = left;
		break;
	case down:
		if (snake->postion != up)
			snake->postion = down;
		break;
	case up:
		if (snake->postion != down)
			snake->postion = up;
		break;
	}
}

void initFood(struct Food* food, struct Snake* snake)
{
	food->fdxy.x = rand() % 64 * 10;
	food->fdxy.y = rand() % 48 * 10;
	food->flag = 1;

	//如果食物出现在蛇身上，重新产生坐标
	for (int i = 0; i < snake->num; i++)
	{
		if (food->fdxy.x == snake->xy[i].x && food->fdxy.y == snake->xy[i].y)
		{
			food->fdxy.x = rand() % 64 * 10;
			food->fdxy.y = rand() % 48 * 10;
		}
	}

}

void drawFood(struct Food* food)
{
	setlinecolor(BLACK);//矩形边框线的颜色
	setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	fillrectangle(food->fdxy.x, food->fdxy.y, food->fdxy.x + 10, food->fdxy.y + 10);
}

void eatFood(struct Food* food, struct Snake* snake)
{
	//蛇边长
	//食物重新生成
	//分数增加
	if (snake->xy[0].x == food->fdxy.x && snake->xy[0].y == food->fdxy.y)
	{
		snake->num++;
		food->eatgrade += 10;
		food->flag = 0;
	}
}

//蛇死亡，游戏结束
int snakeDie(struct Snake* snake)
{
	if (snake->xy[0].x > 640 || snake->xy[0].x < 0 || snake->xy[0].y>480 || snake->xy[0].y < 0 || (snake->xy[0].x + 10) > 640 || (snake->xy[0].x + 10) < 0 || (snake->xy[0].y + 10) > 480 || (snake->xy[0].y + 10) < 0)
	{
		outtextxy(200, 200, "撞墙");
		//MessageBox(hwnd, "游戏结束，点击确定重新开始", "撞墙", MB_OKCANCEL);
		return 1;//返回1，游戏结束
	}
	for (int i = 1; i < snake->num; i++)
	{
		if (snake->xy[0].x == snake->xy[i].x && snake->xy[0].y == snake->xy[i].y)
		{
			outtextxy(200, 200, "自杀");
			//MessageBox(hwnd, "游戏结束，点击确定重新开始", "自杀", MB_OKCANCEL);
			return 1;
		}
	}
	return 0;
}
int winGame(struct Snake* snake)
{
	if (snake->num == length)
	{
		outtextxy(200, 200, "胜利，恭喜通关");
		//MessageBox(hwnd, "游戏结束，点击确定重新开始", "恭喜通关", MB_OKCANCEL);
		return 1;//返回1，游戏结束
	}
	else
	{
		return 0;
	}
}
void showGrade(struct Food* food)
{
	char grade[100] = "";
	sprintf(grade, "%d", food->eatgrade);
	setbkmode(TRANSPARENT);
	settextcolor(LIGHTBLUE);
	outtextxy(560, 20, "分数");
	outtextxy(610, 20, grade);
}

void pauseMoment()
{
	if (_getch() == 32)
	{
		while (_getch() != 32);
	}
}
