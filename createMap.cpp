#include<conio.h>
#include<iostream>
#include<windows.h>//����Windows API
#include<stdlib.h>
#include<time.h>//�������������
#include"����.h"
#include"snake.h"
//#include"snake.h"

using namespace std;


int welcome()//����Ĭ�Ͻ�����棬չʾ��Ϸ˵�������ݣ������Ѷȵȼ�
{
    int x, y;
    int count1 = 0, count2 = 0;
    int choice;
    color(6);                   //������ɫ����Ϊ��ɫ 

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
    cout << "̰   ��   ��   С   ��   Ϸ" << endl;
 

    
    //����count1��count2��forѭ����ĳһ���������ɿ��
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
    cout << "1:��ʼ��Ϸ";

    gotoxy(32, 23);
    cout << "2:�˳���Ϸ";

    gotoxy(43, 26);
    printf("��ѡ��[1 2]:");
    cin >> choice;
    return choice;
}

void createMap()//��ӡ��ɫ�Ŀ����Ϊ������ͼ�ͱ߿�
{
    int i, j;
    int count = 0;
    for (i = 0; i < 58; i += 2)//��ɫ��ӡ���ŵı߿�
    {
        color(13);
        gotoxy(i, 0);
        cout << "��";
        gotoxy(i, 26);
        cout << "��";
    }
    for (j = 1; j <= 26; j++)//��ɫ��ӡ���ŵı߿�
    {
        color(13);
        gotoxy(0, j);
        cout << "��";
        gotoxy(56, j);
        cout << "��";
    }
    color(3);
    for (i = 2; i < 56; i += 2)//��ɫ����ڲ�
    {
        for (j = 1; j < 26; j++)
        {
            gotoxy(i, j);
            cout << "��";
        }
        Sleep(10);//������ʱЧ��
    }
    return;
}

void explanation()
{
    gotoxy(73, 10);
    color(14);
    cout << "��  Ϸ  ˵  ��";
   

    gotoxy(73, 11);
    color(15);
    cout << "����w���ϣ�s���£�a����d���ң�����С���ƶ�";
    gotoxy(73, 13);
    cout << "����ײ��ǽ�壬����ײ���Լ���";
    gotoxy(73, 14);
    cout << "����һ����Ƣ�����ߣ����Զ����¶��١�";     
    gotoxy(73, 15);
    cout << "����Ҫ��Լ������Ҫ���Լ��µĳԻ�ȥ������";
    gotoxy(73, 16);
    cout << "ף��Ϸ��죡" << endl;
    return;
}