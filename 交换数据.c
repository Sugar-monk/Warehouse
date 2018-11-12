#include<stdio.h>
int main()
{
	int a,b,c;
	a=10;
	b=20;
	c=a;
	a=b;
	b=c;
	printf("a=%d\nb=%d\n",a,b);
	return 0;
}
#include<stdio.h>
int main()
{
	int a,b;
	a=10;
	b=20;
	a=a+b;
	b=a-b;
	a=a-b;
	printf("a=%d\nb=%d\n",a,b);
	return;
}
