#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <vector>

using namespace std;

void	merge(vector<int>& arr, int low, int mid, int high);
void	mergeSort(vector<int>& arr, int low, int high);
void	sort(vector<int>& arr);
void	printArr(vector<int> arr);

#endif

