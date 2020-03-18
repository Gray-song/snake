/*
* Copyright (c) *****
* All Rights Reserved.
* Dept.:****
* File:snake.h
* Description:
* REQ IDs: ***
* History:
* 2020-3-18, original
*/




#ifndef _SNAKE_H_
#define _SNAKE_H_
#include "wall.h"
#include "food.h"
struct  Point
{
	int row;
	int col;
	Point *next;
};


typedef enum DIR
{
	UP = 'w',
	DOWN = 's',
	LEFT = 'a',
	RIGHT = 'd'

} DIR;


class Snake
{
public:
	Snake(Wall & temwall,Food &temfood);
	~Snake();
	void initSnake();
	void destoryPoint();
	void addPoint(int row, int col);
	void delPoint();
	int getSize();
	int getSpeed();
	
	int getScore();
	bool move(DIR key);
private:
	Point *pHead;
	Wall &wall;
	Food &food;
	
	int speed ;

};


#endif