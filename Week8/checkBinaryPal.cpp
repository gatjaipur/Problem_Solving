/*
// C++ Program to Check if binary representation 
// of a number is palindrome 
#include<iostream> 
using namespace std; 

// This function returns true if k'th bit in x 
// is set (or 1). For example if x (0010) is 2 
// and k is 2, then it returns true 
bool isKthBitSet(unsigned int x, unsigned int k) 
{ 
	return (x & (1 << (k - 1))) ? true : false; 
} 

// This function returns true if binary 
// representation of x is palindrome. 
// For example (1000...001) is paldindrome 
bool isPalindrome(unsigned int x) 
{ 
	int l = 1; // Initialize left position 
	int r = sizeof(unsigned int) * 8; // initialize right position 

	// One by one compare bits 
	while (l < r) 
	{ 
		if (isKthBitSet(x, l) != isKthBitSet(x, r)) 
			return false; 
		l++; r--; 
	} 
	return true; 
} 

// Driver Code 
int main() 
{ 
	unsigned int x = 1 << 15 + 1 << 16; 
	cout << isPalindrome(x) << endl; 
	x = 1 << 31 + 1; 
	cout << isPalindrome(x) << endl; 
	return 0; 
} 

*/

//MEthod 2
//Time Complexity: O(num)
// C++ implementation to check whether binary 
// representation of a number is palindrome or not 
#include <bits/stdc++.h> 
using namespace std; 

// function to reverse bits of a number 
unsigned int reverseBits(unsigned int n) 
{ 
	unsigned int rev = 0; 

	// traversing bits of 'n' from the right 
	while (n > 0) { 

		// bitwise left shift 'rev' by 1 
		rev <<= 1; 

		// if current bit is '1' 
		if (n & 1 == 1) 
			rev ^= 1; 

		// bitwise right shift 'n' by 1 
		n >>= 1; 
	} 

	// required number 
	return rev; 
} 

// function to check whether binary representation 
// of a number is palindrome or not 
bool isPalindrome(unsigned int n) 
{ 
	// get the number by reversing bits in the 
	// binary representation of 'n' 
	unsigned int rev = reverseBits(n); 

	return (n == rev); 
} 

// Driver program to test above 
int main() 
{ 
	unsigned int n = 9; 
	if (isPalindrome(n)) 
		cout << "Yes"; 
	else
		cout << "No"; 
	return 0; 
} 

