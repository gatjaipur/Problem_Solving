//METHOD 1 
//T(n) = O(N^2)

/*
// C program to Count 
// Inversions in an array 
#include <bits/stdc++.h> 
int getInvCount(int arr[], int n) 
{ 
	int inv_count = 0; 
	for (int i = 0; i < n - 1; i++) 
		for (int j = i + 1; j < n; j++) 
			if (arr[i] > arr[j]) 
				inv_count++; 

	return inv_count; 
} 

int main(int argv, char** args) 
{ 
	int arr[] = { 1, 20, 6, 4, 5 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	printf(" Number of inversions are %d \n", getInvCount(arr, n)); 
	return 0; 
} 

*/

//METHOD 2 (Enhance Merge Sort)
//Time Complexity: O(nlogn)

// C program to Count 
// Inversions in an array 
// using Merge Sort 
#include <bits/stdc++.h> 

int _mergeSort(int arr[], int temp[], int left, int right); 
int merge(int arr[], int temp[], int left, int mid, int right); 

/* This function sorts the input array and returns the 
number of inversions in the array */
int mergeSort(int arr[], int array_size) 
{ 
	int* temp = (int*)malloc(sizeof(int) * array_size); 
	return _mergeSort(arr, temp, 0, array_size - 1); 
} 

/* An auxiliary recursive function that sorts the input array and 
returns the number of inversions in the array. */
int _mergeSort(int arr[], int temp[], int left, int right) 
{ 
	int mid, inv_count = 0; 
	if (right > left) { 
		/* Divide the array into two parts and call _mergeSortAndCountInv() 
	for each of the parts */
		mid = (right + left) / 2; 

		/* Inversion count will be sum of inversions in left-part, right-part 
	and number of inversions in merging */
		inv_count = _mergeSort(arr, temp, left, mid); 
		inv_count += _mergeSort(arr, temp, mid + 1, right); 

		/*Merge the two parts*/
		inv_count += merge(arr, temp, left, mid + 1, right); 
	} 
	return inv_count; 
} 

/* This funt merges two sorted arrays and returns inversion count in 
the arrays.*/
int merge(int arr[], int temp[], int left, int mid, int right) 
{ 
	int i, j, k; 
	int inv_count = 0; 

	i = left; /* i is index for left subarray*/
	j = mid; /* j is index for right subarray*/
	k = left; /* k is index for resultant merged subarray*/
	while ((i <= mid - 1) && (j <= right)) { 
		if (arr[i] <= arr[j]) { 
			temp[k++] = arr[i++]; 
		} 
		else { 
			temp[k++] = arr[j++]; 

			/*this is tricky -- see above explanation/diagram for merge()*/
			inv_count = inv_count + (mid - i); 
		} 
	} 

	/* Copy the remaining elements of left subarray 
(if there are any) to temp*/
	while (i <= mid - 1) 
		temp[k++] = arr[i++]; 

	/* Copy the remaining elements of right subarray 
(if there are any) to temp*/
	while (j <= right) 
		temp[k++] = arr[j++]; 

	/*Copy back the merged elements to original array*/
	for (i = left; i <= right; i++) 
		arr[i] = temp[i]; 

	return inv_count; 
} 

int main(int argv, char** args) 
{ 
	int arr[] = { 1, 20, 6, 4, 5 }; 
	printf(" Number of inversions are %d \n", mergeSort(arr, 5)); 
	getchar(); 
	return 0; 
} 

/*
//METHOD 3 USING SET
//T(n) = O(n^2)

// A STL Set based approach for inversion count 
#include<bits/stdc++.h> 
using namespace std; 

// Returns inversion count in arr[0..n-1] 
int getInvCount(int arr[],int n) 
{ 
	// Create an empty set and insert first element in it 
	set<int> set1; 
	set1.insert(arr[0]); 

	int invcount = 0; // Initialize result 

	set<int>::iterator itset1; // Iterator for the set 

	// Traverse all elements starting from second 
	for (int i=1; i<n; i++) 
	{ 
		// Insert arr[i] in set (Note that set maintains 
		// sorted order) 
		set1.insert(arr[i]); 

		// Set the iterator to first greater element than arr[i] 
		// in set (Note that set stores arr[0],.., arr[i-1] 
		itset1 = set1.upper_bound(arr[i]); 

		// Get distance of first greater element from end 
		// and this distance is count of greater elements 
		// on left side of arr[i] 
		invcount += distance(itset1, set1.end()); 
	} 

	return invcount; 
} 

// Driver program to test above 
int main() 
{ 
	int arr[] = {8, 4, 2, 1}; 
	int n = sizeof(arr)/sizeof(int); 
	cout << "Number of inversions count are : "
		<< getInvCount(arr,n); 
	return 0; 
} 

*/
