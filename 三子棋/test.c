#include "game.h"
void menu()
{
	printf("  �������������������\n");
	printf(" ����                          ����\n");
	printf("����  1.��ʼ��Ϸ     0.������Ϸ ����\n");
	printf(" ����                          ����\n");
	printf("  �������������������\n");
	printf("��ѡ��");
}
void game()
{
	char board[ROW][LINE] = { 0 };
	Initboard(board, ROW, LINE);              //��ʼ������
	Printfboard(board, ROW, LINE);            //��ӡ����
	while (1)
	{
		Player_Runboard(board, ROW, LINE);                   //��ҿ�ʼ����
		computer_Runboard(board, ROW, LINE);                 //���Կ�ʼ����
		Printfboard(board, ROW, LINE);
		judgeboard(board, ROW, LINE);                       //�ж���Ӯ
		if (judgeboard(board, ROW, LINE) == 'X')
		{
			printf("���Ӯ����\n");
			break;
		}
		else if (judgeboard(board, ROW, LINE) == '@')
		{
			printf("����Ӯ����\n");
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
			printf("�˳���Ϸ����\n");
			break;
		default:
			printf("ѡ����󣡣�\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}