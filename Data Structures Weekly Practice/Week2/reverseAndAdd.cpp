#include<iostream>
using namespace std;

int reverse(int num)
{
	int res = 0;
	
	while(num > 0)
	{
		int mod = num % 10;
		res = res*10 + mod;
		num/=10;
	}
	
	return res;
}

bool checkPal(int num)
{
	if(num == reverse(num))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void reverseAndAdd(int num)
{
	if(checkPal(num))
	{
		cout << " number is palindrome" <<endl;
		return;		
	}	
	else
	{
		int temp = num;
		while(!checkPal(temp))
		{
			int rev = reverse(temp);
			int sum = temp + rev;
			
			temp = sum;
		}
			cout << "num : " << temp << endl;

	}
	
	return;
}

int main()
{
	int num = 13;
	reverseAndAdd(num);
	return 0;
}
