/*
* Copyright (c) *****
* All Rights Reserved.
* Dept.:****
* File:food.h
* Description: food.cpp head file
* REQ IDs: ***
* History:
* 2020-3-18, original
*/


#ifndef _FOOD_H_
#define _FOOD_H_
#include "wall.h"


class Food
{
public:
	Food(Wall &temwall);
	~Food();
	void setFood();
private:
	Wall &wall;
	int foodRow;
	int foodCol;
};


#endif