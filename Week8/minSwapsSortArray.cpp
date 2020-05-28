// C++ program to find minimum number of swaps 
// required to sort an array 

//METHOD 1 using graph 
//Time Complexity: O(n)
//Auxiliary Space: O(n)

/*
#include<bits/stdc++.h> 

using namespace std; 

// Function returns the minimum number of swaps 
// required to sort the array 
int minSwaps(int arr[], int n) 
{ 
	// Create an array of pairs where first 
	// element is array element and second element 
	// is position of first element 
	pair<int, int> arrPos[n]; 
	for (int i = 0; i < n; i++) 
	{ 
		arrPos[i].first = arr[i]; 
		arrPos[i].second = i; 
	} 

	// Sort the array by array element values to 
	// get right position of every element as second 
	// element of pair. 
	sort(arrPos, arrPos + n); 

	// To keep track of visited elements. Initialize 
	// all elements as not visited or false. 
	vector<bool> vis(n, false); 

	// Initialize result 
	int ans = 0; 

	// Traverse array elements 
	for (int i = 0; i < n; i++) 
	{ 
		// already swapped and corrected or 
		// already present at correct pos 
		if (vis[i] || arrPos[i].second == i) 
			continue; 

		// find out the number of node in 
		// this cycle and add in ans 
		int cycle_size = 0; 
		int j = i; 
		while (!vis[j]) 
		{ 
			vis[j] = 1; 

			// move to next node 
			j = arrPos[j].second; 
			cycle_size++; 
		} 

		// Update answer by adding current cycle. 
		if(cycle_size > 0) 
		{ 
			ans += (cycle_size - 1); 
		} 
	} 

	// Return result 
	return ans; 
} 

// Driver program to test the above function 
int main() 
{ 
	int arr[] = {1, 5, 4, 3, 2}; 
	int n = (sizeof(arr) / sizeof(int)); 
	cout << minSwaps(arr, n); 
	return 0; 
} 

*/

//METHOD 2 USING SWAPPING TILL DESIRED OUTPUT

// CPP program to find the minimum number 
// of swaps required to sort an array 
// of distinct element 

#include<bits/stdc++.h> 
using namespace std; 

// Function to find minimum swaps to 
// sort an array 
int findMinSwap(int arr[] , int n) 
{ 
	// Declare a vector of pair	 
	vector<pair<int,int> > vec(n); 
	
	for(int i=0;i<n;i++) 
	{ 
		vec[i].first=arr[i]; 
		vec[i].second=i; 
	} 

	// Sort the vector w.r.t the first 
	// element of pair 
	sort(vec.begin(),vec.end()); 

	int ans=0,c=0,j; 

	for(int i=0;i<n;i++) 
	{ 
		// If the element is already placed 
		// correct, then continue 
		if(vec[i].second==i) 
			continue; 
		else
		{ 
			// swap with its respective index 
			swap(vec[i].first,vec[vec[i].second].first); 
			swap(vec[i].second,vec[vec[i].second].second); 
		} 
		
		// swap until the correct 
		// index matches 
		if(i!=vec[i].second) 
			--i; 
		
		// each swap makes one element 
		// move to its correct index, 
		// so increment answer 
		ans++; 
	} 

	return ans; 
} 

// Driver code 
int main() 
{ 
	int arr[] = {1, 5, 4, 3, 2}; 
	
	int n = sizeof(arr)/sizeof(arr[0]); 
	
	cout<<findMinSwap(arr,n); 
	
	return 0; 
} 

