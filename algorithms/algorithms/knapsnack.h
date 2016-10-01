#pragma once
#include<iostream>
using namespace std;

struct Item
{
	int value, weight;
	Item(int value, int weight) :value(value), weight(weight) {}
};

bool cmp(struct Item a, struct Item b)
{
	double r1 = (double)a.value / a.weight;
	double r2 = (double)b.value / b.weight;
	return r1 > r2;
}
/*
An efficient solution is to use Greedy approach. The basic idea of greedy 
approach is to calculate the ratio value/weight for each item and sort the 
item on basis of this ratio. Then take the item with highest ratio and add 
them until we can’t add the next item as whole and at the end add the next item as
much as we can. Which will always be optimal solution of this problem.*/

double fraction_knapsnack(int W, struct Item arr[], int n)
{
	// sort(arr, arr+n, cmp)
	int curWeight = 0;  // Current weight in knapsack
	double finalvalue = 0.0; // Result (value in Knapsack)

							 // Looping through all Items
	for (int i = 0; i < n; i++)
	{
		// If adding Item won't overflow, add it completely
		if (curWeight + arr[i].weight <= W)
		{
			curWeight += arr[i].weight;
			finalvalue += arr[i].value;
		}

		// If we can't add current Item, add fractional part of it
		else
		{
			int remain = W - curWeight;
			finalvalue += arr[i].value * ((double)remain / arr[i].weight);
			break;
		}
	}

	// Returning final value
	return finalvalue;
}