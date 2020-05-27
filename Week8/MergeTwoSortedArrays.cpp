// Method 1
// Time Complexity : O(n1 + n2)
// Auxiliary Space : O(n1 + n2)
// C++ program to merge two sorted arrays/ 
#include<iostream> 
using namespace std; 

// Merge arr1[0..n1-1] and arr2[0..n2-1] into 
// arr3[0..n1+n2-1] 
void mergeArrays(int arr1[], int arr2[], int n1, 
							int n2, int arr3[]) 
{ 
	int i = 0, j = 0, k = 0; 

	// Traverse both array 
	while (i<n1 && j <n2) 
	{ 
		// Check if current element of first 
		// array is smaller than current element 
		// of second array. If yes, store first 
		// array element and increment first array 
		// index. Otherwise do same with second array 
		if (arr1[i] < arr2[j]) 
			arr3[k++] = arr1[i++]; 
		else
			arr3[k++] = arr2[j++]; 
	} 

	// Store remaining elements of first array 
	while (i < n1) 
		arr3[k++] = arr1[i++]; 

	// Store remaining elements of second array 
	while (j < n2) 
		arr3[k++] = arr2[j++]; 
} 

// Driver code 
int main() 
{ 
	int arr1[] = {1, 3, 5, 7}; 
	int n1 = sizeof(arr1) / sizeof(arr1[0]); 

	int arr2[] = {2, 4, 6, 8}; 
	int n2 = sizeof(arr2) / sizeof(arr2[0]); 

	int arr3[n1+n2]; 
	mergeArrays(arr1, arr2, n1, n2, arr3); 

	cout << "Array after merging" <<endl; 
	for (int i=0; i < n1+n2; i++) 
		cout << arr3[i] << " "; 

	return 0; 
} 

// Method 2: Using Maps (O(N) Time and O(N) Extra Space)
/*
// C++ program to merge two sorted arrays 
//using maps 
#include<bits/stdc++.h> 
using namespace std; 

// Function to merge arrays 
void mergeArrays(int a[], int b[], int n, int m) 
{ 
	// Declaring a map. 
	// using map as a inbuilt tool 
	// to store elements in sorted order. 
	map<int, bool> mp; 
	
	// Inserting values to a map. 
	for(int i = 0; i < n; i++) 
	mp[a[i]] = true; 
	
	for(int i = 0;i < m;i++) 
	mp[b[i]] = true; 
	
	// Printing keys of the map. 
	for(auto i: mp) 
	cout<< i.first <<" "; 
} 

// Driver Code 
int main() 
{ 
	int a[] = {1, 3, 5, 7}, b[] = {2, 4, 6, 8}; 
	
	int size = sizeof(a)/sizeof(int); 
	int size1 = sizeof(b)/sizeof(int); 
	
	// Function call 
	mergeArrays(a, b, size, size1); 
	
	return 0; 
} 
*/
//This code is contributed by yashbeersingh42 

// Method 3 T(N) = O(m*n) Space is O(1)
/*
// C++ program to merge two sorted arrays with O(1) extra space. 
#include <bits/stdc++.h> 
using namespace std; 

// Merge ar1[] and ar2[] with O(1) extra space 
void merge(int ar1[], int ar2[], int m, int n) 
{ 
	// Iterate through all elements of ar2[] starting from 
	// the last element 
	for (int i=n-1; i>=0; i--) 
	{ 
//		Find the smallest element greater than ar2[i]. Move all 
//		elements one position ahead till the smallest greater 
//		element is not found 
		int j, last = ar1[m-1]; 
		for (j=m-2; j >= 0 && ar1[j] > ar2[i]; j--) 
			ar1[j+1] = ar1[j]; 

		// If there was a greater element 
		if (j != m-2 || last > ar2[i]) 
		{ 
			ar1[j+1] = ar2[i]; 
			ar2[i] = last; 
		} 
	} 
} 

// Driver program 
int main(void) 
{ 
	int ar1[] = {1, 5, 9, 10, 15, 20}; 
	int ar2[] = {2, 3, 8, 13}; 
	int m = sizeof(ar1)/sizeof(ar1[0]); 
	int n = sizeof(ar2)/sizeof(ar2[0]); 
	merge(ar1, ar2, m, n); 

	cout << "After Merging nFirst Array: "; 
	for (int i=0; i<m; i++) 
		cout << ar1[i] << " "; 
	cout << "nSecond Array: "; 
	for (int i=0; i<n; i++) 
		cout << ar2[i] << " "; 
return 0; 
} 
*/

// Method 4
// C++ program to merge two sorted arrays in 
// constant space 
/*
#include <bits/stdc++.h> 
using namespace std; 

// Function to merge two sorted arrays in 
// constant space 
void mergeArrays(int* a, int n, int* b, int m) 
{ 

	// Convert second array into a min_heap 
	// using make_heap() STL function [takes O(m)] 
	make_heap(b, b + m, greater<int>()); 

	// Start traversing the first array 
	for (int i = 0; i < n; i++) { 

		// If current element is greater than root 
		// of min_heap 
		if (a[i] > b[0]) { 

			// Pop minimum element from min_heap using 
			// pop_heap() STL function 
			// The pop_heap() function removes the minimum element from 
			// heap and moves it to the end of the container 
			// converted to heap and reduces heap size by 1 
			pop_heap(b, b + m, greater<int>()); 

			// Swapping the elements 
			int tmp = a[i]; 
			a[i] = b[m - 1]; 
			b[m - 1] = tmp; 

			// Apply push_heap() function on the container 
			// or array to again reorder it in the 
			// form of min_heap 
			push_heap(b, b + m, greater<int>()); 
		} 
	} 

	// Convert the second array again into max_heap 
	// because sort_heap() on min heap sorts the array 
	// in decreasing order 
	// This step is [O(m)] 
	make_heap(b, b + m); // It's a max_heap 

	// Sort the second array using sort_heap() function 
	sort_heap(b, b + m); 
} 

// Driver Code 
int main() 
{ 

	int ar1[] = { 1, 5, 9, 10, 15, 20 }; 
	int ar2[] = { 2, 3, 8, 13 }; 
	int m = sizeof(ar1) / sizeof(ar1[0]); 
	int n = sizeof(ar2) / sizeof(ar2[0]); 
	mergeArrays(ar1, m, ar2, n); 

	cout << "After Merging :- \nFirst Array: "; 
	for (int i = 0; i < m; i++) 
		cout << ar1[i] << " "; 
	cout << "\nSecond Array: "; 
	for (int i = 0; i < n; i++) 
		cout << ar2[i] << " "; 

	return 0; 
} 
*/

