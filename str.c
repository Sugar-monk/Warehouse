#include <stdio.h>
#include<assert.h>
#include<stdlib.h>


//实现strcpy:
char* my_strcpy(char* goal, const char* source)
{
	char* tmp = goal;

	assert(goal != NULL);
	assert(source != NULL);
	while (*goal++ = *source++)
		;
	return tmp;
}

//实现strlen：
char my_strlen(const char* tmp)
{
	char count = 0;
	assert(tmp);
	while (*tmp)
	{
		count++;
		tmp++;
	}
	return count;
}

//实现strcat函数
//在一个字符串后追加一个字符串

char* my_strcat(char* goal, const char* source)
{
	char* tmp = goal;
	assert(goal != NULL);
	assert(source != NULL);

	while (*goal)
	{
		goal++;
	}
	while (*goal++ = *source++)
		;
	return tmp;
}

//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。找出这两个数字，编程实现。

void findmun(char arr[], char arr1[], int size)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = 0; i <= size; i++)
	{
		int count = 0;
		for (j = 0; j <= size; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}
			if (count >= 2)
				break;
		}
		if (count == 1)
		{
			arr1[tmp] = arr[i];
			tmp++;
		}
	}
}
//比较两个字符串

int my_strcmp(const char *str1, const char *str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);

	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return 0;
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

//实现函数strstr

char *My_strstr(const char *str1, const char *str2)
{
	const char *tmp = str1;
	const char *s1 = str1;
	const char *s2 = str2;
	assert(str1 != NULL);
	assert(str2 != NULL);
	while (*tmp)
	{
		s1 = tmp;
		s2 = str2;
		while ( (*s1) && (*s2) && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return (char*)tmp;
		}
		tmp++;
	}
	return NULL;
}

//实现memcopy：不考虑元素类型的拷贝
//size_t :适于计量内存中可容纳的数据项目个数的无符号整数类型”

void *my_memcopy(void *dest, void *src, size_t data)
{
	assert(dest != NULL);
	assert(src != NULL);
	void *ret = dest;             //将目标地址存储，之后会被改掉
	char *pd = (char *)dest;      //强制类型转换，为了后面方便
	char *ps = (char *)src;
	while (data--)                //开始循环
	{
		*pd++ = *ps++;           //开始拷贝
	}
	return ret; 
}

//实现memmove:如果目标的地址在拷贝的地址前面，用从前往后的方法去拷贝，其他的用从后往前的方法

void *My_memmove(void *dest, void *src, size_t count)
{
	assert(dest != NULL);
	assert(src != NULL);
	char *ret = dest;
	char *pd = (char *)dest;      //强制类型转换，为了后面方便
	char *ps = (char *)src;
	if (dest <= src)
	{
		while (count--)                //开始循环
		{
			*pd++ = *ps++;           //开始拷贝
		}
	}
	else
	{
		while (count--)
		{
			*(pd + count) = *(ps + count);
		}
	}
	return ret;
}
int main()
{
	//实现str类型函数
	int arr1[] = { 1, 5, 9, 4, 5, 6, 7, 8 };
	int arr2[] = { 1, 2, 3, 4, 5, 6 ,7,8,9,10};
	/*char arr1[] = "edcba";
	char arr2[] = "abcdefg";
	int ret = 0;*/
#if 0
	my_strcpy(arr1, arr2);
	my_strcat(arr1, arr2);
	printf("%s\n", arr1);*/
	ret = my_strcmp(arr1, arr2);
	printf("%d\n", ret);
	printf("%s \n", My_strstr(arr1, arr2));
#endif
	My_memmove(arr2, arr2+2,16);
	return 0;
}


////作业
//
////一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。找出这两个数字，编程实现。
//
//int main()
//{
//	int i = 0;
//	char arr1[] = { 0, 0 };
//	char arr[] = { 1, 2, 4, 5, 4, 1, 2, 3 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	findmun(arr, arr1, size);
//	while (i < 2)
//	{
//		printf("%d\n", arr1[i]);
//		i++;
//	}
//
//	return 0;
//}
//
//
////喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水。编程实现。
//int main()
//{
//	
//	int coal = 20;                         //喝了汽水个数
//	int change = coal / 2;                 //换了汽水的个数
//	int surplus = coal % 2;                //剩余汽水的个数
//	while (change != 0)
//	{
//		coal += change;
//		change += surplus;
//		surplus = change % 2;
//		change = change / 2;
//	}
//	printf("coal = %d  change = %d  surplus = %d \n", coal, change, surplus);
//	return 0;
//}