#include"����.h"
#include<iostream>
#include"snake.h"
#include"createMap.h"
using namespace std;

void createFood()
{
    //��ʼ��ָ��
    food* foood = new food();
    foood->x = 1;
    foood->y = 0;

    //��ʼ�������
    srand((unsigned)time(NULL));
    while ((foood->x % 2) != 0)
    {
        foood->x = rand() % 52 + 2;//52�������ڲ���x���꣬+2��ֹ����������߱߿���
    }
    foood->y = rand() % 24 + 1;//ͬ��
    //�ж��ߺ������Ƿ��غ�
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

    //��ӡ���
    gotoxy(foood->x, foood->y);
    color(12);
    cout << "��";
    food_1 = foood;
    return;
}
void showEndGame()
{
    int i;
    system("cls");
    color(13);
    gotoxy(4, 6);
    cout << "��";
    gotoxy(96, 6);
    cout << "��";
    gotoxy(4, 29);
    cout << "��";
    gotoxy(96, 29);
    cout << "��";

    //��ӡ�߿�������
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
    //��ӡ�߿��ϵ�װ��
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
    printf("��_��");

    gotoxy(47, 29);
    color(13);
    printf("�������");

    //���㻨��
    color(13);
    gotoxy(47, 29);
    cout << "�������";

    color(13);
    gotoxy(35, 3);
    cout << "���ĵ÷��ǣ� " << score;
    return;
}//��Ϸ������չʾҳ��
void endgame()
{
    system("cls");
    if (endgamestatus == 1)
    {
        showEndGame();
        gotoxy(35, 9);
        color(14);
        cout << "�޴�������ײ����ǽ����Ϸ������";
    }
    else if (endgamestatus == 2)
    {
        showEndGame();
        gotoxy(35, 9);
        color(14);
        cout << "�޴�������ҧ�����Լ�����Ϸ������";
    }
    else if (endgamestatus == 3)
    {
        showEndGame();
        gotoxy(35, 9);
        color(14);
        cout << "���Ѿ���������Ϸ";
    }
    gotoxy(43, 12);
    color(13);
    cout << "���ĵĵ÷��ǣ� " << score;
    choose();
    return;
}//�жϲ�ͬ��������
void choose()
{
    int n;
    gotoxy(25, 23);
    color(10);
    cout << "����1������������";
    gotoxy(52, 23);
    cout << "����2����Ҫ�˳�";
    gotoxy(46, 25);
    color(13);
    cout << "ѡ��";
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
        printf("���������������������������");
        system("pause >nul");
        endgame();
        choose();               //�߿��µķ�֧ѡ��
        break;
    }
    return;
}//���������ѡ���ؿ����˳�//������Ϸ���Ƿ�����ٴ���Ϸ
void initsnake()
{
    Snake* tail;//    ����һ��ָ��ṹ���ָ��
    tail = new Snake;//�ø�ָ����heap�������µĿռ�
    //���Ҳ����β

    tail->x = 24;
    tail->y = 5;
    tail->next = NULL;//��������β��λ�ã���β֮��Ϊ��

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
        cout << "��";                                          //�ߵ����ɾ������� �����ͷ����node ��֮��Ĺ�ϵ Ȼ���ٰ�ͷ����β�� ��ͷ���
        tail = tail->next; //����һ������
    }
    return;
}
bool biteself()
{
    Snake* self;               //self�������ϵ�һ���ڵ�(��������֮��Ľڵ�)
    self = head->next;

    while (self != NULL)       //�ж���ͷ�Ƿ���������ͬ,��ͬ����ҧ���Լ���,ҧ���Լ��ͷ���true���򷵻�fslse
    {
        if (self->x == head->x && self->y == head->y)
            return true;
        self = self->next;
    }
    return false;                               //��ҧ�˾��� true ��֮Ϊ false
}//����һ�������ѭ���ж��Ƿ�ҧ���Լ��� ���õ�bool
void cantcrosswall()
{
    bool judge = 0;
    if (head->x == 0 || head->x == 56 || head->y == 0 || head->y == 26)  //�ж��Ƿ�ײ��ǽ
    {
        endgamestatus = 1;              //������Ϸ��һ�����,endgamestatus����1ʱΪʧ�ܽ���
        endgame();
        judge = 1;
    }
    return;
}//�õ���game��end �Լ� endgamestatus ���ֱ������Ϸs
void speeddown()
{
    if (sleeptime < 350)       //���ʱ����ڻ����50ִ������Ĵ���
    {
        sleeptime += 30;       //ʱ������10
       
        if (sleeptime == 350)
        {
            add = 1;           //��֤��ͷ�Ϊ 1 ��
        }
    }
}
void keyboardControl()
{
    status = R;     //��ʼ�������ƶ�

    while (1)
    {
        //scoreandtips();      //��Ϸ�ұߵ�С��ʾ�͵÷�

        //GetAsyncKeyState���������жϵ���ʱָ����ټ���״̬
        if (GetAsyncKeyState(VK_UP) && status != D)         //������Ĳ��� �� ������ �� �ƶ�
            status = U;
        else if (GetAsyncKeyState(VK_DOWN) && status != U)  //������Ĳ��� �� ������ �� �ƶ�
            status = D;
        else if (GetAsyncKeyState(VK_LEFT) && status != R)  //������Ĳ��� �� ������ �� �ƶ�
            status = L;
        else if (GetAsyncKeyState(VK_RIGHT) && status != L) //������Ĳ��� �� ������ �� �ƶ�
            status = R;

        if (GetAsyncKeyState(VK_SPACE))          //���ո����ͣ
        {
            while (1)
            {
                Sleep(300);
                if (GetAsyncKeyState(VK_SPACE))          //�ٰ�һ�οո������
                    break;
            }
        }
        else if (GetAsyncKeyState(VK_ESCAPE))            //��Esc��ת����������
        {
            endgamestatus = 3;
            break;
        }

        Sleep(sleeptime);            //�ƶ��ٶ�
        snakemove();                 //û�а��⼸����ʱ�����ƶ�
    }
    return;
}
void snakemove()
{
    Snake* nexthead;

    cantcrosswall();
    nexthead = (Snake*)malloc(sizeof(snake));

    if (status == U)    //�����ƶ�
    {
        nexthead->x = head->x;
        nexthead->y = head->y - 1;

        nexthead->next = head;
        head = nexthead;
        q = head;          //ָ������ͷ׼����������

        if (nexthead->x == food_1->x && nexthead->y == food_1->y)      //���������ʳ��
        {
            color(14);
            while (q != NULL)            //��ӡ����
            {
                gotoxy(q->x, q->y);
                cout << "��";
                q = q->next;
            }
            score += add;               //����ʳ���ӷ�
            createFood();               //����ʳ����ٴ���һ��
        }
        else           //���û����ʳ��
        {
            color(14);
            while (q->next->next != NULL)               //����ǰ�ƶ���ǰ���һ,�����һ   �����ƶ�������ǰn-1������
            {
                gotoxy(q->x, q->y);
                cout << "��";
                q = q->next;
            }

            color(3);
            gotoxy(q->x, q->y);
            cout << "��";              //�����������ڶ����������
            delete(q->next);            //�ͷŵ�ԭ�������һ���������
            q->next = NULL;
        }
    }
    if (status == D)     //�����ƶ�
    {

        nexthead->x = head->x;
        nexthead->y = head->y + 1;

        nexthead->next = head;
        head = nexthead;
        q = head;          //ָ������ͷ׼����������

        if (nexthead->x == food_1->x && nexthead->y == food_1->y)      //���������ʳ��
        {
            color(14);
            while (q != NULL)            //��ӡ����
            {
                gotoxy(q->x, q->y);
                cout << "��";
                q = q->next;
            }
            score += add;               //����ʳ���ӷ�
            createFood();               //����ʳ����ٴ���һ��
        }
        else
        {
            color(14);
            while (q->next->next != NULL)
            {
                gotoxy(q->x, q->y);
                cout << "��";
                q = q->next;
            }

            color(3);
            gotoxy(q->x, q->y);
            cout << "��";              //�����������ڶ����������
            delete(q->next);            //�ͷŵ�ԭ�������һ���������
            q->next = NULL;
        }
    }

    if (status == L)     //�����ƶ�
    {

        nexthead->x = head->x - 2;
        nexthead->y = head->y;

        nexthead->next = head;
        head = nexthead;
        q = head;          //ָ������ͷ׼����������

        if (nexthead->x == food_1->x && nexthead->y == food_1->y)      //���������ʳ��
        {
            color(14);
            while (q != NULL)            //��ӡ����
            {
                gotoxy(q->x, q->y);
                cout << "��";
                q = q->next;
            }
            score += add;               //����ʳ���ӷ�
            createFood();               //����ʳ����ٴ���һ��
        }
        else
        {
            color(14);
            while (q->next->next != NULL)               //����ǰ�ƶ���ǰ���һ,�����һ   �����ƶ�������ǰn-1������(��һ���������) 
            {
                gotoxy(q->x, q->y);
                cout << "��";
                q = q->next;
            }

            color(3);
            gotoxy(q->x, q->y);
            cout << "��";              //�����������ڶ����������
            delete(q->next);            //�ͷŵ�ԭ�������һ���������
            q->next = NULL;
        }
    }

    if (status == R)     //�����ƶ�
    {

        nexthead->x = head->x + 2;
        nexthead->y = head->y;

        nexthead->next = head;
        head = nexthead;
        q = head;          //ָ������ͷ׼����������

        if (nexthead->x == food_1->x && nexthead->y == food_1->y)      //���������ʳ��
        {
            color(14);
            while (q != NULL)            //��ӡ����
            {
                gotoxy(q->x, q->y);
                cout << "��";
                q = q->next;
            }
            score += add;               //����ʳ���ӷ�
            createFood();               //����ʳ����ٴ���һ��
        }
        else
        {
            color(14);
            while (q->next->next != NULL)
            {
                gotoxy(q->x, q->y);
                cout << "��";
                q = q->next;
            }

            color(3);
            gotoxy(q->x, q->y);
            cout << "��";              //�����������ڶ����������
            delete(q->next);            //�ͷŵ�ԭ�������һ���������
            q->next = NULL;
        }
    }

    if (biteself() == true)           //�ж��Ƿ�ҧ���Լ�
    {
        endgamestatus = 2;
        endgame();
    }
    return;
}