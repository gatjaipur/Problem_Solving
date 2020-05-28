//  Method 1 : Naive Method C++ implementation of simple method to find count of pairs with given sum. 
// T(n) = O(n^2)
//Space = O(1)

/*
#include <bits/stdc++.h> 
using namespace std; 
  
// Returns number of pairs in arr[0..n-1] with sum equal 
// to 'sum' 
int getPairsCount(int arr[], int n, int sum) 
{ 
    int count = 0; // Initialize result 
  
    // Consider all possible pairs and check their sums 
    for (int i=0; i<n; i++) 
        for (int j=i+1; j<n; j++) 
            if (arr[i]+arr[j] == sum) 
                {
                	count++; 
                	cout << "Pair found at index " << i << " and " << j <<endl;
				}
  
    return count; 
} 
  
// Driver function to test the above function 
int main() 
{ 
    int arr[] = {1, 5, 7, -1, 5} ; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int sum = 6; 
    cout << "Count of pairs is " 
         << getPairsCount(arr, n, sum); 
    return 0; 
}
*/
//  Method 2 : Hashing Method C++ implementation of simple method to find count of pairs with given sum. 
// T(n) = O(n)
//Space = O(n)

/*
// C++ implementation of simple method to find count of 
// pairs with given sum. 

#include <bits/stdc++.h> 
// Returns number of pairs in arr[0..n-1] with sum equal 
// to 'sum' 
int getPairsCount(int arr[], int n, int sum) 
{ 
    unordered_map<int, int> m; 
  
    // Store counts of all elements in map m 
    for (int i=0; i<n; i++) 
        m[arr[i]]++; 
  
    int twice_count = 0; 
  
    // iterate through each element and increment the 
    // count (Notice that every pair is counted twice) 
    for (int i=0; i<n; i++) 
    { 
        twice_count += m[sum-arr[i]]; 
  
        // if (arr[i], arr[i]) pair satisfies the condition, 
        // then we need to ensure that the count is 
        // decreased by one such that the (arr[i], arr[i]) 
        // pair is not considered 
        if (sum-arr[i] == arr[i]) 
            twice_count--; 
    } 
  
    // return the half of twice_count 
    return twice_count/2; 
} 
  
// Driver function to test the above function 
int main() 
{ 
    int arr[] = {1, 5, 7, -1, 5} ; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int sum = 6; 
    cout << "Count of pairs is " 
         << getPairsCount(arr, n, sum); 
    return 0; 
}
*/


//METHOD 3 Sorting

//T(n)= O(nlogn)

#include <iostream>
#include <algorithm>

// Function to find a pair in an array with given sum using Sorting
void findPair(int arr[], int n, int sum)
{
	// sort the array in ascending order
	std::sort(arr, arr + n);

	// maintain two indices pointing to end-points of the array
	int low = 0;
	int high = n - 1;
	int count =0;
	// reduce search space arr[low..high] at each iteration of the loop

	// loop till low is less than high
	while (low < high)
	{
		// sum found
		if (arr[low] + arr[high] == sum)
		{
			count++;
		}

		// increment low index if total is less than the desired sum
		// decrement high index is total is more than the sum
		(arr[low] + arr[high] < sum)? low++: high--;
	}

	// No pair with given sum exists in the array
	std::cout << "count " << count;
}

// Find pair with given sum in the array
int main()
{
	int arr[] = { 8, 7, 2, 5, 3, 1};
	int sum = 10;

	int n = sizeof(arr)/sizeof(arr[0]);

	findPair(arr, n, sum);

	return 0;
}

//METHOD 4 USING HASHING
//T(n) = O(n)

/*
#include <iostream>
#include <unordered_map>

// Function to find a pair in an array with given sum using Hashing
void findPair(int arr[], int n, int sum)
{
	// create an empty map
	std::unordered_map<int, int> map;
	int count =0;
	// do for each element
	for (int i = 0; i < n; i++)
	{
		// check if pair (arr[i], sum-arr[i]) exists

		// if difference is seen before, print the pair
		if (map.find(sum - arr[i]) != map.end())
		{
		count++;
		}

		// store index of current element in the map
		map[arr[i]] = i;
	}

	// we reach here if pair is not found
	std::cout << count;
}

// Find pair with given sum in the array
int main()
{
	int arr[] = { 8, 7, 2, 5, 3, 1};
	int sum = 10;

	int n = sizeof(arr)/sizeof(arr[0]);

	findPair(arr, n, sum);

	return 0;
}

*/
