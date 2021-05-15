//sum upto n for fib number
#include<iostream>
using namespace std;

int fib(int n) {

int f[1000] = {0};

if(n == 0)
{
	return (f[n] = 0);
	
} else if (n == 1 || n == 2) {
		return (f[n] = 1);
}

if(f[n]) {
	return f[n];
}
	int k = (n&1) ? (n+1)/2 : n/2;
	
	f[n] = (n&1) ? fib(k)*fib(k) + fib(k-1)*fib(k-1) : (2*fib(k-1) + fib(k))*fib(k);
	
	return f[n];
}
  
  int sumFib(int n) {
  	return fib(n+2) - 1;
  }
  
int main() 
{ 
	int n = 5;
	cout << fib(n) << endl;
	cout << "sum upto n is " << sumFib(n) << endl;
	return 0; 
} 

