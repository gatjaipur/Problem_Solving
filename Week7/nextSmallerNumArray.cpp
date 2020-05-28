// METHOD 1 USING two FOR loops
//T(N) = O(N*N)

/*	
// Simple C program to print next smaller elements 
// in a given array 
#include<stdio.h> 

// prints element and NSE pair for all elements of 
//arr[] of size n 
void printNSE(int arr[], int n) 
{ 
	int next, i, j; 
	for (i=0; i<n; i++) 
	{ 
		next = -1; 
		for (j = i+1; j<n; j++) 
		{ 
			if (arr[i] > arr[j]) // for next greater element arr[i] < arr[j]
			{ 
				next = arr[j];  
				break; 
			} 
		} 
		printf("%d -- %d\n", arr[i], next); 
	} 
} 

int main() 
{ 
	int arr[]= {11, 13, 21, 3}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printNSE(arr, n); 
	return 0; 
} 

*/


//METHOD 2 using Stack
//T(n) = O(n)

// A Stack based C++ program to find next 
// smaller element for all array elements. 
#include <bits/stdc++.h> 

using namespace std; 

// prints element and NSE pair for all 
//elements of arr[] of size n 
void printNSE(int arr[], int n) 
{ 
	stack<int> s; 

// push the first element to stack 
	s.push(arr[0]); 

	// iterate for rest of the elements 
	for (int i = 1; i < n; i++) { 

		if (s.empty()) { 
			s.push(arr[i]); 
			continue; 
		} 


		while (s.empty() == false && s.top() > arr[i]) {  // for next greater element s.top < arr[i]
			cout << s.top() << " --> " << arr[i] << endl; 
			s.pop(); 
		} 

		s.push(arr[i]); 
	} 


	while (s.empty() == false) { 
		cout << s.top() << " --> " << -1 << endl; 
		s.pop(); 
	} 
} 

int main() 
{ 
	int arr[] = { 11, 13, 21, 3 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	printNSE(arr, n); 
	return 0; 
}


/*
//FOR C++11
//METHOD 3 using stack and unordered map to get the output in insertion order

// A Stack based C++ program to find next 
// smaller element for all array elements 
// in same order as input. 
#include <bits/stdc++.h> 
#include<unordered_map>
using namespace std; 


void printNSE(int arr[], int n) 
{ 
	stack<int> s; 
	unordered_map<int, int> mp; 

	s.push(arr[0]); 
	

	// iterate for rest of the elements 
	for (int i = 1; i < n; i++) { 

		if (s.empty()) { 
			s.push(arr[i]); 
			continue; 
		} 

		while (s.empty() == false && s.top() > arr[i]) { // for next greater element s.top < arr[i]
			mp[s.top()] = arr[i]; 
			s.pop(); 
		} 

		s.push(arr[i]); 
	} 


	while (s.empty() == false) { 
		mp[s.top()] = -1; 
		s.pop(); 
	} 

	for (int i=0; i<n; i++) 
	cout << arr[i] << " ---> " << mp[arr[i]] << endl; 
} 

int main() 
{ 
	int arr[] = { 11, 13, 21, 3 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	printNSE(arr, n); 
	return 0; 
}

*/


//IMMEDIATE SMALLER ELEMENT
//Immediate Smaller Element [Editorial]
//Just keep checking for a[i+1]<a[i] or not. If yes print a[i+1] else print -1
