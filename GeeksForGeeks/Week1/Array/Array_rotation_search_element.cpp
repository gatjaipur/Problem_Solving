/* C++ Program to search an element
in a sorted and pivoted array*/

// Time Complexity: O(log n). 
// Binary Search requires log n comparisons to find the element. So time complexity is O(log n).
// Space Complexity:O(1), No extra space is required.

#include <bits/stdc++.h>
using namespace std;

/* Standard Binary Search function*/
int binarySearch(int arr[], int low,
				int high, int key)
{
	if (high < low)
		return -1;

	int mid = (low + high) / 2; /*low + (high - low)/2;*/
	if (key == arr[mid])
		return mid;

	if (key > arr[mid])
		return binarySearch(arr, (mid + 1), high, key);

	// else
	return binarySearch(arr, low, (mid - 1), key);
}

/* Function to get pivot. For array 3, 4, 5, 6, 1, 2
it returns 3 (index of 6) */
int findPivot(int arr[], int low, int high)
{
	// base cases
	if (high < low)
		return -1;
	if (high == low)
		return low;

	int mid = (low + high) / 2; /*low + (high - low)/2;*/
	if (mid < high && arr[mid] > arr[mid + 1])
		return mid;

	if (mid > low && arr[mid] < arr[mid - 1])
		return (mid - 1);

	if (arr[low] >= arr[mid])
		return findPivot(arr, low, mid - 1);

	return findPivot(arr, mid + 1, high);
}

/* Searches an element key in a pivoted
sorted array arr[] of size n */
int pivotedBinarySearch(int arr[], int n, int key)
{
	int pivot = findPivot(arr, 0, n - 1);

	// If we didn't find a pivot,
	// then array is not rotated at all
	if (pivot == -1)
		return binarySearch(arr, 0, n - 1, key);

	// If we found a pivot, then first compare with pivot
	// and then search in two subarrays around pivot
	if (arr[pivot] == key)
		return pivot;

	if (arr[0] <= key)
		return binarySearch(arr, 0, pivot - 1, key);

	return binarySearch(arr, pivot + 1, n - 1, key);
}

/* Driver program to check above functions */
int main()
{
	// Let us search 3 in below array
	int arr1[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
	int n = sizeof(arr1) / sizeof(arr1[0]);
	int key = 3;

	// Function calling
	cout << "Index of the element is : "
		<< pivotedBinarySearch(arr1, n, key);

	return 0;
}

//Method 2 One pass of binary search

// Search an element in sorted and rotated
// array using single pass of Binary Search
#include <bits/stdc++.h>
using namespace std;

// Returns index of key in arr[l..h] if
// key is present, otherwise returns -1
// int search(int arr[], int l, int h, int key)
// {
// 	if (l > h)
// 		return -1;

// 	int mid = (l + h) / 2;
// 	if (arr[mid] == key)
// 		return mid;

// 	/* If arr[l...mid] is sorted */
// 	if (arr[l] <= arr[mid]) {
// 		/* As this subarray is sorted, we can quickly
// 		check if key lies in half or other half */
// 		if (key >= arr[l] && key <= arr[mid])
// 			return search(arr, l, mid - 1, key);
// 		/*If key not lies in first half subarray,
// 		Divide other half into two subarrays,
// 		such that we can quickly check if key lies
// 		in other half */
// 		return search(arr, mid + 1, h, key);
// 	}

// 	/* If arr[l..mid] first subarray is not sorted, then arr[mid... h]
// 	must be sorted subarray */
// 	if (key >= arr[mid] && key <= arr[h])
// 		return search(arr, mid + 1, h, key);

// 	return search(arr, l, mid - 1, key);
// }

// // Driver program
// int main()
// {
// 	int arr[] = { 4, 5, 6, 7, 8, 9, 1, 2, 3 };
// 	int n = sizeof(arr) / sizeof(arr[0]);
// 	int key = 6;
// 	int i = search(arr, 0, n - 1, key);

// 	if (i != -1)
// 		cout << "Index: " << i << endl;
// 	else
// 		cout << "Key not found";
// }

// How to handle duplicates? 
// It doesn’t look possible to search in O(Logn) time in all cases when duplicates are allowed. For example consider searching 0 in {2, 2, 2, 2, 2, 2, 2, 2, 0, 2} and {2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}. 
// It doesn’t look possible to decide whether to recur for the left half or right half by doing a constant number of comparisons at the middle.