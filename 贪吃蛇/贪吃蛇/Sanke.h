#pragma once
#define WIDE 60
#define HIGH 20

struct BODY
{
	int X;
	int Y;
};
struct SNAKE
{
	int size;
	struct BODY boby[WIDE*HIGH];
}snake;


int food[2] = {0};//food[0]ΪX���� food[1]ΪY����

int score = 0;
//ƫ������
int dx = 0;
int dy = 0;
//��¼��ĩβ����
int lx = 0;
int ly = 0;

void InitFood();
void InitSnake();
void ShowUI();
void PlayGame();
void InitWall();