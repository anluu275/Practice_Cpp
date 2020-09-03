#include <iostream>
#include <vector>
#include "Merge_Sort.h"

using namespace std;

void MergeSortTest()
{
	vector<int> arr1 = { 5,2,3,4 };
	vector<int> arr2 = { 4,5,7,3,54,9,6,111,632,15,341,4,6,325,6 };
	vector<int> arr3 = { 1 };
	vector<int> arr4 = {  };

	
	printArr(arr1);
	sort(arr1);

	printArr(arr2);
	sort(arr2);

	printArr(arr3);
	sort(arr3);

	printArr(arr4);
	sort(arr4);
}

int main()
{
	MergeSortTest();
}