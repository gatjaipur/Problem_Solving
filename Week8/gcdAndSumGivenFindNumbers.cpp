// C++ program to find two numbers 
// whose sum and GCD is given 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find two numbers 
// whose sum and gcd is given 
void findTwoNumbers(int sum, int gcd) 
{ 
	// sum != gcd checks that both the 
	// numbers are positive or not 
	if (__gcd(gcd, sum - gcd) == gcd && sum != gcd) 
		cout << "a = " << min(gcd, sum - gcd) 
			<< ", b = " << sum - min(gcd, sum - gcd) 
			<< endl; 
	else
		cout << -1 << endl; 
} 

// Driver code 
int main() 
{ 
	int sum = 8; 
	int gcd = 2; 

	findTwoNumbers(sum, gcd); 

	return 0; 
} 

