void GameFace()
{
	printf("************************\n");
	printf("**  �����·���������  **\n");
	printf("************************\n");

}
#define Password 552255
void PassWord()
{
	int count = 3;
	int num = 0;
	//�������
	GameFace();
	//��������
	int pw = Password;
	//��ʼ�������룬������ʾʣ�����
	while (count--)
	{
		printf("���������룺");
		scanf("%d", &num);
		if (num == pw)
		{
			printf("������ȷ����\n");
			return 0;
		}
		if (count > 0)
			printf("����������󣬻�ʣ%d�λ��ᣡ\n", count);
	}
	//���λ������ʾ�����þ����˳�����
	printf("�����Ѿ��þ����ټ�\n");
}