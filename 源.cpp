#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include"����.h"
#include"createMap.h"
#include"snake.h"
#define MY_BUFSIZE 1024    //����̨���ڱ���Ļ�������С
HANDLE hOut;                     //����̨���
using namespace std;
HWND GetConsoleHwnd()            //��ȡ���ھ��      
{

	HWND hwndFound;                      //����õľ�� 
	WCHAR pszNewWindowTitle[MY_BUFSIZE]; //���ڱ���

	WCHAR pszOldWindowTitle[MY_BUFSIZE]; //�ɵľ�� 


	//��ȡ��ǰ���ڱ���

	GetConsoleTitle(pszOldWindowTitle, MY_BUFSIZE);

	//����Ψһ�������ӡ� 

	char szStr[MY_BUFSIZE];

	sprintf_s(szStr, "%d%d", GetTickCount(), GetCurrentProcessId());   //��ΪΪ�˼��������MessagrBox�����õ�

	memset(pszNewWindowTitle, 0, sizeof(pszNewWindowTitle));
	MultiByteToWideChar(CP_ACP, 0, szStr, strlen(szStr) + 1, pszNewWindowTitle, sizeof(pszNewWindowTitle) / sizeof(pszNewWindowTitle[0]));

	//���ĵ�ǰ���ڱ��� 
	SetConsoleTitle(pszNewWindowTitle);

	//ȷ�����ڱ����Ѹ��� 
	Sleep(40);
	//�����´��ڱ���
	hwndFound = FindWindow(NULL, pszNewWindowTitle);

	//��ԭԭʼ���ڱ���
	SetConsoleTitle(pszOldWindowTitle);

	return(hwndFound);        //���ؾ��
}
int main()
{
	int choice;
	choice=welcome();
	explanation();
	switch (choice)
	{
	case 1:
		system("cls");
		createMap();
		explanation();
		initsnake();
		createFood();
		keyboardControl();
		snakemove();
		break;
	case 2:
		exit(0);
	}
	
	return 0;
}