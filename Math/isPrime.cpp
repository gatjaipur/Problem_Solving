//TO CHECK WHETHER NUMBER IS PRIME OR NOT


#include<iostream>
#include<math.h>
using namespace std;



//METHOD 1 -- ITERATING TILL N/2
//T(n) = O(n)

/*
bool isPrime(int num)
{	
	if(num < 2)
	{
		return false;
	}
	
	int n = num/2; // or use sqrt(num) , it gives prime for exception 39601(not a prime i.e. 199^2);
	
	for(int i = 2; i < n; i++)
	{
		if(num%i == 0)
		{
			return false;
		}
	}
	
	return true;
}
*/

//METHOD 2 Optimized School method iterate till root n and skip for 5 numbers as every int is 6k+ 0, 1, 2 , 3, 4 divided bu 2 and 3 respectively
//T(n) = O(root(n))


bool isPrime(int num)
{	
	if(num < 2)
	{
		return false;
	}
	
	if(num <= 3)
	{
		return true;
	}
	
	if(num%2 == 0 || num%3 == 0)
	{
		return false;	
	}
	
	for(int i = 5; i*i <= num; i= i+6)
	{
		if(num%i == 0 || num%(i+2) == 0)
		{
			return false;
		}
	}
	
	return true;
}

int main()
{
	int num = 39601;
	if(isPrime(num))
	{
		cout << num << " is Prime" << endl;
	}
	else
	{
		cout << num << " is not Prime" << endl;
	}
	return 0;
}
