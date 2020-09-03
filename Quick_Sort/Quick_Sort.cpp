#include "Quick_Sort.h"

void sort(vector<int>& arr)
{
	quicksort(arr, 0, arr.size() - 1);
	printArr(arr);
}

void printArr(vector<int> arr)
{
	cout << " { ";
	for (auto a : arr)
	{
		cout << a << " ";
	}
	cout << "}" << endl;
}

void quicksort(vector<int>& arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}

int partition(vector<int>& arr, int low, int high)
{
	int pivot = arr[high];	//pivot value
	int i = 0;	//iterator values less then pivot value (arr[i] < pivot)

	for (int j = 0; j < high; ++j)
		if (arr[j] <= pivot)
			swap(arr[i++], arr[j]);

	swap(arr[i], arr[high]);
	return i;
}