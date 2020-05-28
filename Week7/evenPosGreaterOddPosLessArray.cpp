// C++ program to rearrange the array 
// as per the given condition 
//Given an array of n elements. Our task is to write a program to rearrange the array such that
//elements at even positions are greater than all elements before it and elements at odd positions
//are less than all elements before it.
//Time Complexity: O( n logn )
//Auxiliary Space: O(n)

#include <bits/stdc++.h> 
using namespace std; 

// function to rearrange the array 
void rearrangeArr(int arr[], int n) 
{ 
	// total even positions 
	int evenPos = n / 2; 

	// total odd positions 
	int oddPos = n - evenPos; 

	int tempArr[n]; 

	// copy original array in an 
	// auxiliary array 
	for (int i = 0; i < n; i++) 
		tempArr[i] = arr[i]; 

	// sort the auxiliary array 
	sort(tempArr, tempArr + n); 

	int j = oddPos - 1; 

	// fill up odd position in original 
	// array 
	for (int i = 0; i < n; i += 2) { 
		arr[i] = tempArr[j]; 
		j--; 
	} 

	j = oddPos; 

	// fill up even positions in original 
	// array 
	for (int i = 1; i < n; i += 2) { 
		arr[i] = tempArr[j]; 
		j++; 
	} 

	// display array 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 }; 
	int size = sizeof(arr) / sizeof(arr[0]); 
	rearrangeArr(arr, size); 
	return 0; 
} 

