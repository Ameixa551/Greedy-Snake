#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include"工具.h"
#include"createMap.h"
#include"snake.h"
#define MY_BUFSIZE 1024    //控制台窗口标题的缓冲区大小
HANDLE hOut;                     //控制台句柄
using namespace std;
HWND GetConsoleHwnd()            //获取窗口句柄      
{

	HWND hwndFound;                      //最后获得的句柄 
	WCHAR pszNewWindowTitle[MY_BUFSIZE]; //窗口标题

	WCHAR pszOldWindowTitle[MY_BUFSIZE]; //旧的句柄 


	//获取当前窗口标题

	GetConsoleTitle(pszOldWindowTitle, MY_BUFSIZE);

	//设置唯一窗口名子。 

	char szStr[MY_BUFSIZE];

	sprintf_s(szStr, "%d%d", GetTickCount(), GetCurrentProcessId());   //因为为了兼容下面的MessagrBox这里用的

	memset(pszNewWindowTitle, 0, sizeof(pszNewWindowTitle));
	MultiByteToWideChar(CP_ACP, 0, szStr, strlen(szStr) + 1, pszNewWindowTitle, sizeof(pszNewWindowTitle) / sizeof(pszNewWindowTitle[0]));

	//更改当前窗口标题 
	SetConsoleTitle(pszNewWindowTitle);

	//确保窗口标题已更新 
	Sleep(40);
	//查找新窗口标题
	hwndFound = FindWindow(NULL, pszNewWindowTitle);

	//还原原始窗口标题
	SetConsoleTitle(pszOldWindowTitle);

	return(hwndFound);        //返回句柄
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