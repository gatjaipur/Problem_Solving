#include<iostream>
using namespace std;

/*
//Method 1 ( Use recursion ) 
//Time Complexity: T(n) = T(n-1) + T(n-2) which is exponential.
//Extra Space: O(n) if we consider the function call stack size, otherwise O(1).

int fib(int n)
{
	if(n <= 1)
	{
		return n;
	}
	else
	{
		return fib(n-1) + fib(n-2);
	}
}

*/

//Method 2 ( Use Dynamic Programming )
//Time Complexity: O(n)
//Extra Space: O(n)

/*
int fib(int n)
{
	int f[n+2];
	int i;
	
	f[0]= 0;
	f[1]= 1;
	
//Add the previous 2 numbers in the series and store it 
	for(i=2; i<=n; i++)
	{
		f[i] = f[i-1] + f[i-2];
	}
	
	return f[n];
}
*/

//Method 3 ( Space Optimized Method 2 )
//Time Complexity: O(n)
//Extra Space: O(1)
/*
int fib(int n) 
{ 
  int a = 0, b = 1, c, i; 
  if( n == 0) 
    return a; 
  for (i = 2; i <= n; i++) 
  { 
     c = a + b; 
     a = b; 
     b = c; 
  } 
  return b; 
} 
*/

//Method 4 ( Using power of the matrix {{1,1},{1,0}} )
//Time Complexity: O(n)
//Extra Space: O(1)
/*

// Helper function that multiplies 2 matrices F and M of size 2*2, and 
//puts the multiplication result back to F[][] 
void multiply(int F[2][2], int M[2][2]); 
  
// Helper function that calculates F[][] raise to the power n and puts the 
//  result in F[][] 
//  Note that this function is designed only for fib() and won't work as general 
//  power function 
void power(int F[2][2], int n); 
  
int fib(int n) 
{ 
  int F[2][2] = {{1,1},{1,0}}; 
  if (n == 0) 
      return 0; 
  power(F, n-1); 
  
  return F[0][0]; 
} 
  
void multiply(int F[2][2], int M[2][2]) 
{ 
  int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0]; 
  int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1]; 
  int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0]; 
  int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1]; 
  
  F[0][0] = x; 
  F[0][1] = y; 
  F[1][0] = z; 
  F[1][1] = w; 
} 
  
void power(int F[2][2], int n) 
{ 
  int i; 
  int M[2][2] =  {{1,1},{1,0}}; 
  
  // n - 1 times multiply the matrix to {{1,0},{0,1}} 
  for (i = 2; i <= n; i++) 
      multiply(F, M); 
}

*/

//Method 5 ( Optimized Method 4 )
//Time Complexity: O(Logn)
//Extra Space: O(Logn) if we consider the function call stack size, otherwise O(1).

/*
void multiply(int F[2][2], int M[2][2]); 
  
void power(int F[2][2], int n); 
  
// function that returns nth Fibonacci number 
int fib(int n) 
{ 
  int F[2][2] = {{1,1},{1,0}}; 
  if (n == 0) 
    return 0; 
  power(F, n-1); 
  return F[0][0]; 
} 
  
// Optimized version of power() in method 4 
void power(int F[2][2], int n) 
{ 
  if( n == 0 || n == 1) 
      return; 
  int M[2][2] = {{1,1},{1,0}}; 
  
  power(F, n/2); 
  multiply(F, F); 
  
  if (n%2 != 0) 
     multiply(F, M); 
} 
  
void multiply(int F[2][2], int M[2][2]) 
{ 
  int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0]; 
  int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1]; 
  int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0]; 
  int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1]; 
  
  F[0][0] = x; 
  F[0][1] = y; 
  F[1][0] = z; 
  F[1][1] = w; 
} 


*/

//Method 6 Using Memoization
/*
 int fibArray[26] = {0};
 
int fib(int n)
{
	fibArray[0] = fibArray[1] = 1;
	
	int fibValue = 0;
	if(n == 0)
	{
		return 0;
	}
	else
	if(n ==1){
		return 1;
	}
	else
	{
		fibValue = fib(n-1) + fib(n-2);
		fibArray[n] = fibValue;
		return fibValue;
	}
}
*/

//Method 7 (O(Log n) Time)
//Time Complexity: O(Logn)

const int MAX = 1000;

int f[MAX] = {0};

int fib(int n)
{
	if(n == 0)
	{
		return 0;
	}
	
	if(n ==1 || n == 2)
	{
		return (f[n] = 1);
	}
	
	if(f[n])
	{
		return f[n];
	}
	
	int k = (n&1) ? (n+1)/2 : n/2;
	
	f[n] = (n&1) ? fib(k)*fib(k) + fib(k-1)*fib(k-1) : (2*(fib(k-1)) + fib(k))*fib(k) ;
	return f[n];
}

int main()
{
	int n = 6;
	cout << fib(n) << endl;
	return 0;
}
