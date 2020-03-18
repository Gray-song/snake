/*
* Copyright (c) *****
* All Rights Reserved.
* Dept.:****
* File:wall.cpp
* Description:
* REQ IDs: ***
* History:
* 2020-3-18, original
*/



#include "wall.h"


Wall::Wall(){}

Wall::~Wall(){}

 void Wall::initWall()
{
	int t_row_index = 0;
	int t_col_index = 0;

	for(t_row_index = 0;t_row_index < ROW;t_row_index++)
	{
		for(t_col_index = 0;t_col_index < COL;t_col_index++)
		{
			if((t_col_index==0)||(t_col_index == COL-1)||(t_row_index==0)||(t_row_index == COL-1))
			{
			    this->gameArray[t_row_index][t_col_index] = '*';
			}
			else
			{
			    this->gameArray[t_row_index][t_col_index] = ' ';
			}
			
		}
	}

}


 void Wall::draw()
 {
     int t_row_index = 0;
	 int t_col_index = 0;
	 cout<<endl;
	 cout<<endl;
	 cout<<endl;
	 cout<<endl;
	 cout<<endl;
	 for(t_row_index = 0;t_row_index < ROW; t_row_index++)
	 {
	     for(t_col_index = 0; t_col_index < COL;t_col_index++)
		 {
		     cout<<this->gameArray[t_row_index][t_col_index]<<" ";
		 }
		 if (t_row_index == 5)
		{
			cout << " Snake Game V1.0" << " ";
		}
		if (t_row_index == 6)
		{
			cout << " Create by zt, 2016-09-10" << " ";
		}
		if (t_row_index == 7)
		{
			cout << " up    : w" << " ";
		}

		if (t_row_index == 8)
		{
			cout << " down  : s" << " ";
		}

		if (t_row_index == 9)
		{
			cout << " left  : a" << " ";
		}

		if (t_row_index == 10)
		{
			cout << " right : d" << " ";
		}

		 cout<<endl;
	 }
 
 }


 char Wall::getWall(int row , int col)
 {
     char value;
	 value =this->gameArray[row][col];
	 return value;
 
 }


 void Wall::setWall(int row,int col,char value)
 {
     this->gameArray[row][col] = value;
 
 }