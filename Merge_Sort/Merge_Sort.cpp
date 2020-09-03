#include "Merge_Sort.h"

void merge(vector<int>& arr, int low, int mid, int high)
{
	int s1 = mid - low + 1;		//left half size for temp arr
	int s2 = high - mid;		//right halfe size for temp arr

	vector<int> left;
	vector<int> right;

	for (int i = 0; i < s1; ++i) //copy left side temp arr
		left.push_back(arr[low + i]);

	for (int j = 0; j < s2; ++j) //copy right side temp arr
		right.push_back(arr[mid + 1 + j]);

	int x = 0;		//iterator for left temp arr
	int y = 0;		//iterator for right temp arr
	int z = low;	//iterator on original arr

	for (int i = 0; i < s1 + s2; ++i)
	{
		if (x >= s1)	arr[z++] = right[y++];
		else if (y >= s2)	arr[z++] = left[x++];
		else if (left[x] <= right[y])	arr[z++] = left[x++];
		else if (right[y] < left[x])	arr[z++] = right[y++];
	}
}


void mergeSort(vector<int>& arr, int low, int high)
{
	if (low < high)
	{
		int mid = (high - low) / 2 + low;

		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);

		merge(arr, low , mid, high);
	}
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

void sort(vector<int>& arr)
{
	mergeSort(arr, 0, arr.size() - 1);
	printArr(arr);
}