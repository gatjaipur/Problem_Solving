// METHOD 1 find minimum
//Time Complexity : O(n)
//Auxiliary Space : O(1)


/*
// C++ program to find number of rotations 
// in a sorted and rotated array. 
#include<bits/stdc++.h> 
using namespace std; 

// Returns count of rotations for an array which 
// is first sorted in ascending order, then rotated 
int countRotations(int arr[], int n) 
{ 
	// We basically find index of minimum 
	// element 
	int min = arr[0], min_index; 
	for (int i=0; i<n; i++) 
	{ 
		if (min > arr[i]) 
		{ 
			min = arr[i]; 
			min_index = i; 
		} 
	} 
	return min_index; 
} 

// Driver code 
int main() 
{ 
	int arr[] = {15, 18, 2, 3, 6, 12}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << countRotations(arr, n); 
	return 0; 
} 
*/

//Method 2 (Efficient Using Binary Search)
//Time Complexity : O(Log n)
//Auxiliary Space : O(1) if we use iterative Binary Search is used

// Binary Search based C++ program to find number 
// of rotations in a sorted and rotated array. 
#include<bits/stdc++.h> 
using namespace std; 

// Returns count of rotations for an array which 
// is first sorted in ascending order, then rotated 
int countRotations(int arr[], int low, int high) 
{ 
	// This condition is needed to handle the case 
	// when array is not rotated at all 
	if (high < low) 
		return 0; 

	// If there is only one element left 
	if (high == low) 
		return low; 

	// Find mid 
	int mid = low + (high - low)/2; /*(low + high)/2;*/

	// Check if element (mid+1) is minimum element. 
	// Consider the cases like {3, 4, 5, 1, 2} 
	if (mid < high && arr[mid+1] < arr[mid]) 
	return (mid+1); 

	// Check if mid itself is minimum element 
	if (mid > low && arr[mid] < arr[mid - 1]) 
	return mid; 

	// Decide whether we need to go to left half or 
	// right half 
	if (arr[high] > arr[mid]) 
	return countRotations(arr, low, mid-1); 

	return countRotations(arr, mid+1, high); 
} 

// Driver code 
int main() 
{ 
	int arr[] = {15, 18, 2, 3, 6, 12}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << countRotations(arr, 0, n-1); 
	return 0; 
} 

