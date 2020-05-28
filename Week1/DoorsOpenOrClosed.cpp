#include<iostream>
using namespace std;
#include <bits/stdc++.h> 


bool evenFactors(int i)
{
	int root = sqrt(i);
	
	if( root*root == i )
	{
		return false;
	}
	else 
	return true;
}


/* Method 2 to find if a number is a perfect square

bool evenFactors(long double i)
{
	long double root = sqrt(i);
	
	if( (root - floor(root)) == 0 )
	{
		return false;
	}
	else 
	return true;
}
*/

void printStatus(int n)
{
	for(int i=1 ; i<=n; i++)
	{
		if(evenFactors(i))
		{
			cout<< "closed ";
		}	
		else
		{
			cout << "open ";
		}
	}	
}

int main()
{
	int n = 5;
	printStatus(n);
	return 0;
}

