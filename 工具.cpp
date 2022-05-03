#include<windows.h>

void gotoxy(short x, short y) {
    COORD coord = { x, y };
    //COORD是Windows API中定义的一种结构体类型，表示控制台屏幕上的坐标。
    //上面语句是定义了COORD类型的变量coord，并以形参x和y进行初始化。
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    //GetStdHandle(STD_OUTPUT_HANDLE); 获取控制台输出句柄
    //然后用SetConsoleCursorPosition设置控制台(cmd)光标位置
}
void color(int col)
{
    //调用API改变控制台字体颜色
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}