int Find()
{
	int arr[] = { 1, 2, 3, 5, 6, 7, 8, 9, 10 };
	int lift = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int mid = 0;
	int a = 0;//Ҫ���ҵ�����
	for (int i = 0; i <= right; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n������Ҫ���ҵ����֣�");
	scanf("%d", &a);
	while (right >= lift)
	{
		mid = lift + ((right - lift) / 2);
		if (arr[mid] > a)
			right = mid - 1;
		else if (arr[mid] < a)
			lift = mid + 1;
		else if (arr[mid] = a)
		{
			return mid;
		}
	}
	return -1;
}

int main()
{
	int tmp = 0;
	tmp = Find();
	if (tmp == -1)
		printf("û���ҵ���\n");
	else
		printf("�ҵ���,�±�Ϊ%d\n", tmp);
	return 0;
}