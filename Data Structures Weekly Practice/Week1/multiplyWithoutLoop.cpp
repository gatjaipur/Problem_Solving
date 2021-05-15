#include<iostream>
using namespace std;

//METHOD 1 USING RECURSION

/*
int multiply(int x, int y)
{
	if(y == 0)
	{
		return 0;
	}
	
	if(y>0)
	{
		return (x + multiply(x, y-1));
	}
	
	if(y<0)
	{
		return -(multiply(x,-y)); 
	}
}

*/


//METHOD 2 USING BITWISE OPERATORS
int multiply(int x, int y)
{
	int res =0;
	
	bool flag = false;
	
	if(x < 0 && y<0)
	{
		flag = false;
	}
	else
	{
		if(x <0)
		{
			flag = true;
			x = -x;
		}
		else
		if(y<0)
		{
			flag = true;
			y = -y;
		}
	}
	
	while(y>0)
	{
		if(y & 1)
		{
			res = res + x;
		}
		
		x=x<<1;
		y=y>>1;
	}
	
	if(flag)
	{
		res = -res;
	}
	return res;
}

int main()
{
	cout << multiply(5, -2);
	return 0;
}
