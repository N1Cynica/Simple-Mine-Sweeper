#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>



#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define easy_count 10
#define normal_count 20



void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void displayboard(char board[ROWS][COLS], int row, int col);
void setmine(char board[ROWS][COLS], int row, int col,int count);
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int getminecount(char mine[ROWS][COLS],int x, int y);
void touch(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
int countmine(char show[ROWS][COLS], int row, int col);