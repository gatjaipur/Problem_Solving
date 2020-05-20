
/*
// Method - 1 sort decrease order. If numbers in array are only single digit which is 1 <= arr[i] <= 9

// C++ program to generate largest possible 
// number with given digits 
#include <bits/stdc++.h> 

using namespace std; 

// Function to generate largest possible 
// number with given digits 
int findMaxNum(int arr[], int n) 
{ 
	// sort the given array in 
	// descending order 
	sort(arr, arr+n, greater<int>()); 
	
	int num = arr[0]; 
	
	// generate the number 
	for(int i=1; i<n; i++) 
	{ 
		num = num*10 + arr[i]; 
	} 
	
	return num; 
} 

// Driver code 
int main() 
{ 
	int arr[] = {1, 2, 3, 4, 5, 0}; 
	
	int n = sizeof(arr)/sizeof(arr[0]); 
	
	cout<<findMaxNum(arr,n); 
	
	return 0; 
} 
*/
/*
// Method 2 using count[]

// C++ program to generate largest possible 
// number with given digits 
#include <bits/stdc++.h> 

using namespace std; 

// Function to generate largest possible 
// number with given digits 
void findMaxNum(int arr[], int n) 
{ 
	// Declare a hash array of size 10 
	// and initialize all the elements to zero 
	int hash[10] = {0}; 
	
	// store the number of occurrences of the digits 
	// in the given array into the hash table 
	for(int i=0; i<n; i++) 
	{ 
		hash[arr[i]]++; 
	} 
	
	// Traverse the hash in descending order 
	// to print the required number 
	for(int i=9; i>=0; i--) 
	{ 
		// Print the number of times a digits occurs 
		for(int j=0; j<hash[i]; j++) 
			cout<<i; 
	} 
} 

// Driver code 
int main() 
{ 
	int arr[] = {1, 2, 3, 4, 5, 0}; 
	
	int n = sizeof(arr)/sizeof(arr[0]); 
	
	findMaxNum(arr,n); 
	
	return 0; 
} 
*/
//Method 3 using compare

// Given an array of numbers, program to arrange the numbers to form the 
// largest number 
#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
using namespace std; 

// A comparison function which is used by sort() in printLargest() 
int myCompare(string X, string Y) 
{ 
	// first append Y at the end of X 
	string XY = X.append(Y); 

	// then append X at the end of Y 
	string YX = Y.append(X); 

	// Now see which of the two formed numbers is greater 
	return XY.compare(YX) > 0 ? 1: 0; 
} 

// The main function that prints the arrangement with the largest value. 
// The function accepts a vector of strings 
void printLargest(vector<string> arr) 
{ 
	// Sort the numbers using library sort function. The function uses 
	// our comparison function myCompare() to compare two strings. 
	// See http://www.cplusplus.com/reference/algorithm/sort/ for details 
	sort(arr.begin(), arr.end(), myCompare); 

	for (int i=0; i < arr.size() ; i++ ) 
		cout << arr[i]; 
} 

// Driver program to test above functions 
int main() 
{ 
	vector<string> arr; 

	//output should be 6054854654 
	arr.push_back("54"); 
	arr.push_back("546"); 
	arr.push_back("548"); 
	arr.push_back("60"); 
	printLargest(arr); 

return 0; 
} 

