#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <vector>

using namespace std;

void	printArr(vector<int> arr);
void	sort(vector<int>& arr);
void	quicksort(vector<int> &arr, int low, int high);
int	partition(vector<int>& arr, int low, int high);

#endif
