#include<conio.h>
#include<iostream>
#include<windows.h>//调用Windows API
#include<stdlib.h>
#include<time.h>//生成随机数所需
#include"工具.h"
#include"snake.h"
//#include"snake.h"

using namespace std;


int welcome()//设置默认进入界面，展示游戏说明等内容，设置难度等级
{
    int x, y;
    int count1 = 0, count2 = 0;
    int choice;
    color(6);                   //字体颜色设置为黄色 

    gotoxy(32, 3);
    printf("~~~~=_=~~~~\\\\   <----------------------");

    gotoxy(44, 4);
    printf("\\\\");

    gotoxy(45, 5);
    printf("\\\\");

    gotoxy(46, 6);
    printf("\\\\");

    gotoxy(47, 7);
    printf("\\\\");

    gotoxy(48, 8);
    printf("=========================");

    gotoxy(32, 15);
    color(14);
    cout << "贪   吃   蛇   小   游   戏" << endl;
 

    
    //利用count1，count2和for循环在某一区域内生成框框
    for (x = 20; x < 80; x++)
    {
        count2++;
        for (y = 17; y < 26; y++)
        {
            count1++;
            if (x == 20 || x == 79)
            {
                if (count1 % 2 == 0)
                    color(9);
                else
                    color(13);

                gotoxy(x, y);
                cout << "|";
            }

            if (y == 17 || y == 25)
            {
                if (count2 % 2 == 0)
                    color(9);
                else
                    color(13);

                gotoxy(x, y);
                cout << "-";
            }
        }
    }

    for (x = 20; x < 80; x++)
    {
        count2++;
        for (y = 17; y < 26; y++)
        {

            count1++;
            if (x == 20 || x == 79)
            {
                if (count1 % 2 == 0)
                    color(9);
                else
                    color(13);

                gotoxy(x, y);
                printf("|");
            }

            if (y == 17 || y == 25)
            {
                if (count2 % 2 == 0)
                    color(9);
                else
                    color(13);

                gotoxy(x, y);
                printf("-");
            }
        }
    }
    gotoxy(32, 19);
    color(13);
    cout << "1:开始游戏";

    gotoxy(32, 23);
    cout << "2:退出游戏";

    gotoxy(43, 26);
    printf("请选择[1 2]:");
    cin >> choice;
    return choice;
}

void createMap()//打印彩色的块块作为基础地图和边框
{
    int i, j;
    int count = 0;
    for (i = 0; i < 58; i += 2)//紫色打印横着的边框
    {
        color(13);
        gotoxy(i, 0);
        cout << "■";
        gotoxy(i, 26);
        cout << "■";
    }
    for (j = 1; j <= 26; j++)//紫色打印竖着的边框
    {
        color(13);
        gotoxy(0, j);
        cout << "■";
        gotoxy(56, j);
        cout << "■";
    }
    color(3);
    for (i = 2; i < 56; i += 2)//蓝色填充内部
    {
        for (j = 1; j < 26; j++)
        {
            gotoxy(i, j);
            cout << "■";
        }
        Sleep(10);//动画延时效果
    }
    return;
}

void explanation()
{
    gotoxy(73, 10);
    color(14);
    cout << "游  戏  说  明";
   

    gotoxy(73, 11);
    color(15);
    cout << "利用w（上）s（下）a（左）d（右）控制小蛇移动";
    gotoxy(73, 13);
    cout << "不能撞到墙体，不能撞到自己！";
    gotoxy(73, 14);
    cout << "这是一条有脾气的蛇，它吃多少吐多少。";     
    gotoxy(73, 15);
    cout << "做蛇要节约，所以要把自己吐的吃回去！！！";
    gotoxy(73, 16);
    cout << "祝游戏愉快！" << endl;
    return;
}