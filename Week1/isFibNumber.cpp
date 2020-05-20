#include<iostream>
#include<math.h>
using namespace std;


// METHOD 1 Generate fib number upto N and see if it exists
/*
int generateFib(int n)
{
	int a =0;
	int b = 1;
	
	while(b < n)
	{
		int temp =b;
		b = b + a;
		a = temp;
	}
	return b;
}

bool checkFib(int n)
{
	
	int res = generateFib(n);
	return (res == n); 
}
*/


//METHOD 2 Using formula for perfect square to identify fib number

bool checkFib(int n)
{
	int root = sqrt(n);
	
	return (root*root == n);
}

int main()
{
	int n = 89;
	
	if((checkFib(5*n*n + 4)) || (checkFib(5*n*n - 4)))
	{
		cout << n << " is a fib number";	
	}
	else
	{
				cout << n << " is not a fib number";
	}
	
	return 0;
}
