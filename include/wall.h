/*
* Copyright (c) *****
* All Rights Reserved.
* Dept.:****
* File:wall.h
* Description:
* REQ IDs: ***
* History:
* 2020-3-18, original
*/




#ifndef _WALL_H_
#define  _WALL_H_
#include <iostream>
#include "tool.h"
using namespace std;

class Wall
{
public:
	enum MyEnum
	{
		ROW = 26,
		COL = 26
	};

	Wall();
	~Wall();

	void initWall();
	void draw();
	char getWall(int row, int col);
	void setWall(int row, int col, char value);

private:
	char gameArray[ROW][COL];


};




#endif