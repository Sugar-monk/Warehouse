#include <stdio.h>
#include<assert.h>
#include<stdlib.h>


//ʵ��strcpy:
char* my_strcpy(char* goal, const char* source)
{
	char* tmp = goal;

	assert(goal != NULL);
	assert(source != NULL);
	while (*goal++ = *source++)
		;
	return tmp;
}

//ʵ��strlen��
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

//ʵ��strcat����
//��һ���ַ�����׷��һ���ַ���

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

//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ��ҳ����������֣����ʵ�֡�

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
//�Ƚ������ַ���

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

//ʵ�ֺ���strstr

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

//ʵ��memcopy��������Ԫ�����͵Ŀ���
//size_t :���ڼ����ڴ��п����ɵ�������Ŀ�������޷����������͡�

void *my_memcopy(void *dest, void *src, size_t data)
{
	assert(dest != NULL);
	assert(src != NULL);
	void *ret = dest;             //��Ŀ���ַ�洢��֮��ᱻ�ĵ�
	char *pd = (char *)dest;      //ǿ������ת����Ϊ�˺��淽��
	char *ps = (char *)src;
	while (data--)                //��ʼѭ��
	{
		*pd++ = *ps++;           //��ʼ����
	}
	return ret; 
}

//ʵ��memmove:���Ŀ��ĵ�ַ�ڿ����ĵ�ַǰ�棬�ô�ǰ����ķ���ȥ�������������ôӺ���ǰ�ķ���

void *My_memmove(void *dest, void *src, size_t count)
{
	assert(dest != NULL);
	assert(src != NULL);
	char *ret = dest;
	char *pd = (char *)dest;      //ǿ������ת����Ϊ�˺��淽��
	char *ps = (char *)src;
	if (dest <= src)
	{
		while (count--)                //��ʼѭ��
		{
			*pd++ = *ps++;           //��ʼ����
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
	//ʵ��str���ͺ���
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


////��ҵ
//
////һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ��ҳ����������֣����ʵ�֡�
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
////����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֡�
//int main()
//{
//	
//	int coal = 20;                         //������ˮ����
//	int change = coal / 2;                 //������ˮ�ĸ���
//	int surplus = coal % 2;                //ʣ����ˮ�ĸ���
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