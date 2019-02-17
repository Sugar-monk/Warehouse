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