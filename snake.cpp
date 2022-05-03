#include"工具.h"
#include<iostream>
#include"snake.h"
#include"createMap.h"
using namespace std;

void createFood()
{
    //初始化指针
    food* foood = new food();
    foood->x = 1;
    foood->y = 0;

    //初始化随机数
    srand((unsigned)time(NULL));
    while ((foood->x % 2) != 0)
    {
        foood->x = rand() % 52 + 2;//52是最右内部的x坐标，+2防止生成在最左边边框上
    }
    foood->y = rand() % 24 + 1;//同上
    //判断蛇和事物是否重合
    q = head;
    while (q->next == NULL)
    {
        if (q->x == foood->x && q->y == foood->y)
        {
            free(foood);
            createFood();
        }
        q = q->next;
    }

    //打印输出
    gotoxy(foood->x, foood->y);
    color(12);
    cout << "●";
    food_1 = foood;
    return;
}
void showEndGame()
{
    int i;
    system("cls");
    color(13);
    gotoxy(4, 6);
    cout << "★";
    gotoxy(96, 6);
    cout << "★";
    gotoxy(4, 29);
    cout << "★";
    gotoxy(96, 29);
    cout << "★";

    //打印边框四条边
    for (i = 6; i < 96; i++)
    {
        color(13);
        gotoxy(i, 6);
        cout << "-";
    }
    for (i = 7; i < 29; i++)
    {
        color(13);
        gotoxy(4, i);
        cout << "|";
        gotoxy(97, i);
        cout << "|";
    }
    //打印边框上的装饰
    color(14);
    gotoxy(30, 6);
    printf("o00o");
    gotoxy(71, 6);
    printf("o00o");

    gotoxy(48, 5);
    color(14);
    printf("<  @ @  >");

    gotoxy(50, 6);
    color(3);
    printf("《_》");

    gotoxy(47, 29);
    color(13);
    printf("☆☆☆☆☆☆");

    //整点花活
    color(13);
    gotoxy(47, 29);
    cout << "☆☆☆☆☆☆";

    color(13);
    gotoxy(35, 3);
    cout << "您的得分是： " << score;
    return;
}//游戏结束的展示页面
void endgame()
{
    system("cls");
    if (endgamestatus == 1)
    {
        showEndGame();
        gotoxy(35, 9);
        color(14);
        cout << "愚蠢的人类撞到了墙，游戏结束。";
    }
    else if (endgamestatus == 2)
    {
        showEndGame();
        gotoxy(35, 9);
        color(14);
        cout << "愚蠢的人类咬到了自己，游戏结束。";
    }
    else if (endgamestatus == 3)
    {
        showEndGame();
        gotoxy(35, 9);
        color(14);
        cout << "您已经结束了游戏";
    }
    gotoxy(43, 12);
    color(13);
    cout << "您的的得分是： " << score;
    choose();
    return;
}//判断不同结束类型
void choose()
{
    int n;
    gotoxy(25, 23);
    color(10);
    cout << "输入1：不服，再来";
    gotoxy(52, 23);
    cout << "输入2：我要退出";
    gotoxy(46, 25);
    color(13);
    cout << "选择";
    cin >> n;
    switch (n)
    {
    case 1:
        system("cls");
        score = 0;
        sleeptime = INITIALTIME;
        add = 10;
        createMap();
        explanation();
        initsnake();
        createFood();
        keyboardControl();
        snakemove();
        break;
    case 2:
        exit(0);
        break;
    default:
        gotoxy(35, 27);
        color(12);
        printf("※※您输入的有误，请从新输入※※");
        system("pause >nul");
        endgame();
        choose();               //边框下的分支选项
        break;
    }
    return;
}//结束后进行选择重开或退出//结束游戏后是否进行再次游戏
void initsnake()
{
    Snake* tail;//    创建一个指向结构体的指针
    tail = new Snake;//用该指针在heap创建了新的空间
    //这个也是蛇尾

    tail->x = 24;
    tail->y = 5;
    tail->next = NULL;//定义了蛇尾的位置，蛇尾之后为空

    for (int i = 0; i <= 4; i++)
    {
        head = new Snake;
        head->next = tail;

        head->x = 24 + 2 * i;
        head->y = 5;
        tail = head;
    }

    while (tail != NULL)
    {
        color(14);
        gotoxy(tail->x,tail->y);                          
        cout << "■";                                          //蛇的生成就是用了 上面把头建立node 点之间的关系 然后再把头当成尾巴 从头输出
        tail = tail->next; //蛇身一点点输出
    }
    return;
}
bool biteself()
{
    Snake* self;               //self是蛇身上的一个节点(除了蛇身之外的节点)
    self = head->next;

    while (self != NULL)       //判断蛇头是否与蛇身相同,相同就是咬到自己了,咬到自己就返回true否则返回fslse
    {
        if (self->x == head->x && self->y == head->y)
            return true;
        self = self->next;
    }
    return false;                               //被咬了就是 true 反之为 false
}//利用一个身体的循环判断是否咬到自己了 利用的bool
void cantcrosswall()
{
    bool judge = 0;
    if (head->x == 0 || head->x == 56 || head->y == 0 || head->y == 26)  //判断是否撞到墙
    {
        endgamestatus = 1;              //结束游戏的一种情况,endgamestatus等于1时为失败界面
        endgame();
        judge = 1;
    }
    return;
}//用到了game里end 以及 endgamestatus 来分别结束游戏s
void speeddown()
{
    if (sleeptime < 350)       //如果时间大于或等于50执行下面的代码
    {
        sleeptime += 30;       //时间间隔减10
       
        if (sleeptime == 350)
        {
            add = 1;           //保证最低分为 1 分
        }
    }
}
void keyboardControl()
{
    status = R;     //初始化向右移动

    while (1)
    {
        //scoreandtips();      //游戏右边的小提示和得分

        //GetAsyncKeyState函数用来判断调用时指定虚假键的状态
        if (GetAsyncKeyState(VK_UP) && status != D)         //如果按的不是 下 键则向 上 移动
            status = U;
        else if (GetAsyncKeyState(VK_DOWN) && status != U)  //如果按的不是 上 键则向 下 移动
            status = D;
        else if (GetAsyncKeyState(VK_LEFT) && status != R)  //如果按的不是 右 键则向 左 移动
            status = L;
        else if (GetAsyncKeyState(VK_RIGHT) && status != L) //如果按的不是 左 键则向 右 移动
            status = R;

        if (GetAsyncKeyState(VK_SPACE))          //按空格键暂停
        {
            while (1)
            {
                Sleep(300);
                if (GetAsyncKeyState(VK_SPACE))          //再按一次空格键继续
                    break;
            }
        }
        else if (GetAsyncKeyState(VK_ESCAPE))            //按Esc键转到结束界面
        {
            endgamestatus = 3;
            break;
        }

        Sleep(sleeptime);            //移动速度
        snakemove();                 //没有按这几个键时继续移动
    }
    return;
}
void snakemove()
{
    Snake* nexthead;

    cantcrosswall();
    nexthead = (Snake*)malloc(sizeof(snake));

    if (status == U)    //向上移动
    {
        nexthead->x = head->x;
        nexthead->y = head->y - 1;

        nexthead->next = head;
        head = nexthead;
        q = head;          //指向链表头准备遍历链表

        if (nexthead->x == food_1->x && nexthead->y == food_1->y)      //如果遇到了食物
        {
            color(14);
            while (q != NULL)            //打印蛇身
            {
                gotoxy(q->x, q->y);
                cout << "■";
                q = q->next;
            }
            score += add;               //吃了食物后加分
            createFood();               //吃了食物后再创建一个
        }
        else           //如果没遇到食物
        {
            color(14);
            while (q->next->next != NULL)               //蛇往前移动后前面加一,后面减一   画出移动后蛇身前n-1个格子
            {
                gotoxy(q->x, q->y);
                cout << "■";
                q = q->next;
            }

            color(3);
            gotoxy(q->x, q->y);
            cout << "■";              //画出蛇身倒数第二个蛇身格子
            delete(q->next);            //释放掉原来的最后一个蛇身格子
            q->next = NULL;
        }
    }
    if (status == D)     //向下移动
    {

        nexthead->x = head->x;
        nexthead->y = head->y + 1;

        nexthead->next = head;
        head = nexthead;
        q = head;          //指向链表头准备遍历链表

        if (nexthead->x == food_1->x && nexthead->y == food_1->y)      //如果遇到了食物
        {
            color(14);
            while (q != NULL)            //打印蛇身
            {
                gotoxy(q->x, q->y);
                cout << "■";
                q = q->next;
            }
            score += add;               //吃了食物后加分
            createFood();               //吃了食物后再创建一个
        }
        else
        {
            color(14);
            while (q->next->next != NULL)
            {
                gotoxy(q->x, q->y);
                cout << "■";
                q = q->next;
            }

            color(3);
            gotoxy(q->x, q->y);
            cout << "■";              //画出蛇身倒数第二个蛇身格子
            delete(q->next);            //释放掉原来的最后一个蛇身格子
            q->next = NULL;
        }
    }

    if (status == L)     //向左移动
    {

        nexthead->x = head->x - 2;
        nexthead->y = head->y;

        nexthead->next = head;
        head = nexthead;
        q = head;          //指向链表头准备遍历链表

        if (nexthead->x == food_1->x && nexthead->y == food_1->y)      //如果遇到了食物
        {
            color(14);
            while (q != NULL)            //打印蛇身
            {
                gotoxy(q->x, q->y);
                cout << "■";
                q = q->next;
            }
            score += add;               //吃了食物后加分
            createFood();               //吃了食物后再创建一个
        }
        else
        {
            color(14);
            while (q->next->next != NULL)               //蛇往前移动后前面加一,后面减一   画出移动后蛇身前n-1个格子(画一画就理解了) 
            {
                gotoxy(q->x, q->y);
                cout << "■";
                q = q->next;
            }

            color(3);
            gotoxy(q->x, q->y);
            cout << "■";              //画出蛇身倒数第二个蛇身格子
            delete(q->next);            //释放掉原来的最后一个蛇身格子
            q->next = NULL;
        }
    }

    if (status == R)     //向右移动
    {

        nexthead->x = head->x + 2;
        nexthead->y = head->y;

        nexthead->next = head;
        head = nexthead;
        q = head;          //指向链表头准备遍历链表

        if (nexthead->x == food_1->x && nexthead->y == food_1->y)      //如果遇到了食物
        {
            color(14);
            while (q != NULL)            //打印蛇身
            {
                gotoxy(q->x, q->y);
                cout << "■";
                q = q->next;
            }
            score += add;               //吃了食物后加分
            createFood();               //吃了食物后再创建一个
        }
        else
        {
            color(14);
            while (q->next->next != NULL)
            {
                gotoxy(q->x, q->y);
                cout << "■";
                q = q->next;
            }

            color(3);
            gotoxy(q->x, q->y);
            cout << "■";              //画出蛇身倒数第二个蛇身格子
            delete(q->next);            //释放掉原来的最后一个蛇身格子
            q->next = NULL;
        }
    }

    if (biteself() == true)           //判断是否咬到自己
    {
        endgamestatus = 2;
        endgame();
    }
    return;
}