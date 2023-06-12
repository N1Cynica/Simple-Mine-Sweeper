#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < ROWS;i++)
	{
		for (j = 0;j < ROWS;j++)
		{
			board[i][j] = set;
		}
	}
}
void displayboard(char board[ROWS][COLS], int row, int col)
{
	printf("----------------扫雷游戏-----------------\n");
	int i = 0;
	int j = 0;
	for (j = 0;j <= col;j++)
	{
		printf("%d ",j);
	}
	printf("\n");
	for (i = 1;i <= row;i++)
	{
		printf("%d ", i);
		for (j = 1;j <= col;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void setmine(char board[ROWS][COLS], int row, int col,int count)
{
	if (count)
	{
		int x = rand() % row + 1;
		int y = rand() % row + 1;
		while (board[x][y]-48)
		{
			x = rand() % row + 1;
			y = rand() % row + 1;
		}
		board[x][y] = '1';
		setmine(board, row, col, count - 1);
	}
}

void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int i = 0;
	int j = 0;
	int count = 1;
	int check = 0;
	while (1)
	{
		check = countmine(show, row, col);
		if (check == easy_count)
		{
			printf("你赢了\n");
			break;
		}
		printf("请输入要排查的坐标：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("该坐标已经排查过了\n");
			}
			else
			{
				if (mine[x][y] == '1')
				{
					printf("嘭！！你被炸死了！！\n");
					displayboard(mine, row, col);
					break;
				}
				else
				{
					touch(mine, show, x, y);
					displayboard(show, row, col);
				}
			}
		}
		else
		{
			printf("输入的坐标非法，请重新输入\n");
		}
	}
}

int getminecount(char mine[ROWS][COLS], int x,int y)
{
	return mine[x - 1][y - 1] +
		mine[x - 1][y + 1] +
		mine[x - 1][y] +
		mine[x + 1][y - 1] +
		mine[x + 1][y + 1] +
		mine[x + 1][y] +
		mine[x][y - 1] +
		mine[x][y + 1]-48*8;
}

void touch(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
	{
		show[x][y] = getminecount(mine, x , y) + 48;
		if ((!getminecount(mine, x, y)) && (show[x + 1][y] == '*'))
		{
			touch(mine, show, x + 1, y);
		}
		if ((!getminecount(mine, x, y)) && (show[x + 1][y - 1] == '*'))
		{
			touch(mine, show, x + 1, y - 1);
		}
		if ((!getminecount(mine, x, y)) && (show[x + 1][y + 1] == '*'))
		{
			touch(mine, show, x + 1, y + 1);
		}
		if ((!getminecount(mine, x, y)) && (show[x - 1][y + 1] == '*'))
		{
			touch(mine, show, x - 1, y + 1);
		}
		if ((!getminecount(mine, x, y)) && (show[x - 1][y - 1] == '*'))
		{
			touch(mine, show, x - 1, y - 1);
		}
		if ((!getminecount(mine, x, y)) && (show[x - 1][y] == '*'))
		{
			touch(mine, show, x - 1, y);
		}
		if ((!getminecount(mine, x, y)) && (show[x][y + 1] == '*'))
		{
			touch(mine, show, x, y + 1);
		}
		if ((!getminecount(mine, x, y)) && (show[x][y - 1] == '*'))
		{
			touch(mine, show, x, y - 1);
		}
	}
}
int countmine(char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1;i <= row;i++)
	{
		for (j = 1;j <= row;j++)
		{
			if (show[i][j] == '*')
				count++;
		}
	}
	return count;
}