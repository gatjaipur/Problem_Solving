//Addition Under Modulo
//A few distributive properties of modulo are as follows:
//
//( a + b) % c = ( ( a % c ) + ( b % c ) ) % c
//( a * b) % c = ( ( a % c ) * ( b % c ) ) % c
//( a – b) % c = ( ( a % c ) – ( b % c ) ) % c
//
////( a / b ) % c != ( ( a % c ) / ( b % c ) ) % c
//

//10^9+7 fulfills both the criteria. It is the first 10-digit prime number and fits in int data type as well. In fact, any prime number less than 2^30 will be fine in order to prevent possible overflows.
int sumUnderModulo(long long a,long long b)
{
    
    int M=1000000007;
    //your code here
    
    int res = a%M;
    res+= b%M;
    return res;
}


//

unsigned long long factorial(int n) 
{ 
	const unsigned int M = 1000000007; 

	unsigned long long f = 1; 
	for (int i = 1; i <= n; i++) 
		f = (f*i) % M; // Now f never can 
						// exceed 10^9+7 
	return f; 
} 


//

int mod(int a, int m) 
{ 
	return (a%m + m) % m; 
} 

