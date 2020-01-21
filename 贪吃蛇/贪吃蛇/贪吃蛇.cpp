﻿//#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"Sanke.h"
#include<Windows.h>
#include<conio.h>

/*
1、定义蛇的结构体
1、初始化蛇和实物
3、开始游戏
     蛇和墙的碰撞
	 蛇和吱自身的碰撞
	 蛇和食物碰撞
	   重新随机食物
	   蛇身体增长
	   分数增长
	方向键的控制
4、游戏结束

*/


void InitFood()
{
	
	food[0] = rand() % WIDE;
	food[1] = rand() % HIGH;
}

void InitSnake()
{
	snake.size = 2;


	snake.boby[0].X = WIDE / 2;
	snake.boby[0].Y = HIGH / 2;

	snake.boby[1].X = WIDE / 2-1;
	snake.boby[1].Y = HIGH / 2;
}

void ShowUI()
{
	COORD coord;
	//更新末尾空格

	coord.X = lx;
	coord.Y = ly;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar(' ');

	//显示蛇的位置
	for (int i = 0; i < snake.size; i++)
	{
		coord.X = snake.boby[i].X;
		coord.Y = snake.boby[i].Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		if (i == 0)
		{
			putchar('@');
		}
		else
		{
			putchar('*');
		}


	}
	
	
	//显示食物的位置
	coord.X = food[0];
	coord.Y = food[1];
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar('#');
}

void PlayGame()
{
	char key = 'D';
	while (snake.boby[0].X >= 0 && snake.boby[0].X < WIDE
		&&snake.boby[0].Y >= 0 && snake.boby[0].Y < HIGH)
	{
		//InitWall();
		//显示界面
		ShowUI();
		//方向控制

		while (_kbhit())
		{
			key = _getch();
		}
		
		switch (key)
		{
		case'D':case'd': dx = 1; dy = 0; break;
		case'A':case'a': dx = -1; dy = 0; break;
		case'W':case'w': dx = 0; dy = -1; break;
		case'S':case's': dx = 0; dy = 1; break;
		}

		//是否和自身碰撞
		for (int i = 1; i < snake.size; i++)
		{
			if (snake.boby[0].X==snake.boby[i].X && snake.boby[0].Y == snake.boby[i].Y)
			{
				return;
			}
		}

		//蛇和食物的碰撞
		if (snake.boby[0].X == food[0] && snake.boby[0].Y == food[1])
		{
			//随机新事物
			InitFood();
			//蛇身体增长
			snake.size++;
			//分数增长
			score += 10;

		}


		//更新蛇的坐标

		lx = snake.boby[snake.size - 1].X;
		ly = snake.boby[snake.size - 1].Y;

		for (int i = snake.size - 1; i > 0; i--)
		{
			snake.boby[i].X = snake.boby[i - 1].X;
			snake.boby[i].Y = snake.boby[i - 1].Y;
		}
		//更新蛇头
		snake.boby[0].X += dx;
		snake.boby[0].Y += dy;

		Sleep(200);
		//system("cls");
		
	}

}

void InitWall()
{
	for (int i = 0; i <= HIGH; i++)
	{
		for (int j = 0; j <= WIDE; j++)
		{
			if (i == HIGH)
				putchar('=');
			else if (j == WIDE)
				putchar('=');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}


int main()
{
	srand((size_t)time(NULL));

	//去掉控制台光标
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

	InitWall();
	InitFood();
	InitSnake();
	//ShowUI();
	PlayGame();
	getchar();

	return 0;
}

