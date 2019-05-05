
//直接插入排序
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

//冒泡排序
//时间复杂度
//最坏        O(n ^ 2)        已经逆序
//平均        O(n ^ 1.3)
//最好        O(n)             有序
//空间复杂度O(1)
//稳定

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

//拥有gap的插排
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

//希尔排序
//时间复杂度
//最坏        O(n ^ 2)        需要可以构造
//平均        O(n ^ 1.3)		
//最好        O(n)             有序
//空间复杂度O(1)
//不稳定
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

//选择排序
//时间复杂度：O(n^2)
//空间复杂度：O(1)
//不稳定，数据不敏感（无论来源是什么数据，都不影响执行时间）

//选择排序：直接找最大的
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

//升级版选择排序：同时找最大和最小值
void SelectSortP(int array[], int size)
{
	int minSpace = 0;
	int maxSpace = size - 1;

	while (minSpace < maxSpace)
	{
		int min = minSpace;
		int max = maxSpace;

		//找最大数和最小数
		for (int i = minSpace + 1; i <= maxSpace; i++)
		{
			if (array[i] < array[min])
				min = i;
			if (array[i] > array[max])
				max = i;
		}

		//开始交换

		//先交换小的
		int tmp = array[min];
		array[min] = array[minSpace];
		array[minSpace] = tmp;

		//如果大的下标和最小的下标有冲突
		if (max == minSpace)
			max == min;
		//在交换大的
		int tmp = array[max];
		array[max] = array[maxSpace];
		array[maxSpace] = tmp;

		minSpace++;
		maxSpace--;
	}
}

//堆排序
//时间复杂度 O(n*logn)
//空间复杂度 O（1）
//不稳定
//数据不敏感

//root表示要开始调整的节点下标
//建大堆

//向下调整函数,
void AdjustDown(int array[], int size, int root)
{
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	//要将根节点设为最大点
	while (left < size)
	{
		//找两个孩子中大的一个，只在一种情况下大的一个是右孩子：有右孩子，并且右孩子的值>左孩子的值
		int	max = left;			//假设大的是左孩子
		if (right < size && array[right] > array[left])
			max = right;
		if (array[root] > array[max])		//如果根节点大于叶子结点中的最大值，退出
			break;

		//否则交换
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