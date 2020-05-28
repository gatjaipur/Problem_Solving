#include<bits/stdc++.h> 
using namespace std; 

/* C++ program to Check if a given array contains duplicate 
elements within k distance from each other */
bool checkDuplicatesWithinK(int arr[], int n, int k) 
{ 
	// Creates an empty hashset 
	unordered_set<int> myset; 

	// Traverse the input array 
	for (int i = 0; i < n; i++) 
	{ 
		// If already present n hash, then we found 
		// a duplicate within k distance 
		if (myset.find(arr[i]) != myset.end()) 
			return true; 

		// Add this item to hashset 
		myset.insert(arr[i]); 

		// Remove the k+1 distant item 
		if (i >= k) 
			myset.erase(arr[i-k]); 
	} 
	return false; 
} 

// Driver method to test above method 
int main () 
{ 
	int arr[] = {10, 5, 3, 4, 3, 5, 6}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	if (checkDuplicatesWithinK(arr, n, 3)) 
		cout << "Yes"; 
	else
		cout << "No"; 
} 

//This article is contributed by Chhavi 

