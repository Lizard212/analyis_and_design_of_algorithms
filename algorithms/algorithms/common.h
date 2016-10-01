#pragma once
#include<stdio.h>
// utility functions

void print_array(int arr[], int size)
{
	int i;
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}