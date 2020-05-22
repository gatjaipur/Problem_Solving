/*
Sort all even numbers in ascending order and then sort all odd numbers in descending order
*/

// METHOD 1 Using Partition
//Time complexity: O(n log n)
//space complexity: O(1)

/*

// C++ program sort array in even and odd manner. 
// The odd numbers are to be sorted in descending 
// order and the even numbers in ascending order 
#include<bits/stdc++.h> 
using namespace std; 

// To do two way sort. First sort even numbers in 
// ascending order, then odd numbers in descending 
// order. 

void twoWaySort(int arr[], int n) 
{ 
	// Current indexes from left and right 
	int l = 0, r = n-1; 

	// Count of odd numbers 
	int k = 0; 

	while (l < r) 
	{ 
		// Find first odd number from left side. 
		while (arr[l]%2 != 0) 
		{ 
			l++; 
			k++; 
		} 

		// Find first even number from right side. 
		while (arr[r]%2 == 0 && l<r) 
			r--; 

		// Swap odd number present on left and even 
		// number right. 
		if (l < r) 
			swap(arr[l], arr[r]); 
	} 

	// Sort odd number in descending order 
	sort(arr, arr+k, greater<int>()); 

	// Sort even number in ascending order 
	sort(arr+k, arr+n); 
} 

// Driver code 
int main() 
{ 
	int arr[] = {1, 3, 2, 7, 5, 4}; 
	int n = sizeof(arr)/sizeof(int); 
	twoWaySort(arr, n); 
	for (int i=0; i<n; i++) 
		cout << arr[i] << " "; 
	return 0; 
} 

*/

// METHOD 2 Using negative multiplication
//Time complexity: O(n log n)
//space complexity: O(1)


// C++ program sort array in even and odd manner. 
// The odd numbers are to be sorted in descending 
// order and the even numbers in ascending order 
#include<bits/stdc++.h> 
using namespace std; 

// To do two way sort. First sort even numbers in 
// ascending order, then odd numbers in descending 
// order. 
void twoWaySort(int arr[], int n) 
{ 
	// Make all odd numbers negative 
	for (int i=0 ; i<n ; i++) 
		if (arr[i] & 1) // Check for odd 
			arr[i] *= -1; 

	// Sort all numbers 
	sort(arr, arr+n); 

	// Retaining original array 
	for (int i=0 ; i<n ; i++) 
		if (arr[i] & 1) 
			arr[i] *= -1; 
} 

// Driver code 
int main() 
{ 
	int arr[] = {1, 3, 2, 7, 5, 4}; 
	int n = sizeof(arr)/sizeof(int); 
	twoWaySort(arr, n); 
	for (int i=0; i<n; i++) 
		cout << arr[i] << " "; 
	return 0; 
}
 

