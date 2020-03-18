/*
* Copyright (c) *****
* All Rights Reserved.
* Dept.:****
* File:game.cpp
* Description:
* REQ IDs: ***
* History:
* 2020-3-18, original
*/




#include<iostream>
#include "wall.h"
#include "snake.h"
#include "food.h"
#include "time.h"
#include "conio.h"
#include <Windows.h>



void startGame()
{
	char key;
	char prekey = NULL;
	bool isGameOver = true;
	srand((unsigned int)time(NULL));
	Wall wall;
	wall.initWall();
	wall.draw();
    Food food(wall);
	food.setFood();
	Snake snake(wall,food);
	snake.initSnake();
	
	gotoxy(hOut, 0, wall.ROW+5);
	cout << "得分：" << snake.getScore() << "分" << endl;
	
	//cout<<"得分："<<snake.getScore()<<endl;
	
	while (isGameOver)
	{
        key = _getch();
		if((prekey == NULL)&&(key == LEFT))
		{
		    continue;
		}
		do
		{
		    if((key == UP) || (key == DOWN) || (key == LEFT) || (key == RIGHT))
			{
			    if(((prekey == UP)&&(key == DOWN))
					||((prekey == DOWN)&&(key == UP))
					||((prekey == LEFT)&&(key == RIGHT))
					||((prekey == RIGHT)&&(key == LEFT)))
				{
				    key = prekey;
				}
				else
				{
				    prekey = key;
				}
				isGameOver = snake.move(DIR(key));
				if(isGameOver)
				{
					/*该处是正常移动，这个变量名字起的有点歧义望诸君见谅*/
					gotoxy(hOut, 0, wall.ROW+5);
					cout<<"得分："<<snake.getScore()<<endl;
					gotoxy(hOut, 0, wall.ROW+6);
					cout<<"速度："<<snake.getSpeed()<<endl;
					Sleep(snake.getSpeed());
				}
				else
				{
					break;

				}
			
			

			}
			else if(key = ' ')
			{
				;;
			}
			else
			{
			    key = prekey;
			}
		
		}while (!_kbhit());
		
		
	}
	
	
	

}


int main()
{
	startGame();
	

	system("pause");
    return EXIT_SUCCESS;
}