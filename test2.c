#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void GameIterface()
{
	printf("************************\n");
	printf("**** 0-99��������Ϸ ****\n");
	printf("**  1.��ʼ   0.�˳�   **\n");
	printf("************************\n");
	printf("���������֣�");
}

void Game1()
{
	int a = 0;
	int tmp = 0;
	srand(time(NULL));
	a = rand() % 100;		//���������
	printf("���������֣�");
	scanf("%d", &tmp);
	while (1)				//��ʼִ���ж���Ϸ
	{
		if (tmp == a)
		{
			printf("��ϲ�¶��ˣ�\n");
			printf("1.����   0.�˳�\n");
			printf("��ѡ��");
			break;
		}
		else if(tmp > a)
		{
			printf("�´��ˣ�\n");
			printf("���������֣�");
			scanf("%d", &tmp);
		}
		else if (tmp < a)
		{
			printf("��С�ˣ�\n");
			printf("���������֣�");
			scanf("%d", &tmp);
		}

	}
}
void Game()
{
	int get = 0;
	GameIterface();   //��ӡ��Ϸ��ʼ����
	while (1)
	{
		get = scanf("%d", &get);
		if (get == 0)		//�ж��Ƿ������Ϸ
			Game1();	//��ʼ��Ϸ
		else
			printf("�ټ�����\n");
			break;
	}
}
int main()
{
	Game();
	return 0;
}