// A C++ program to find the number of digits in 
// a factorial 
//However that solution would not be able to handle cases where n >10^6
#include <bits/stdc++.h> 
using namespace std; 

// This function receives an integer n, and returns 
// the number of digits present in n! 
int findDigits(int n) 
{ 
	// factorial exists only for n>=0 
	if (n < 0) 
		return 0; 

	// base case 
	if (n <= 1) 
		return 1; 

	// else iterate through n and calculate the 
	// value 
	double digits = 0; 
	for (int i=2; i<=n; i++) 
		digits += log10(i); 

	return floor(digits) + 1; 
} 

// Driver code 
int main() 
{ 
	cout << findDigits(1) << endl; 
	cout << findDigits(5) << endl; 
	cout << findDigits(10) << endl; 
	cout << findDigits(120) << endl; 
	return 0; 
} 


// Method 2

// A optimised program to find the 
// number of digits in a factorial 
#include <bits/stdc++.h> 
using namespace std; 

// Returns the number of digits present 
// in n! Since the result can be large 
// long long is used as return type 
long long findDigits(int n) 
{ 
	// factorial of -ve number 
	// doesn't exists 
	if (n < 0) 
		return 0; 

	// base case 
	if (n <= 1) 
		return 1; 

	// Use Kamenetsky formula to calculate 
	// the number of digits 
	double x = ((n * log10(n / M_E) + 
				log10(2 * M_PI * n) / 
				2.0)); 

	return floor(x) + 1; 
} 

// Driver Code 
int main() 
{ 
	cout << findDigits(1) << endl; 
	cout << findDigits(50000000) << endl; 
	cout << findDigits(1000000000) << endl; 
	cout << findDigits(120) << endl; 
	return 0; 
} 


