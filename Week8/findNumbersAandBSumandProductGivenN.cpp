// C++ program to find a and b 
// such that a*b=N and a+b=N 

#include <bits/stdc++.h> 
using namespace std; 

// Function to return the smallest string 
void findAandB(double N) 
{ 
	double val = N * N - 4.0 * N; 

	// Not possible 
	if (val < 0) { 
		cout << "NO"; 
		return; 
	} 

	// find a and b 
	double a = (N + sqrt(val)) / 2.0; 
	double b = (N - sqrt(val)) / 2.0; 

	cout << "a = " << a << endl; 
	cout << "b = " << b << endl; 
} 

// Driver Code 
int main() 
{ 
	double N = 69.0; 
	findAandB(N); 
	return 0; 
} 

// If sum and product are not equal

/*

void findAandB(int sum, int product) 
{ 

	int a = 1;
	int b = -sum;
	int c = product;
	
	
	int val = (int) sqrt((b * b) - 4 * a*c); 

	// Not possible 
	if (val < 0) { 
		cout << "NO"; 
		return; 
	} 

	// find a and b 
	double a = (int)(-b + val) / 2*a; 
	double b = (int)(-b - val) / 2*a; 

	cout << "a = " << a << endl; 
	cout << "b = " << b << endl; 
} 

*/
