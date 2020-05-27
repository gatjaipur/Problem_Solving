// C++ code to find minimum number of 
// swaps to sort a binary array 
//This can be done by finding number of zeroes to the right side of every 1 and add them.
//Time Complexity : O(n)
//Auxiliary Space : O(n)

#include <bits/stdc++.h> 

using namespace std; 

// Function to find minimum swaps to 
// sort an array of 0s and 1s. 
int findMinSwaps(int arr[], int n) 
{ 
	// Array to store count of zeroes 
	int noOfZeroes[n]; 
	memset(noOfZeroes, 0, sizeof(noOfZeroes)); 

	int i, count = 0; 

	// Count number of zeroes 
	// on right side of every one. 
	noOfZeroes[n - 1] = 1 - arr[n - 1]; 
	for (i = n - 2; i >= 0; i--) { 
		noOfZeroes[i] = noOfZeroes[i + 1]; 
		if (arr[i] == 0) 
			noOfZeroes[i]++; 
	} 

	// Count total number of swaps by adding number 
	// of zeroes on right side of every one. 
	for (i = 0; i < n; i++) { 
		if (arr[i] == 1) 
			count += noOfZeroes[i]; 
	} 

	return count; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 0, 0, 1, 0, 1, 0, 1, 1 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << findMinSwaps(arr, n); 
	return 0; 
} 

