#include "Sort.h"
#include <time.h>


void FillArray(int *array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		array[i] = rand() % 10;
	}
}

void PrintArray(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

int main() 
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	int  size;
	cout << "������� ������ �������: ";
	cin >> size;
	int *array = new int[size];

	FillArray(array, size);
	cout << "�������� ������, ����������� ���������� �������:" << endl;
	PrintArray(array, size);
	quickSort(array, size - 1);
	cout << "��������������� ������:" << endl;
	PrintArray(array, size);

	delete[] array;
	system("pause");
}
