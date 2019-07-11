#include <iostream>
using namespace std;

void mergeArrays(int[], int[], int, int, int[]);
void printArray(int[], int);

int main()
{
	cout << "Testing Normal Arrays" << endl;
	int arr1[5] = {1, 3, 5, 7, 9};
	int arr2[10] = {2, 4, 6, 8, 10, 12, 25, 29, 30, 31};
	int result[5 + 10];

	mergeArrays(arr1, arr2, 5, 10, result);
	printArray(result, 5 + 10);

	cout << endl;

	cout << "Testing with 1 Empty Array" << endl;
	int arr3[5] = {1, 2, 3, 4, 5};
	int arr4[0];
	int result2[5];

	mergeArrays(arr3, arr4, 5, 0, result2);
	printArray(result2, 5);

	cout << endl;

	cout << "Testing with 2 Empty Arrays" << endl;
	int arr5[0];
	int arr6[0];
	int result3[0];

	mergeArrays(arr5, arr6, 0, 0, result3);
	printArray(result3, 0);

	return 0;
}

void mergeArrays(int arr1[], int arr2[], int size1, int size2, int result[])
{
	if (size1 <= 0 && size2 <= 0)
	{
		return;
	}
	else if (size1 <= 0)
	{
		for (int i = 0; i < size2; i++)
		{
			result[i] = arr2[i];
		}
		return;
	}
	else if (size2 <= 0)
	{
		for (int i = 0; i < size1; i++)
		{
			result[i] = arr1[i];
		}
		return;
	}

	int index1 = 0;
	int index2 = 0;

	for (int i = 0; i < (size1 + size2); i++)
	{
		if (index1 >= size1 && index2 >= size2)
		{
			break;
		}

		bool first = index2 >= size2 || (index1 < size1 && arr1[index1] < arr2[index2]);

		if (first)
		{
			result[i] = arr1[index1];
			index1++;
		}
		else
		{
			result[i] = arr2[index2];
			index2++;
		}
	}
}

void printArray(int arr[], int size)
{
	if (size <= 0)
	{
		cout << "[]" << endl;
		return;
	}

	cout << "[ ";

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}

	cout << ']' << endl;
}
