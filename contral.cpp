#include"additional.h"

void insline() {
	int i;
	for (i = 0; i < 87; i++) {
		printf("%c", '*');
	}
}
void insline1() {
	int i;
	for (i = 1; i < 86; i++) {
		printf("%c", ' ');
	}
}
void gotoxy(int x, int y)
{
	int xx = 0x0b;
	HANDLE hOutput;
	COORD loc;
	loc.X = x;
	loc.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, loc);
	return;
}
int wherex()

{

	CONSOLE_SCREEN_BUFFER_INFO pBuffer;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);

	return (pBuffer.dwCursorPosition.X + 1);

}
int wherey()

{

	CONSOLE_SCREEN_BUFFER_INFO pBuffer;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &pBuffer);

	return (pBuffer.dwCursorPosition.Y + 1);

}
void modeset(int w, int h)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD size = { w,h };
	SetConsoleScreenBufferSize(hOut, size);
	SMALL_RECT rc = { 1,1,w,h };
	SetConsoleWindowInfo(hOut, true, &rc);
	system("cls");
	return;
}
void drawmain2()
{
	MultiByteToWideChar(CP_UTF8, NULL, NULL, NULL, NULL, NULL);
	initgraph(700, 600);
	SetWindowText(GetHWnd(), _T("酒店客房管理系统"));
	COLORREF color;//定义一个颜色类型的变量
	color = RGB(189, 190, 0);
	settextcolor(color);//设置字体颜色
	settextstyle(20, 7, _T("Times New Roman"));
	color = RGB(179, 23, 220);
	setlinecolor(color);
	line(1, 1, 1, 600);
	line(700, 1, 700, 600);
	line(1, 1, 700, 1);
	line(1, 50, 700, 50);
	line(1, 550, 700, 550);
	line(1, 599, 700, 599);
	outtextxy(150, 20, _T("ROOM"));
	outtextxy(300, 20, _T("MENBER"));
	outtextxy(450, 20, _T("R&R"));
	outtextxy(275, 150, _T("press H -> ROOM\n"));
	outtextxy(275, 225, _T("press J -> MENBER\n"));
	outtextxy(275, 300, _T("press K -> R&R\n"));
	outtextxy(0, 560, _T("Hotel Managment System"));
	outtextxy(600, 560, _T("Version 2.0"));
	getch();
	closegraph();
}

void mainmenu()               /*绘制系统主界面*/
{
	int i;
	/*打印菜单内容*/
	for (i = 0; i <= 30; i++)
	{
		gotoxy(1, i);
		cprintf("%c", '#');
		gotoxy(89, i);
		cprintf("%c", '#');
	}
	gotoxy(2, 0);	insline();
	gotoxy(2, 2);	insline();
	gotoxy(2, 28);	insline();
	gotoxy(2, 30);	insline();
	gotoxy(12, 1);	printf("%c  %c ROOM %c  %c", '|', '<', '>', '|');
	gotoxy(37, 1);	printf("%c  %c MENBER %c  %c", '|', '<', '>', '|');
	gotoxy(64, 1);	printf("%c  %c R&R %c  %c", '|', '<', '>', '|');
	gotoxy(5, 29);	printf("Hotel Managment System");
	gotoxy(70, 29); printf("Version 2.0");
	gotoxy(65, 32);
}

void drawmain()
{
	system("color d");
	/*打印伪窗口竖线*/
	mainmenu();
	gotoxy(35, 10);	printf("press H -> Room");
	gotoxy(35, 12);	printf("press J -> Menber");
	gotoxy(35, 14);	printf("press K -> R&R");
}
//绘制菜单
void drawmenu(int m, int n) {
	int i;
	if (m % 3 == 0)
	{
		system("cls");
		/*打印边框*/
		for (i = 0; i < 10; i++)
		{
			gotoxy(12, 2 + i);	 cprintf("%c", '*');
			gotoxy(25, 2 + i); cprintf("%c", '*');
		}
		gotoxy(12, 11);  cprintf("**************");
		/*打印菜单内容*/
		mainmenu();
		gotoxy(14, 3);	cprintf("Add      ");
		gotoxy(14, 4);	cprintf("Query    ");
		gotoxy(14, 5);	cprintf("Modify   ");
		gotoxy(14, 6);	cprintf("Delete   ");
		gotoxy(14, 7);	cprintf("Sort     ");
		gotoxy(14, 8);	cprintf("Count    ");
		//gotoxy(14, 9); cprintf("Details");
		/*打印选项*/
		switch (n % 6) {
		case 0:gotoxy(14, 3); cprintf("Add     &"); break;
		case 1:gotoxy(14, 4); cprintf("Query   &"); break;
		case 2:gotoxy(14, 5); cprintf("Modify  &"); break;
		case 3:gotoxy(14, 6); cprintf("Delete  &"); break;
		case 4:gotoxy(14, 7); cprintf("Sort    &"); break;
		case 5:gotoxy(14, 8); cprintf("Count   &"); break;
		//case 6:gotoxy(14,9);  cprintf("Details &");break;
		}
	}
	if (m % 3 == 1)
	{
		system("cls");
		/*打印边框*/
		for (i = 1; i < 10; i++)
		{
			gotoxy(37, 2 + i);	cprintf("%c", '*');
			gotoxy(52, 2 + i);	cprintf("%c", '*');
		}
		gotoxy(39, 11);  cprintf("**************");//

		/*打印菜单内容*/
		mainmenu();
		gotoxy(39, 3);	cprintf("Add      ");
		gotoxy(39, 4);	cprintf("Query    ");
		gotoxy(39, 5);	cprintf("Modify   ");
		gotoxy(39, 6);	cprintf("Delete   ");
		gotoxy(39, 7);	cprintf("Sort     ");
		gotoxy(39, 8);	cprintf("Count    ");
		//gotoxy(39, 9); cprintf("Details");
		/*打印选项*/
		switch (n % 6) {
		case 0:gotoxy(39, 3); cprintf("Add     &"); break;
		case 1:gotoxy(39, 4); cprintf("Query   &"); break;
		case 2:gotoxy(39, 5); cprintf("Modify  &"); break;
		case 3:gotoxy(39, 6); cprintf("Delete  &"); break;
		case 4:gotoxy(39, 7); cprintf("Sort    &"); break;
		case 5:gotoxy(39, 8); cprintf("Count   &"); break;
		//case 6:gotoxy(39,9);  cprintf("Details &");break;
		}
	}
	if (m % 3 == 2)
	{
		system("cls");
		/*打印边框*/
		for (i = 1; i < 10; i++)//列
		{
			gotoxy(64, 2 + i);	cprintf("%c", '*');
			gotoxy(77, 2 + i);	cprintf("%c", '*');
		}
		gotoxy(64, 11);	cprintf("**************");
		/*打印菜单内容*/
		mainmenu();
		gotoxy(66, 3);	cprintf("Register   ");
		gotoxy(66, 5);	cprintf("Return   ");
		gotoxy(66, 7);	cprintf("Exit     ");
		/*打印选项*/
		switch (n % 3) {
		case 0:gotoxy(66, 3); cprintf("Register  &"); break;
		case 1:gotoxy(66, 5); cprintf("Return  &"); break;
		case 2:gotoxy(66, 7); cprintf("Exit    &"); break;
		}
	}
}
int menuctrl()           /*菜单控制*/
{
	int A, B, value,flag = 36, a, b;
	while (1)
	{
		/*获取键值*/
		while (1)
		{
			if (_kbhit())
			{
				A = getch();
				A = getch();
				if (A == 'H' || A == 'J' || A == 'K') break;
			}
		}
		if (A == 'H')
		{
			drawmenu(0, flag);
			value = 300;
		}
		if (A == 'J') {
			drawmenu(1, flag);
			value = 301;
		}
		if (A == 'K') {
			drawmenu(2, flag);
			value = 302;
		}
		while (1)
		{
			/*获取键值*/
			while (1)
			{
				if (_kbhit()) {
					B = getch();
					if (B == ESC || B == ENTER) {
						break;
					}
					B = getch();
					if (B == LEFT || B == RIGHT || B == UP || B == DOWN) break;
				}
			}
			/*返回上一级菜单*/
			if (B == ESC)
			{
				system("cls");
				drawmain();
				break;
			}
			if (flag == 0) flag = 36;
			if (value == 0) value = 300;
			/*返回功能键值*/
			if (B == ENTER)
			{
				if (value % 3 == 0) b = 6;
				if (value % 3 == 1) b = 6;
				if (value % 3 == 2) b = 3;
				a = (value % 3) * 10 + flag % b;
				if (a == 0) return ADD_ROOM;
				if (a == 1) return QUERY_ROOM;
				if (a == 2) return MODIFY_ROOM;
				if (a == 3) return DEL_ROOM;
				if (a == 4) return SORT_ROOM;
				if (a == 5) return COUNT_ROOM;
				if (a == 10) return ADD_MEMBER;
				if (a == 11) return QUERY_MEMBER;
				if (a == 12) return MODIFY_MEMBER;
				if (a == 13) return DEL_MEMBER;
				if (a == 14) return SORT_MEMBER;
				if (a == 15) return COUNT_MEMBER;
				if (a == 20) return REGISTER_ROOM;
				if (a == 21) return RETURN_ROOM;
				if (a == 22) return EXIT;
			}
			else if (B == UP) { /*切换选项*/
				drawmenu(value, --flag);
			}
			else if (B == DOWN) {
				drawmenu(value, ++flag);
			}
			else if (B == LEFT) {/*切换菜单*/
				drawmenu(--value, flag);
			}
			else {
				drawmenu(++value, flag);
			}
		}
	}

}