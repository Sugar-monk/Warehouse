int partion_2(int array[], int left,int right)
{
	int pivot = array[right];
	int begin = left;
	int end = right;
	while (begin < end)
	{
		while (begin < end && array[begin] <= pivot)
		{
			begin++;
		}
		if (begin == end)
		{
			break;
		}
		array[end] = array[begin];
		while (begin < end && array[end] >= pivot)
		{
			end--;
		}
		array[begin] = array[end];
	}
}

int partion_3(int array[], int left, int right)
{
	for (int div = left;)

}