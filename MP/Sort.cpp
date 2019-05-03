#include "Sort.h"

void quickSort(int *array, int lastIndex)
{
	int leftBorder = 0;
	int rightBorder = lastIndex;
	int centerElement = array[lastIndex / 2];

	do
	{
		while (array[leftBorder] < centerElement)
		{
			leftBorder++;
		}
		while (array[rightBorder] > centerElement)
		{
			rightBorder--;
		}

		if (leftBorder <= rightBorder)
		{
			swap(array[leftBorder], array[rightBorder]);
			leftBorder++;
			rightBorder--;
		}
	} 
	while (leftBorder <= rightBorder);
	

#pragma omp parallel shared(array)
	{
		//cout << omp_get_thread_num() << endl;
		if (rightBorder > 0)
		{
			quickSort(array, rightBorder);
		}
	}
#pragma omp parallel shared(array)
	{
		//cout << omp_get_thread_num() << endl;
		if (lastIndex > leftBorder)
		{
			quickSort(array + leftBorder, lastIndex - leftBorder);
		}
	}
}

