//method 1 USING SORT
//T(N) = O(n(logn))

/*
// A C++ program to sort an array in wave form using 
// a sorting function 
#include<iostream> 
#include<algorithm> 
using namespace std; 

// A utility method to swap two numbers. 
void swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 

// This function sorts arr[0..n-1] in wave form, i.e., 
// arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= arr[5].. 
void sortInWave(int arr[], int n) 
{ 
	// Sort the input array 
	sort(arr, arr+n); 

	// Swap adjacent elements 
	for (int i=0; i<n-1; i += 2) 
		swap(&arr[i], &arr[i+1]); 
} 

// Driver program to test above function 
int main() 
{ 
	int arr[] = {10, 90, 49, 2, 1, 5, 23}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	sortInWave(arr, n); 
	for (int i=0; i<n; i++) 
	cout << arr[i] << " "; 
	return 0; 
} 
*/

//METHOD 2 LINEAR SWAPPING
//T(n) = O(n)

// A O(n) program to sort an input array in wave form 
#include<iostream> 
using namespace std; 

// A utility method to swap two numbers. 
void swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 

// This function sorts arr[0..n-1] in wave form, i.e., arr[0] >= 
// arr[1] <= arr[2] >= arr[3] <= arr[4] >= arr[5] .... 
void sortInWave(int arr[], int n) 
{ 
	// Traverse all even elements 
	for (int i = 0; i < n; i+=2) 
	{ 
		// If current even element is smaller than previous 
		if (i>0 && arr[i-1] > arr[i] ) 
			swap(&arr[i], &arr[i-1]); 

		// If current even element is smaller than next 
		if (i<n-1 && arr[i] < arr[i+1] ) 
			swap(&arr[i], &arr[i + 1]); 
	} 
} 

// Driver program to test above function 
int main() 
{ 
	int arr[] = {10, 90, 49, 2, 1, 5, 23}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	sortInWave(arr, n); 
	for (int i=0; i<n; i++) 
	cout << arr[i] << " "; 
	return 0; 
} 

