//Given an array of integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a2 + b2 = c2.

/*
//Method - 1 T(n) O(n3).
// A C++ program that returns true if there is a Pythagorean 
// Triplet in a given array. 
#include <iostream> 

using namespace std; 

// Returns true if there is Pythagorean triplet in ar[0..n-1] 
bool isTriplet(int ar[], int n) 
{ 
	for (int i = 0; i < n; i++) { 
		for (int j = i + 1; j < n; j++) { 
			for (int k = j + 1; k < n; k++) { 
				// Calculate square of array elements 
				int x = ar[i] * ar[i], y = ar[j] * ar[j], z = ar[k] * ar[k]; 

				if (x == y + z || y == x + z || z == x + y) 
					return true; 
			} 
		} 
	} 

	// If we reach here, no triplet found 
	return false; 
} 

int main() 
{ 
	int ar[] = { 3, 1, 4, 6, 5 }; 
	int ar_size = sizeof(ar) / sizeof(ar[0]); 
	isTriplet(ar, ar_size) ? cout << "Yes" : cout << "No"; 
	return 0; 
} 

*/

/*

// Method 2 Sorting O(n^2)


// A C++ program that returns true if there is a Pythagorean 
// Triplet in a given array. 
#include <algorithm> 
#include <iostream> 

using namespace std; 

// Returns true if there is a triplet with following property 
// A[i]*A[i] = A[j]*A[j] + A[k]*[k] 
// Note that this function modifies given array 
bool isTriplet(int arr[], int n) 
{ 
	// Square array elements 
	for (int i = 0; i < n; i++) 
		arr[i] = arr[i] * arr[i]; 

	// Sort array elements 
	sort(arr, arr + n); 

	// Now fix one element one by one and find the other two 
	// elements 
	for (int i = n - 1; i >= 2; i--) { 
		// To find the other two elements, start two index 
		// variables from two corners of the array and move 
		// them toward each other 
		int l = 0; // index of the first element in arr[0..i-1] 
		int r = i - 1; // index of the last element in arr[0..i-1] 
		while (l < r) { 
			// A triplet found 
			if (arr[l] + arr[r] == arr[i]) 
				return true; 

			// Else either move 'l' or 'r' 
			(arr[l] + arr[r] < arr[i]) ? l++ : r--; 
		} 
	} 

	// If we reach here, then no triplet found 
	return false; 
} 

int main() 
{ 
	int arr[] = { 3, 1, 4, 6, 5 }; 
	int arr_size = sizeof(arr) / sizeof(arr[0]); 
	isTriplet(arr, arr_size) ? cout << "Yes" : cout << "No"; 
	return 0; 
} 

*/

// Method 3 Count array

#include <bits/stdc++.h> 
using namespace std; 

// Function to check if the 
// Pythagorean triplet exists or not 
bool checkTriplet(int arr[], int n) 
{ 
	int maximum = 0; 

	// Find the maximum element 
	for (int i = 0; i < n; i++) { 
		maximum = max(maximum, arr[i]); 
	} 

	// Hashing array 
	int hash[maximum + 1] = { 0 }; 

	// Increase the count of array elements 
	// in hash table 
	for (int i = 0; i < n; i++) 
		hash[arr[i]]++; 

	// Iterate for all possible a 
	for (int i = 1; i < maximum + 1; i++) { 

		// If a is not there 
		if (hash[i] == 0) 
			continue; 

		// Iterate for all possible b 
		for (int j = 1; j < maximum + 1; j++) { 

			// If a and b are same and there is only one a 
			// or if there is no b in original array 
			if ((i == j && hash[i] == 1) || hash[j] == 0) 
				continue; 

			// Find c 
			int val = sqrt(i * i + j * j); 

			// If c^2 is not a perfect square 
			if ((val * val) != (i * i + j * j)) 
				continue; 

			// If c exceeds the maximum value 
			if (val > maximum) 
				continue; 

			// If there exists c in the original array, 
			// we have the triplet 
			if (hash[val]) { 
				return true; 
			} 
		} 
	} 
	return false; 
} 
// Driver Code 
int main() 
{ 
	int arr[] = { 3, 2, 4, 6, 5 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	if (checkTriplet(arr, n)) 
		cout << "Yes"; 
	else
		cout << "No"; 
} 

