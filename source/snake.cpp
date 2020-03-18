/*
* Copyright (c) *****
* All Rights Reserved.
* Dept.:****
* File:snake.cpp
* Description:
* REQ IDs: ***
* History:
* 2020-3-18, original
*/




#include "snake.h"


Snake::Snake(Wall & temwall,Food &temfood):wall(temwall),pHead(NULL),food(temfood),speed(300){}
Snake::~Snake(){}


void Snake::destoryPoint()
{

	Point *pCur = pHead;
	while (pHead != NULL)
	{
		pCur = pHead->next;
		delete pHead;
		pHead = pCur;
	}

}

void Snake::addPoint(int row,int col)
{
	Point *newP = new Point;
	newP->row = row;
	newP->col = col;
	newP->next = NULL;
	if(this->pHead != NULL)
	{
	    this->wall.setWall(pHead->row,pHead->col,'=');
		gotoxy(hOut,pHead->col*2,pHead->row+5);
		cout<<"=";
	}
	newP->next = pHead;
	pHead = newP;
	this->wall.setWall(pHead->row ,pHead->col,'@');
	gotoxy(hOut,pHead->col*2,pHead->row+5);
	cout<<"@";


}


void Snake::initSnake()
{
    this->destoryPoint();
	this->addPoint(5,5);
	this->addPoint(5,6);
}


bool Snake :: move(DIR key)
{
	int cur_head_row;
	int cur_head_col;
	Point *pre = this->pHead;
	Point *cur = this->pHead->next;
	bool rool = false;

	if(this->pHead == NULL)
	{
	    std::cout << "没有蛇"<<endl;
		return false;
	}
	cur_head_row = this->pHead->row;
	cur_head_col = this->pHead->col;

	
	switch (key)
	{
	case DOWN:
		cur_head_row++;
		break;
	case UP:
		cur_head_row--;
		break;
	case RIGHT:
		cur_head_col++;
		break;
	case LEFT:
		cur_head_col--;
		break;
	default:
		break;
	}
	while (cur->next != NULL)
	{
		pre = pre->next;
		cur = pre->next;
	}
	if((cur->row==cur_head_row) &&(cur->col==cur_head_col))
	{
	    rool = true;
	}
	else 
	{
		if((this->wall.getWall(cur_head_row,cur_head_col) == '*')||(this->wall.getWall(cur_head_row,cur_head_col) == '='))
		{
			this->addPoint(cur_head_row,cur_head_col);
			this->delPoint();
			//system("cls"); //清屏
			//this->wall.draw(); //重新绘制蛇
			gotoxy(hOut, 0, wall.ROW+5);
			cout<<"得分："<<this->getScore()<<endl;
			gotoxy(hOut, 0, wall.ROW+6);
			cout<<"速度："<<this->getSpeed()<<endl;
			gotoxy(hOut, 0, wall.ROW+7);
			std::cout<<"gameover"<<endl;
			return false;
		}
		
	}
	if(this->wall.getWall(cur_head_row,cur_head_col) == '#')
	{
	    this->addPoint(cur_head_row,cur_head_col);
		this->food.setFood();
		return true;
		
	}
	else
	{
		if(rool)
		{
		    this->addPoint(cur_head_row,cur_head_col);
	        this->delPoint();
			this->wall.setWall(cur_head_row,cur_head_col,'@');
			gotoxy(hOut,pHead->col*2,pHead->row+5);
		    cout<<"@";
		    return true;
		}
		else
		{
			this->addPoint(cur_head_row,cur_head_col);
			this->delPoint();
			return true;
		}
		
	}
}


void Snake::delPoint()
{
    Point *pre = this->pHead;
	Point *cur = this->pHead->next;
	if( (pre==NULL) || (cur == NULL))
	{
	    return;
	}

	while (cur->next != NULL)
	{
		pre = pre->next;
		cur = pre->next;
	}
	this->wall.setWall(cur->row,cur->col,' ');
	gotoxy(hOut,cur->col*2,cur->row+5);
	cout<<" ";
	delete cur;
	cur = NULL;
	pre->next = NULL;

}


int Snake::getSize()
{
	Point *cur = this->pHead;
	int size = 0;
	while (cur!= NULL)
	{
		
		size++;
		cur = cur->next;
		
	}

	return size;
}

int Snake::getSpeed()
{
	int size=0;
	size = this->getSize();
    if(size < 7)
	{
	    this->speed = 300;
	}
	else if(size >=7 && size < 12)
	{
	    this->speed = 200;
	}
	else if(size >=12 && size < 22)
	{
	    this->speed = 100;
	}
	else
	{
		this->speed = 50;
	}
	return this->speed;
}


int Snake::getScore()
{
    int size = 0;
	int score = 0;
	size = this->getSize();
	score = (size-2)*10;
	return score;


}