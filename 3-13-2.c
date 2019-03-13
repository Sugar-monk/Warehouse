#include <stdio.h>
int main()
{
	int line=0;
	int i;
	scanf("%d",&line);
	for(i=0;i<line;i++)
	{
		int j=0;
		for(j=0;j<line-1-i;j++)
		{
				printf(" ");
		}
		for(j=0;j<i*2+1;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for(i=0;i<line-1;i++)
	{
		int j=0;
		for(j=0;j<i+1;j++)
		{
				printf(" ");
		}
		for(j=0;j<2*(line-1-i)-1;j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}