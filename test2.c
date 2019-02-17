#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void GameIterface()
{
	printf("************************\n");
	printf("**** 0-99猜数字游戏 ****\n");
	printf("**  1.开始   0.退出   **\n");
	printf("************************\n");
	printf("请输入数字：");
}

void Game1()
{
	int a = 0;
	int tmp = 0;
	srand(time(NULL));
	a = rand() % 100;		//生成随机数
	printf("请输入数字：");
	scanf("%d", &tmp);
	while (1)				//开始执行判断游戏
	{
		if (tmp == a)
		{
			printf("恭喜猜对了！\n");
			printf("1.继续   0.退出\n");
			printf("请选择：");
			break;
		}
		else if(tmp > a)
		{
			printf("猜大了！\n");
			printf("请输入数字：");
			scanf("%d", &tmp);
		}
		else if (tmp < a)
		{
			printf("猜小了！\n");
			printf("请输入数字：");
			scanf("%d", &tmp);
		}

	}
}
void Game()
{
	int get = 0;
	GameIterface();   //打印游戏开始界面
	while (1)
	{
		get = scanf("%d", &get);
		if (get == 0)		//判断是否继续游戏
			Game1();	//开始游戏
		else
			printf("再见！！\n");
			break;
	}
}
int main()
{
	Game();
	return 0;
}