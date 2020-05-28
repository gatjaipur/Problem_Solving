// Maximum difference between two elements such that larger element appears after the smaller number
//Input : arr = {2, 3, 10, 6, 4, 8, 1}
//Output : 8
//Explanation : The maximum difference is between 10 and 2

//METHOD 1 USING Brute Force
//T(n) = O(n*n)
//Space = O(1)


// C++ program to find Maximum difference 
// between two elements such that larger 
// element appears after the smaller number 

/* The function assumes that there are 
at least two elements in array. The 
function returns a negative value if the 
array is sorted in decreasing order and 
returns 0 if elements are equal */
/*
#include <bits/stdc++.h> 
using namespace std; 



int maxDiff(int arr[], int arr_size) 
{	 
int max_diff = arr[1] - arr[0]; 
for (int i = 0; i < arr_size; i++) 
{ 
	for (int j = i+1; j < arr_size; j++) 
	{	 
	if (arr[j] - arr[i] > max_diff) 
		max_diff = arr[j] - arr[i]; 
	} 
}		 
return max_diff; 
} 

int main() 
{ 
int arr[] = {1, 2, 90, 10, 110}; 
int n = sizeof(arr) / sizeof(arr[0]); 
	
// Function calling 
cout << "Maximum difference is " << maxDiff(arr, n); 

return 0; 
}

*/


//METHOD 2 USING Min Element
//T(n) = O(n)
//Space = O(1)

/*
// C++ program to find Maximum difference 
// between two elements such that larger 
// element appears after the smaller number 
#include <bits/stdc++.h> 
using namespace std; 

// The function assumes that there are 
//at least two elements in array. The 
//function returns a negative value if the 
//array is sorted in decreasing order and 
//returns 0 if elements are equal 

int maxDiff(int arr[], int arr_size) 
{ 
	// Maximum difference found so far 
	int max_diff = arr[1] - arr[0]; 
	
	// Minimum number visited so far 
	int min_element = arr[0]; 
	for(int i = 1; i < arr_size; i++) 
	{	 
	if (arr[i] - min_element > max_diff)							 
	max_diff = arr[i] - min_element; 
		
	if (arr[i] < min_element) 
	min_element = arr[i];					 
	} 
	
	return max_diff; 
} 

int main() 
{ 
int arr[] = {1, 2, 90, 10, 110}; 
int n = sizeof(arr) / sizeof(arr[0]); 
	
// Function calling 
cout << "Maximum difference is " << maxDiff(arr, n); 

return 0; 
} 

*/ 


//METHOD 3 USING MAX Right
//T(n) = O(n)
//Space = O(1)

// C++ program to find Maximum difference 
// between two elements such that larger 
// element appears after the smaller number 


/* The function assumes that there are 
at least two elements in array. The 
function returns a negative value if the 
array is sorted in decreasing order and 
returns 0 if elements are equal */
/*
#include <bits/stdc++.h> 
using namespace std; 

int maxDiff(int arr[], int n) 
{ 
	// Initialize Result 
	int maxDiff = -1; 
	
	// Initialize max element from right side 
	int maxRight = arr[n-1]; 

	for (int i = n-2; i >= 0; i--) 
	{ 
		if (arr[i] > maxRight) 
			maxRight = arr[i]; 
		else
		{ 
			int diff = maxRight - arr[i]; 
			if (diff > maxDiff) 
			{ 
				maxDiff = diff; 
			} 
		} 
	} 
	return maxDiff; 
} 

int main() 
{ 
int arr[] = {1, 2, 90, 10, 110}; 
int n = sizeof(arr) / sizeof(arr[0]); 
	
// Function calling 
cout << "Maximum difference is " << maxDiff(arr, n); 

return 0; 
} 
*/

//METHOD 4 USING diff and max sum logic
//T(n) = O(n)
//Space = O(1)


// C++ program to find Maximum difference 
// between two elements such that larger 
// element appears after the smaller number 
#include <bits/stdc++.h> 
using namespace std; 

/* The function assumes that there are 
at least two elements in array. The 
function returns a negative value if the 
array is sorted in decreasing order and 
returns 0 if elements are equal */
int maxDiff (int arr[], int n) 
{ 
	// Initialize diff, current sum and max sum 
	int diff = arr[1]-arr[0]; 
	int curr_sum = diff; 
	int max_sum = curr_sum; 

	for(int i=1; i<n-1; i++) 
	{ 
		// Calculate current diff 
		diff = arr[i+1]-arr[i]; 

		// Calculate current sum 
		if (curr_sum > 0) 
		curr_sum += diff; 
		else
		curr_sum = diff; 

		// Update max sum, if needed 
		if (curr_sum > max_sum) 
		max_sum = curr_sum; 
	} 

	return max_sum; 
} 

/* Driver program to test above function */
int main() 
{ 
int arr[] = {80, 2, 6, 3, 100}; 
int n = sizeof(arr) / sizeof(arr[0]); 
	
// Function calling 
cout << "Maximum difference is " << maxDiff(arr, n); 

return 0; 
} 

