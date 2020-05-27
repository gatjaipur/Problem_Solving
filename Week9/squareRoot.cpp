/*
//Method 1 Babylonian method 
// C++ program for Babylonian 
// method for square root 
#include <iostream> 
using namespace std; 

class gfg { 

// Returns the square root of 
//n. Note that the function 
//will not work for numbers 
//which are not perfect 
//squares
public: 
	float squareRoot(float n) 
	{ 
		
		float x = n; 
		float y = 1; 

		while (x > y) { 
			x = (x + y) / 2; 
			y = n / x; 
		} 
		return x; 
	} 
}; 

int main() 
{ 
	gfg g; 
	int n = 49; 
	cout << "Square root of " << n << " is " << g.squareRoot(n); 
	getchar(); 
} 

// This code is edited by Dark_Dante_ 
*/

// Method 2
// A C++ program to find floor(sqrt(x) 
/*
//Time Complexity: O(v n).
//Only one traversal of the solution is needed, so the time complexity is O(v n).
//Space Complexity: O(1).
//Constant extra space is needed.
#include<bits/stdc++.h> 
using namespace std; 

// Returns floor of square root of x 
int floorSqrt(int x) 
{ 
	// Base cases 
	if (x == 0 || x == 1) 
	return x; 

	// Staring from 1, try all numbers until 
	// i*i is greater than or equal to x. 
	int i = 1, result = 1; 
	while (result <= x) 
	{ 
	i++; 
	result = i * i; 
	} 
	return i - 1; 
} 

// Driver program 
int main() 
{ 
	int x = 11; 
	cout << floorSqrt(x) << endl; 
	return 0; 
} 
*/

// Method 3 
//Time complexity: O(log n).
//The time complexity of binary search is O(log n).// A C++ program to find floor(sqrt(x) 
//Space Complexity: O(1).
//Constant extra space is needed.
#include<bits/stdc++.h> 
using namespace std; 

// Returns floor of square root of x		 
int floorSqrt(int x) 
{	 
	// Base cases 
	if (x == 0 || x == 1) 
	return x; 

	// Do Binary Search for floor(sqrt(x)) 
	int start = 1, end = x, ans; 
	while (start <= end) 
	{		 
		int mid = (start + end) / 2; 

		// If x is a perfect square 
		if (mid*mid == x) 
			return mid; 

		// Since we need floor, we update answer when mid*mid is 
		// smaller than x, and move closer to sqrt(x) 
		if (mid*mid < x) 
		{ 
			start = mid + 1; 
			ans = mid; 
		} 
		else // If mid*mid is greater than x 
			end = mid-1;		 
	} 
	return ans; 
} 

// Driver program 
int main() 
{	 
	int x = 11; 
	cout << floorSqrt(x) << endl; 
	return 0; 
} 

