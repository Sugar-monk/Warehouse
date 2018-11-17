//5.求两个数的最大公约数//
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#if 1
//普通方法
int FindMaxFactor(int a, int b)
{
	if (a == 0 && b == 0)
		return 0;
	while (1)
	{
		int i = 0;
		if (a >= b)
		{
			for (i = b; i > 1; --i)
			{
				if ((a % i == 0) && (b % i == 0))
					return i;
			}
		}
		else if (a < b)
		{
			for (i = a; i > 1; --i)
			{
				if ((a % i == 0) && (b % i == 0))
					return i;
			}
		}
		else
			break;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int a = 0;
	int b = 0;
	a = rand() % 10;
	b = rand() % 10;
	printf("a = %d,b = %d\n%d\n", a, b, FindMaxFactor(a, b));
	return 0;
}
#endif

//辗转相减法
#if 0
int main()
{
	srand((unsigned)time(NULL));
	int a = 0;
	int b = 0;
	int Max = 0;
	a = rand() % 10;
	b = rand() % 10;
	printf("%d\n", a);
	printf("%d\n", b);
	while (1)
	{
		if (a > b)
		{
			a -= b;
		}
		else if (b > a)
		{
			b -= a;
		}
		else break;
	}
	printf("%d\n", a);

	return 0;
}
#endif