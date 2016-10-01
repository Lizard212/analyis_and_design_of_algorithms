#pragma once
/* Program for merge sort*/
#include<iostream>
#include"common.h"
#define MAX_INDEX 100
using namespace std;



void merge(int arr[], int left, int mid, int right)
{
	/*
	Merges two subarrays of arr[]
	*/
	int temp_arr[MAX_INDEX];

	
	int i, j, k, h;
	i = left; // Initial index of first subarray
	j = mid +1 ;
	k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
		{
			temp_arr[k] = arr[i];
			i++;
		}
		else
		{
			temp_arr[k] = arr[j];
			j++;
		}
		k++;
	}

	while (i <= mid)
	{
		temp_arr[k] = arr[i];
		i++;
		k++;
	}
	while (j <= right)
	{
		temp_arr[k] = arr[j];
		j++;
		k++;
	}

	for (h = left; h <=right; h++) { arr[h] = temp_arr[h]; }
	
}

void merge_sort(int arr[], int left , int right )
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		// Sort fisrt and second halves
		merge_sort(arr, left, mid );
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

void run_test_merge_sort()
{
	int arr[] = { 12,11,13,5,6,7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	cout << "Given array is \n";
	print_array(arr, arr_size);

	merge_sort(arr, 0, arr_size-1);

	cout << "Sorted array is \n";
	print_array(arr, arr_size);
 }