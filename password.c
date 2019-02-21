void GameFace()
{
	printf("************************\n");
	printf("**  请在下方输入密码  **\n");
	printf("************************\n");

}
#define Password 552255
void PassWord()
{
	int count = 3;
	int num = 0;
	//输入界面
	GameFace();
	//生成密码
	int pw = Password;
	//开始输入密码，输错后提示剩余机会
	while (count--)
	{
		printf("请输入密码：");
		scanf("%d", &num);
		if (num == pw)
		{
			printf("密码正确！！\n");
			return 0;
		}
		if (count > 0)
			printf("密码输入错误，还剩%d次机会！\n", count);
	}
	//三次机会后，提示机会用尽，退出程序
	printf("机会已经用尽！再见\n");
}