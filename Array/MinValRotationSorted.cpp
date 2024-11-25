//Method 1

// // C program to find minimum element in a sorted and rotated array
// #include <stdio.h>

// int findMin(int arr[], int low, int high)
// {
// 	// This condition is needed to handle the case when array is not
// 	// rotated at all
// 	if (high < low) return arr[0];

// 	// If there is only one element left
// 	if (high == low) return arr[low];

// 	// Find mid
// 	int mid = low + (high - low)/2; /*(low + high)/2;*/

// 	// Check if element (mid+1) is minimum element. Consider
// 	// the cases like {3, 4, 5, 1, 2}
// 	if (mid < high && arr[mid+1] < arr[mid])
// 	return arr[mid+1];

// 	// Check if mid itself is minimum element
// 	if (mid > low && arr[mid] < arr[mid - 1])
// 	return arr[mid];

// 	// Decide whether we need to go to left half or right half
// 	if (arr[high] > arr[mid])
// 	return findMin(arr, low, mid-1);
// 	return findMin(arr, mid+1, high);
// }

// // Driver program to test above functions
// int main()
// {
// 	int arr1[] = {5, 6, 1, 2, 3, 4};
// 	int n1 = sizeof(arr1)/sizeof(arr1[0]);
// 	printf("The minimum element is %d\n", findMin(arr1, 0, n1-1));

// 	return 0;
// }

// The above approach in the worst case(If all the elements are the same) takes O(N).
// Below is the code to handle duplicates in O(log n) time. 

// Method 2

// C++ program to find minimum element in a sorted
// and rotated array contating duplicate elements.
#include <bits/stdc++.h>
using namespace std;

// Function to find minimum element
int findMin(int arr[], int low, int high)
{
	while(low < high)
	{
		int mid = low + (high - low)/2;
		if (arr[mid] == arr[high])
			high--;
		else if(arr[mid] > arr[high])
			low = mid + 1;
		else
			high = mid;
	}
	return arr[high];
}

// Driver code
int main()
{
	int arr1[] = {5, 6, 1, 2, 3, 3, 4};
	int n1 = sizeof(arr1)/sizeof(arr1[0]);
	cout << "The minimum element is " << findMin(arr1, 0, n1-1) << endl;
	return 0;
}
