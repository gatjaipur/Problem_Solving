// METHOD 1 Using simple iteration
//Implementation is done for frequency strictly less than the value of digit except for 0 
//......as 0 if not present will return false always, and 0 can not be less than 0, therefore we make it exception
// 1 should occur for atmost 0 times

/*
#include<iostream>
using namespace std;

int checkFreq(long int n)
{
	for(int i=0; i<10; i++)
	{
		long int temp =n;
		int count =0;
		while(temp)
		{
			if(temp%10 == i)
			{
				count++;
			}
			
			if(i != 0)
			{
			if(count == i)
			{
				return i;
			}	
			}
			else
			{
				if(count > i)
			{
				return i;
			}
			}
			
			temp/=10;
		}
	}
	return -1;
}


int main()
{
	long int n = 256;
	int res = checkFreq(n);
	if(res == -1)
	{
		cout << "Frequency of each digit is numerically less than digit";
		
	}
	else
	{
			cout << "Frequency of "<< res <<" is not numerically less than digit";
	
	}
	return 0;
}

*/


//METHOD 2 Using count array


#include<iostream>
using namespace std;

int checkFreq(long int n)
{
	int count[10] = {0};
	
	while(n)
	{
		int r = n%10;
		count[r]++;
		
		if(count[r] == r)
		{
			return r;
		}
		
		n/=10;
	}
	
	return -1;
}



int main()
{
	long int n = 255556;
	int res = checkFreq(n);
	if(res == -1)
	{
		cout << "Frequency of each digit is numerically less than digit";
		
	}
	else
	{
			cout << "Frequency of "<< res <<" is not numerically less than digit";
	
	}
	return 0;
}

