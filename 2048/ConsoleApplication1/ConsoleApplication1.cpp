// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"


#include<stdio.h>

#include<stdlib.h>

#include<time.h>

#include<conio.h>

#include<windows.h>

#define SIZE 4

static int score = 0;


void putn(int n[][SIZE]);

void getn(int n[][SIZE]);

int isempty(int n[][SIZE]);

int isfull(int n[][SIZE]);

void math(int n[][SIZE], char c);

void tow(int n[][SIZE]);

void toa(int n[][SIZE]);

void tos(int n[][SIZE]);

void tod(int n[][SIZE]);








	//主函数

	int main()

	{

		int i, j;

		int n[SIZE][SIZE];

		char c = ' ';

		for (i = 0; i < SIZE; i++)

		{

			for (j = 0; j < SIZE; j++)

			{

				n[i][j] = 0;

			}

		}


		printf("***********************\n"

			"      2048(%dX%d)      \n"

			"   control:W/A/S/D    \n"

			"press any key to begin \n"

			"***********************\n", SIZE, SIZE);

		_getch();

		system("cls");

		//n[0][1]=2048;

		//n[0][3]=2048;

		while (1)

		{

			if (isempty(n))

				getn(n);

			putn(n);

			if (!isempty(n) && isfull(n))

				break;

			//sleep(200);

			c = _getch();

			while (c != 'w'&&c != 'a'&&c != 's'&&c != 'd')

				c = _getch();

			math(n, c);

			system("cls");

		}

		printf("      Game Over!\n", score);

		return 0;

	}





	//函数

	void putn(int n[][SIZE])

	{

		int i, j;

		for (i = 0; i < SIZE; i++)

		{

			for (j = 0; j < SIZE; j++)

				printf("|     ");

			printf("|\n");

			for (j = 0; j < SIZE; j++)

			{

				if (n[i][j] == 0)

					printf("|     ");

				else

					printf("|%4d ", n[i][j]);

			}

			printf("|\n");

			for (j = 0; j < SIZE; j++)

				printf("|_____");

			printf("|\n");

		}

		printf("score: %d", score);

	}


	void getn(int n[][SIZE])

	{

		int a, b;

		a = rand() % SIZE;

		b = rand() % SIZE;

		while (n[a][b] != 0)

		{

			a = rand() % SIZE;

			b = rand() % SIZE;

		}

		n[a][b] = 2;


	}


	int isempty(int n[][SIZE])

	{

		int i, j, count = 0;

		for (i = 0; i < SIZE; i++)

			for (j = 0; j < SIZE; j++)

				if (n[i][j] == 0)

					count++;

		return count;

	}


	int isfull(int n[][SIZE])

	{

		int i, j, count = 0;

		for (i = 0; i < SIZE; i++)

		{

			for (j = 1; j < SIZE - 1; j++)

			{

				if (n[i][j] == n[i][j + 1] || n[i][j] == n[i][j - 1])

					count++;

			}

		}

		for (j = 0; j < SIZE; j++)

		{

			for (i = 1; i < SIZE - 1; i++)

			{

				if (n[i][j] == n[i + 1][j] || n[i][j] == n[i - 1][j])

					count++;

			}

		}

		return count > 0 ? 0 : 1;

	}


	void math(int n[][SIZE], char c)

	{

		switch (c)

		{

		case 'w':tow(n); break;

		case 'a':toa(n); break;

		case 's':tos(n); break;

		case 'd':tod(n); break;

		default:;

		}

	}

	void tow(int n[][SIZE])

	{

		int i, j, a;

		int m[SIZE];

		for (a = 0; a < SIZE; a++)

			m[a] = 0;

		for (j = 0; j < SIZE; j++)

		{

			for (a = 0; a < SIZE; a++)

			{

				for (i = 0; i < SIZE - 1; i++)

				{

					if (n[i][j] == 0)

					{

						n[i][j] = n[i + 1][j];

						n[i + 1][j] = 0;

					}

				}

			}

		}

		for (j = 0; j < SIZE; j++)

		{

			for (a = 0, i = 0; i < SIZE; i++)

			{

				if (n[i][j] != n[i + 1][j] && n[i][j] != 0 || n[i][j] == 2048)

				{

					m[a++] = n[i][j];

					n[i][j] = 0;

				}

				else if (n[i][j] == n[i + 1][j])

				{

					m[a++] = n[i][j] + n[i + 1][j];

					score += m[a - 1];

					n[i][j] = 0, n[i + 1][j] = 0;

				}

			}

			for (i = 0; i < SIZE; i++)

			{

				n[i][j] = m[i];

				m[i] = 0;

			}

		}



	}


	void toa(int n[][SIZE])

	{

		int i, j, a;

		int m[SIZE];

		for (a = 0; a < SIZE; a++)

			m[a] = 0;

		for (i = 0; i < SIZE; i++)

		{

			for (a = 0; a < SIZE; a++)

			{

				for (j = 0; j < SIZE - 1; j++)

				{

					if (n[i][j] == 0)

					{

						n[i][j] = n[i][j + 1];

						n[i][j + 1] = 0;

					}

				}

			}

		}

		for (i = 0; i < SIZE; i++)

		{

			for (a = 0, j = 0; j < SIZE; j++)

			{

				if (n[i][j] != n[i][j + 1] && n[i][j] != 0 || n[i][j] == 2048)

				{

					m[a++] = n[i][j];

					n[i][j] = 0;

				}

				else if (n[i][j] == n[i][j + 1])

				{

					m[a++] = n[i][j] + n[i][j + 1];

					score += m[a - 1];

					n[i][j] = 0, n[i][j + 1] = 0;

				}

			}

			for (j = 0; j < SIZE; j++)

			{

				n[i][j] = m[j];

				m[j] = 0;

			}

		}





	}

	void tos(int n[][SIZE])

	{

		int i, j, a;

		int m[SIZE];

		for (a = 0; a < SIZE; a++)

			m[a] = 0;

		for (j = SIZE - 1; j >= 0; j--)

		{

			for (a = SIZE - 1; a >= 0; a--)

			{

				for (i = SIZE - 1; i > 0; i--)

				{

					if (n[i][j] == 0)

					{

						n[i][j] = n[i - 1][j];

						n[i - 1][j] = 0;

					}

				}

			}

		}

		for (j = SIZE - 1; j >= 0; j--)

		{

			for (a = SIZE - 1, i = SIZE - 1; i >= 0; i--)

			{

				if (n[i][j] != n[i - 1][j] && n[i][j] != 0 || n[i][j] == 2048)

				{

					m[a--] = n[i][j];

					n[i][j] = 0;

				}

				else if (n[i][j] == n[i - 1][j])

				{

					m[a--] = n[i][j] + n[i - 1][j];

					score += m[a + 1];

					n[i][j] = 0, n[i - 1][j] = 0;

				}

			}

			for (i = SIZE - 1; i >= 0; i--)

			{

				n[i][j] = m[i];

				m[i] = 0;

			}

		}


	}

	void tod(int n[][SIZE])
	{

		int i, j, a;

		int m[SIZE];

		for (a = 0; a < SIZE; a++)

			m[a] = 0;

		for (i = SIZE - 1; i >= 0; i--)

		{

			for (a = SIZE - 1; a >= 0; a--)

			{

				for (j = SIZE - 1; j > 0; j--)

				{

					if (n[i][j] == 0)

					{

						n[i][j] = n[i][j - 1];

						n[i][j - 1] = 0;

					}

				}

			}

		}

		for (i = SIZE - 1; i >= 0; i--)

		{

			for (a = SIZE - 1, j = SIZE - 1; j >= 0; j--)

			{

				if (n[i][j] != n[i][j - 1] && n[i][j] != 0 || n[i][j] == 2048)

				{

					m[a--] = n[i][j];

					n[i][j] = 0;

				}

				else if (n[i][j] == n[i][j - 1])

				{

					m[a--] = n[i][j] + n[i][j - 1];

					score += m[a + 1];

					n[i][j] = 0, n[i][j - 1] = 0;

				}

			}

			for (j = SIZE - 1; j >= 0; j--)

			{

				n[i][j] = m[j];

				m[j] = 0;

			}

		}
	}
	

