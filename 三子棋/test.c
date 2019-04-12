#include "game.h"
void menu()
{
	printf("  ★★★★★★★★★★★★★★★★★★\n");
	printf(" ★★★                          ★★★\n");
	printf("★★★  1.开始游戏     0.结束游戏 ★★★\n");
	printf(" ★★★                          ★★★\n");
	printf("  ★★★★★★★★★★★★★★★★★★\n");
	printf("请选择：");
}
void game()
{
	char board[ROW][LINE] = { 0 };
	Initboard(board, ROW, LINE);              //初始化棋盘
	Printfboard(board, ROW, LINE);            //打印棋盘
	while (1)
	{
		Player_Runboard(board, ROW, LINE);                   //玩家开始下棋
		computer_Runboard(board, ROW, LINE);                 //电脑开始下棋
		Printfboard(board, ROW, LINE);
		judgeboard(board, ROW, LINE);                       //判断输赢
		if (judgeboard(board, ROW, LINE) == 'X')
		{
			printf("玩家赢！！\n");
			break;
		}
		else if (judgeboard(board, ROW, LINE) == '@')
		{
			printf("电脑赢！！\n");
			break;
		}
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！！\n");
			break;
		default:
			printf("选择错误！！\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}