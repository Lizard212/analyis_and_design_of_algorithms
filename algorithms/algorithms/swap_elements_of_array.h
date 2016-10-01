#pragma once
/*Program for swap sub array*/

#include<iostream>
#include"common.h"
using namespace std;

void swap(int arr[], int fi, int si, int d)
{
	/*This function swaps d elements starting at index fi with d elements starting at index si*/
	int i, temp;
	for (int i = 0; i < d; i++)
	{
		temp = arr[fi + i];
		arr[fi + i] = arr[si + i];
		arr[si + i] = temp;
	}
}

void left_rotate(int arr[], int d, int n)
{
	if (d == 0 || n == 0)
		return;
	/*If number of elements to be rotated is exactly 
	half of array size*/
		if (n - d == d)
		{
			swap(arr, 0, n - d, d);
			return;
		}

		if (d < n - d)
		{
			swap(arr, 0, n - d, d);
			left_rotate(arr, d, n-d);
		}
		else
		{

			swap(arr, 0, d, n - d);
			left_rotate(arr + n - d, 2 * d - n, d); /*This is tricky*/
		}


}

void run_test_swap_array()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	left_rotate(arr, 4, 7);
	print_array(arr, 7);

}