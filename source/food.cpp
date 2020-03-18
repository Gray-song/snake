/*
* Copyright (c) *****
* All Rights Reserved.
* Dept.:****
* File:food.cpp
* Description:
* REQ IDs: ***
* History:
* 2020-3-18, original
*/




#include "food.h"


Food::Food(Wall &temwall):wall(temwall){}


Food::~Food(){}


void Food::setFood()
{
	int t_row_index = 0;
	int t_col_index = 0;

	while (1)
	{
        this->foodRow = rand()%(this->wall.ROW-2)+1;
		this->foodCol = rand()%(this->wall.COL-2)+1;
			
		if((this->wall.getWall(this->foodRow,this->foodCol) == ' '))
		{
					
			this->wall.setWall(this->foodRow,this->foodCol,'#');
			gotoxy(hOut,this->foodCol*2,this->foodRow+5);
			cout<<"#";
			break;
		}
			
			
	}

	
}
