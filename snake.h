#pragma once
#include<windows.h>
#define INITIALTIME 200
#define U 1    
#define D 2    
#define L 3    
#define R 4 
static int endgamestatus;
static int score = 0, add = 1;
static int sleeptime = INITIALTIME;
static int status;
using namespace std;

static struct food
{
	int x;
	int y;
};
static food* food_1;
void createFood();
static class Snake
{
public:
	int x;                  //节点的x坐标
	int y;                  //节点的y坐标
	Snake* next;     //蛇身的下一个节点
}snake;//生成了snake对象
static Snake* head;            //蛇头指针,食物指针
static Snake* q;                                                               //注意：：删去了食物指针 



void showEndGame();//失败界面
void endgame();//结束游戏
void choose();
void snakemove();
void initsnake();
void keyboardControl();
