//Smallest divisible number divisible by 1 to n
// C++ program to find LCM of First N Natural Numbers. 
#include <bits/stdc++.h> 
#define MAX 100000 
using namespace std; 

// array to store all prime less than and equal to 10^6 
vector <int> primes; 

// utility function for sieve of sieve of Eratosthenes 
void sieve() 
{ 
	bool isComposite[MAX] = {false}; 
	for (int i=2; i*i<=MAX; i++) 
	{ 
		if (isComposite[i]==false) 
			for (int j=2; j*i<=MAX; j++) 
				isComposite[i*j] = true; 
	} 

	// Store all prime numbers in vector primes[] 
	for (int i=2; i<=MAX; i++) 
		if (isComposite[i]==false) 
			primes.push_back(i); 
} 

// Function to find LCM of first n Natural Numbers 
long long LCM(int n) 
{ 
	long long lcm = 1; 
	for (int i=0; i<primes.size() && primes[i]<=n; i++) 
	{ 
		// Find the highest power of prime, primes[i] 
		// that is less than or equal to n 
		int pp = primes[i]; 
		while (pp*primes[i] <= n) 
			pp = pp *primes[i]; 

		// multiply lcm with highest power of prime[i] 
		lcm *= pp; 
		lcm %= 1000000007; 
	} 
	return lcm; 
} 

// Driver code 
int main() 
{ 
	sieve(); 
	int N = 7; 
	cout << LCM(N); 
	return 0; 
} 

// Method 2 
/*
// Java program to find the smallest number evenly divisible by 
// all numbers 1 to n 

class GFG{ 

static long gcd(long a, long b) 
{ 
if(a%b != 0) 
	return gcd(b,a%b); 
else
	return b; 
} 

// Function returns the lcm of first n numbers 
static long lcm(long n) 
{ 
	long ans = 1;	 
	for (long i = 1; i <= n; i++) 
		ans = (ans * i)/(gcd(ans, i)); 
	return ans; 
} 

// Driver program to test the above function 
public static void main(String []args) 
{ 
	long n = 20; 
	System.out.println(lcm(n)); 

} 
} 
*/
