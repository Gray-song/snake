/*
* Copyright (c) *****
* All Rights Reserved.
* Dept.:****
* File:tool.cpp
* Description:
* REQ IDs: ***
* History:
* 2020-3-18, original
*/





#include "tool.h"

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
void gotoxy(HANDLE hOut, int x, int y)
{
	COORD pos;
	pos.X = x;             //横坐标
	pos.Y = y;            //纵坐标
	SetConsoleCursorPosition(hOut, pos);
}
