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
//char TimeShow[16]; // 显示时间
//IMAGE img;//定义一个对象（变量)
//void image()//背景图片输出
//{
//    loadimage(&img, "42.jpeg", 800, 640);//后两个为图片大小
//    putimage(0, 0, &img);
//}
//void title()//标题
//{
//    settextcolor(BLACK);
//    setbkmode(TRANSPARENT);//文字背景透明
//    settextstyle(80, 0, "宋体");
//    outtextxy(120, 60, "挑战六秒小游戏");
//    settextstyle(30, 0, "宋体");
//    settextcolor(RED);
//    outtextxy(0, 200, "←←←←         游戏规则请看doc窗口");
//    settextcolor(GREEN);
//    settextstyle(90, 0, "华文彩云");
//    outtextxy(8, 390, "敲回车键开始游戏哦");
//}
//
//void print()//doc输出
//{
//    printf("----------------游戏介绍和规则------------------\n");
//    printf("这个游戏在日常生活中很常见，例如作者喜爱的柯南就有类似的游戏。\n");
//    printf("用户第一次进行按键操作时，计时开始；再次按键操作，计时结束。\n");
//    printf("准确暂停到六秒整，则挑战成功\n");
//}
//void change()//更改easy界面标题
//{
//    HWND hnd = GetHWnd();//获取窗口句柄
//    SetWindowText(hnd, "数六秒小游戏");//设置窗口标题
//    //MessageBox(NULL, "看规则！", "看规则", MB_OK);//弹出窗口
//}
//void music()//音乐
//{
//    mciSendString("open ./最终.mp3 alias Bgm ", 0, 0, 0);
//    mciSendString("play Bgm", 0, 0, 0);
//}
//struct tm     //定义时间结构体，包括时分秒和10毫秒 
//{
//    int hours, minutes, seconds;
//    int hscd;
//}time, tmp, total;    //time用以计时显示，tmp用以存储上一阶段时间，total记总时间 
//int cnt;
//FILE* fout;
////每次调用update函数，相当于时间过了10ms 
//void update(struct tm* t)
//{
//
//    (*t).hscd++;    //10ms单位时间加1  
//    cnt++;
//    if ((*t).hscd == 100)   //计时满1s，进位 
//    {
//        (*t).hscd = 0;
//        (*t).seconds++;
//    }
//    if ((*t).seconds == 60)   //计时满一分，进位 
//    {
//        (*t).seconds = 0;
//        (*t).minutes++;
//    }
//    if ((*t).minutes == 60)        //计时满一小时，进位 
//
//    {
//        (*t).minutes = 0;
//        (*t).hours++;
//    }
//    if ((*t).hours == 24) (*t).hours = 0;
//    Sleep(10);  //Sleep是windows提供的函数，作用是暂停程序，单位毫秒，所以此处暂停10ms 
//}
//void display(struct tm* t)
//{
//    BeginBatchDraw(); // 内存缓冲
//    putimage(0, 0, &img);
//    settextcolor(BLACK);
//    settextstyle(80, 0, "宋体");
//    outtextxy(120, 60, "挑战六秒小游戏");
//    settextstyle(30, 0, "宋体");
//    settextcolor(RED);
//    outtextxy(0, 200, "←←←←         游戏规则请看doc窗口");
//    sprintf(TimeShow, "%d : %d : %d : %d", (*t).hours, (*t).minutes, (*t).seconds, (*t).hscd);//字符串格式化
//    settextstyle(100, 0, "楷体");
//    settextcolor(BLUE);
//    outtextxy(60, 320, TimeShow);
//    settextcolor(GREEN);
//    settextstyle(60, 0, "华文彩云");
//    outtextxy(34, 260, "暂停到六秒整则为挑战成功哦");
//    EndBatchDraw();
//
//}
//void time_init()  //初始化时间 
//{
//    time.hours = time.minutes = time.seconds = time.hscd = 0;
//}
//void get_total()   //计算总时间 
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
//        settextstyle(150, 0, "方正舒体");
//        outtextxy(200, 450, "失败！");
//    }
//    if ((*t).seconds == 5 && (*t).hscd > 80)
//    {
//        settextcolor(RGB(127, 127, 127));
//        settextstyle(150, 0, "方正舒体");
//        outtextxy(100, 450, "太着急了！");
//    }
//    if ((*t).seconds == 6 && (*t).hscd > 20)
//    {
//        settextcolor(RGB(127, 127, 127));
//        settextstyle(150, 0, "方正舒体");
//        outtextxy(100, 450, "有点慢哦");
//    }
//    if ((*t).seconds ==6 && (*t).hscd ==0)
//    {
//        settextcolor(RED);
//        settextstyle(100, 0, "方正舒体");
//        outtextxy(68, 450, "恭喜！挑战成功!");
//    }
//}
//
//int main()
//{
//    initgraph(800, 640, SHOWCONSOLE);
//    system("mode con cols=69 lines=45");//调一下doc窗口大小
//    setbkcolor(RGB(191, 147, 52));//背景颜色，设置了图片全屏，这行无用
//    cleardevice();//清屏设置背景颜色
//    image();
//    title();
//    music();
//    change();
//    print();
//    char m;
//    time_init();
//    cnt = 0;
//    fout = fopen("timeout.txt", "w");
//    printf("按回车键开始计时!\n");
//    while (1)
//    {
//        m = getch();
//        if (m != '\r') //读入一个输入，如果是回车，那么跳出次循环
//
//            printf("输入错误，仅能输入回车键!\n");
//        else
//            break;
//
//    }
//    printf("已经开始计时，但是你可以按空格键以分段计时!\n");
//    while (1)
//    {
//        if (kbhit())    //此处检查是否有键盘输入 
//        {
//            m = getch();
//            if (m == '\r')//如果等于回车，那么计时结束，跳出循环
//                break;
//            else if (m == ' ')  //如果等于空格，显示此次计时，初始化计时器 
//            {
//                tmp = time;      //记录上一段计时器结果 
//                fprintf(fout, "%d:%d:%d:%d\n", tmp.hours, tmp.minutes, tmp.seconds, tmp.hscd); //写入文件 
//                time_init();
//                printf("\n");
//            }
//            else
//            {
//                printf("输入错误，仅支持输入回车键或者空格键!\n");
//            }
//        }
//        update(&time);//更新计时器 
//
//        display(&time);//显示计时器时间 
//    }
//    display2(&time);
//
//    tmp = time;       //输出最后一次即使结果，写入文件 
//    fprintf(fout, "%d:%d:%d:%d\n", tmp.hours, tmp.minutes, tmp.seconds, tmp.hscd);
//    get_total();      //计算总的时间，显示，并写入文件 
//    printf("\n总时间:%d:%d:%d:%d\n", total.hours, total.minutes, total.seconds, total.hscd);
//    fprintf(fout, "统计时间:%d:%d:%d:%d\n", total.hours, total.minutes, total.seconds, total.hscd);
//    fclose(fout);
//    printf("已经保存到当前目录下的timeout.txt文件中按任意键结束!");
//    getch();
//    getchar();
//    closegraph();
//}
//
//
