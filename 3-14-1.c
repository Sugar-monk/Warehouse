//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
////int main()
////{
////	int n = 0;
////	size_t sum = 1;
////	printf("������һ������");
////	scanf("%d", &n);
////
////	while (n > 1)
////	{
////		sum *= n--;
////	}
////	printf("%d\n", sum);
////	return 0;
////}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	char and;
//	printf("�������������㣺");
//	scanf("%d%s%d", &a, &and, &b);
//	switch (and)
//	{
//	case('*') :
//	{
//				  printf("%d * %d = %d\n", a, b, a*b);
//				  break;
//	}
//	case('+') :
//	{
//				  printf("%d + %d = %d\n", a, b, a + b);
//				  break;
//	}case('-') :
//	{
//		printf("%d - %d = %d\n", a, b, a - b);
//		break;
//	}case('/') :
//	{
//		printf("%d / %d = %d \n", a, b, a / b);
//		break;
//	}
//	default:
//	{
//			   printf("����ȷ���룡��");
//			   break;
//	}
//
//
//	}
//	return 0;
//}

#include <stdio.h>

int main()
{
	int num = 0;
	int count = 0;

	printf("������һ����������λ��������");

	scanf("%d", &num);
	if (!(num / 10000))					//������������λ��ִ�г����������ֱ���˳�	(�����³����)
	{
		printf("�Ӹ�λ��ʼ���Ϊ��");
		while (num)						//�����������������ѭ��
		{
			count++;					//���������Ƿ���count++��
			printf("%d ", num % 10);	//��ӡ��λ������
			num = num / 10;				//�����������ƶ�		eg��123->12->3->0
		}

		printf("\n λ��Ϊ��%d \n", count);
	}
	return 0;
}