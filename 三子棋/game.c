#include "game.h"
void Initboard(char board[ROW][LINE], int row, int line)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < line; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void Printfboard(char board[ROW][LINE], int row, int line)
{
	int i = 0;
	int j = 0;
	for (i = 0; i<row; i++)
	{
		for (j = 0; j< line; j++)
		{
			printf(" %c ",board[i][j]);
			if (j<line-1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j< line; j++)
			{
				printf("---");
				if (j<line - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}
void Player_Runboard(char board[ROW][LINE], int row, int line)
{
	int x = 0;
	int y = 0;
	printf("玩家走：\n");
	while (1)
	{
		printf("请输入坐标:");
		scanf("%d%d", &x, &y);
		if ((x >= 1 && x <= (row + 1)) && (y >= 1 && y <= (line + 1)))
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'X';
				break;
			}
			else
			{
				printf("坐标已被占用\n");
			}
		}
		else
		{
			printf("坐标非法\n");
		}
	}
}
void computer_Runboard(char board[ROW][LINE])
{
	int x = 0;
	int y = 0;
	printf("电脑走：\n");
	while (1)
	{
		x = rand() % ROW;
		y = rand() % LINE;
		if (board[x][y] == ' ')
		{
			board[x][y] = '@';
			break;
		}
	}
}
char judgeboard(char board[ROW][LINE], int row, int line)
{
	int i = 0;
	for (i = 0; i < row; i++)                 //横向判断
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][1] !=' ')
		{
			return board[1][1];
		}
	}
	for (i = 0; i < row; i++)                 //竖向判断
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[1][1];
		}
	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')  // 右斜判断
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')  // 左斜判断
	{
		return board[1][1];
	}
}