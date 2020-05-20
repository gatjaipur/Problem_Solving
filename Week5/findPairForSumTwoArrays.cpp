//Method - 1 T.C. O(n^2)
/*

// C++ program to find all pairs in both arrays 
// whose sum is equal to given value x 
#include <bits/stdc++.h> 

using namespace std; 

// Function to print all pairs in both arrays 
// whose sum is equal to given value x 
void findPairs(int arr1[], int arr2[], int n, 
			int m, int x) 
{ 
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			if (arr1[i] + arr2[j] == x) 
				cout << arr1[i] << " "
					<< arr2[j] << endl; 
} 

// Driver code 
int main() 
{ 
	int arr1[] = { 1, 2, 3, 7, 5, 4 }; 
	int arr2[] = { 0, 7, 4, 3, 2, 1 }; 
	int n = sizeof(arr1) / sizeof(int); 
	int m = sizeof(arr2) / sizeof(int); 
	int x = 8; 
	findPairs(arr1, arr2, n, m, x); 
	return 0; 
} 

*/

//Method - 2 using set Time Complexity: O(max(n, m))

// C++ program to find all pair in both arrays 
// whose sum is equal to given value x 
#include <bits/stdc++.h> 
#include<set>
using namespace std; 

// Function to find all pairs in both arrays 
// whose sum is equal to given value x 
void findPairs(int arr1[], int arr2[], int n, 
			int m, int x) 
{ 
	// Insert all elements of first array in a hash 
	set<int> s; 
	for (int i = 0; i < n; i++) 
		s.insert(arr1[i]); 

	// Subtract sum from second array elements one 
	// by one and check it's present in array first 
	// or not 
	for (int j = 0; j < m; j++) 
		if (s.find(x - arr2[j]) != s.end()) 
			cout << x - arr2[j] << " "
				<< arr2[j] << endl; 
} 

// Driver code 
int main() 
{ 
	int arr1[] = { 1, 0, -4, 7, 6, 4 }; 
	int arr2[] = { 0, 2, 4, -3, 2, 1 }; 
	int x = 8; 
	int n = sizeof(arr1) / sizeof(int); 
	int m = sizeof(arr2) / sizeof(int); 
	findPairs(arr1, arr2, n, m, x); 
	return 0; 
} 

