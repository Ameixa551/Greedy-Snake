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
	int x;                  //�ڵ��x����
	int y;                  //�ڵ��y����
	Snake* next;     //�������һ���ڵ�
}snake;//������snake����
static Snake* head;            //��ͷָ��,ʳ��ָ��
static Snake* q;                                                               //ע�⣺��ɾȥ��ʳ��ָ�� 



void showEndGame();//ʧ�ܽ���
void endgame();//������Ϸ
void choose();
void snakemove();
void initsnake();
void keyboardControl();
