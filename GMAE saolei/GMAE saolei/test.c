#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	setmine(mine, ROW, COL, easy_count);
	displayboard(show, ROW, COL);
	//displayboard(mine, ROW, COL);
	findmine(mine, show, ROW, COL);
}
void menu()
{
	printf("*******************************\n");
	printf("**********  1.play  ***********\n");
	printf("**********  0.exit  ***********\n");
	printf("*******************************\n");
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("«Î—°‘Ò£∫");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("ÕÀ≥ˆ\n");
			break;
		default:
			printf(" ‰»Î¥ÌŒÛ\n");
		}
	} while (1);
}