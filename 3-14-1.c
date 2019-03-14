//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
////int main()
////{
////	int n = 0;
////	size_t sum = 1;
////	printf("请输入一个数：");
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
//	printf("请输入四则运算：");
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
//			   printf("请正确输入！！");
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

	printf("请输入一个不超过四位的整数：");

	scanf("%d", &num);
	if (!(num / 10000))					//如果这个数是四位数执行程序，如果不是直接退出	(代码的鲁棒性)
	{
		printf("从个位开始逐个为：");
		while (num)						//如果这个数不是零进入循环
		{
			count++;					//如果这个数是非零count++；
			printf("%d ", num % 10);	//打印个位的数字
			num = num / 10;				//让数字向右移动		eg：123->12->3->0
		}

		printf("\n 位数为：%d \n", count);
	}
	return 0;
}