#pragma once
/* C++ Program for Binary Search */
#include<iostream>

using namespace std;
int binary_search(int arr[], int left, int right, int x)
{
	/*
	input: array int is sorted
	return : location of x in given array[l..r], otherwise -1
	*/
	if (right >= left) 
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] == x) return mid;
		if (arr[mid] > x) return binary_search(arr, left, mid -1,x );

		return binary_search(arr, mid+1, right, x );
	}
	// otherwise
	return -1;
}

void run_test_binary_search()
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 10;
	int result = binary_search(arr, 0, n - 1, x);
	(result == -1) ? cout << "Element not present in array\n"
		: cout << "Element is present at index " << result << endl;
}
