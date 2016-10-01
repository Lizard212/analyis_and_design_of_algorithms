#pragma once
/*Program for Quick Sort*/
#include"common.h"
#include<iostream>

using namespace std;

int partition(int arr[], int left, int right)
{
	int pivot = arr[right];
	int i = (left - 1);
	int j;
	for (  j = left; j <= right -1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}

	}
	swap(&arr[i + 1], &arr[right]);
	return (i + 1);
}

void quick_sort(int arr[], int left, int right)
{
	if (left < right)
	{
		int pi = partition(arr, left, right);
		/* pi is partition index , arr[p] is now at right place*/
		quick_sort(arr, left, pi - 1);
		quick_sort(arr, pi + 1, right);

	}
}

void run_test_quick_sort()
{
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	quick_sort(arr, 0, n - 1);
	printf("Sorted array: \n");
	print_array(arr, n);
}