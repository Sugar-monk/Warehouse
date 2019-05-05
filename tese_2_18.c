
//ֱ�Ӳ�������
void InsertSort(int array[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int j = 0;
		int k = array[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (array[j] <= k)
				break;
			array[j] = array[j + 1];
		}
		array[j + 1] = k;
	}
}

//ð������
//ʱ�临�Ӷ�
//�        O(n ^ 2)        �Ѿ�����
//ƽ��        O(n ^ 1.3)
//���        O(n)             ����
//�ռ临�Ӷ�O(1)
//�ȶ�

void BubbleSort(int array[], int size)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}

//ӵ��gap�Ĳ���
void InsertSortWhitGap(int array[], int size, int gap)
{
	for (int i = gap; i < size; i++)
	{
		int j = 0;
		int k = array[i];
		for (j = i - gap; j >= 0; j -= gap)
		{
			if (array[j] <= k)
				break;
			array[j] = array[j + gap];
		}
		array[j + gap] = k;
	}
}

//ϣ������
//ʱ�临�Ӷ�
//�        O(n ^ 2)        ��Ҫ���Թ���
//ƽ��        O(n ^ 1.3)		
//���        O(n)             ����
//�ռ临�Ӷ�O(1)
//���ȶ�
void ShellSort(int array[], int size)
{
	int gap = size;
	while (1)
	{
		gap = (gap / 3) + 1;
		InsertSortWhitGap(array, size, gap);
		if (1 == gap)
			break;
	}
}

//ѡ������
//ʱ�临�Ӷȣ�O(n^2)
//�ռ临�Ӷȣ�O(1)
//���ȶ������ݲ����У�������Դ��ʲô���ݣ�����Ӱ��ִ��ʱ�䣩

//ѡ������ֱ��������
void SelectSort(int array[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int max = 0;
		for (int j = 1; j <= size - i; j++)
		{
			if (array[j] >= array[max])
				max = j;
		}
		int tmp = array[max];
		array[max] = array[size - 1];
		array[size - 1] = tmp;
	}
}

//������ѡ������ͬʱ��������Сֵ
void SelectSortP(int array[], int size)
{
	int minSpace = 0;
	int maxSpace = size - 1;

	while (minSpace < maxSpace)
	{
		int min = minSpace;
		int max = maxSpace;

		//�����������С��
		for (int i = minSpace + 1; i <= maxSpace; i++)
		{
			if (array[i] < array[min])
				min = i;
			if (array[i] > array[max])
				max = i;
		}

		//��ʼ����

		//�Ƚ���С��
		int tmp = array[min];
		array[min] = array[minSpace];
		array[minSpace] = tmp;

		//�������±����С���±��г�ͻ
		if (max == minSpace)
			max == min;
		//�ڽ������
		int tmp = array[max];
		array[max] = array[maxSpace];
		array[maxSpace] = tmp;

		minSpace++;
		maxSpace--;
	}
}

//������
//ʱ�临�Ӷ� O(n*logn)
//�ռ临�Ӷ� O��1��
//���ȶ�
//���ݲ�����

//root��ʾҪ��ʼ�����Ľڵ��±�
//�����

//���µ�������,
void AdjustDown(int array[], int size, int root)
{
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	//Ҫ�����ڵ���Ϊ����
	while (left < size)
	{
		//�����������д��һ����ֻ��һ������´��һ�����Һ��ӣ����Һ��ӣ������Һ��ӵ�ֵ>���ӵ�ֵ
		int	max = left;			//������������
		if (right < size && array[right] > array[left])
			max = right;
		if (array[root] > array[max])		//������ڵ����Ҷ�ӽ���е����ֵ���˳�
			break;

		//���򽻻�
		int t = array[root];
		array[root] = array[max];
		array[max] = t;

		root = max;
		left = 2 * root + 1;
		right = 2 * root + 2;
	}
}

void CreateHeat(int array[], int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		AdjustDown(array, size, i);
	}
	for (int i = 1; i < size; i++)
	{
		int t = array[0];
		array[0] = array[size - 1];
		array[size - 1] = t;

		AdjustDown(array, size - i, 0);
	}
}