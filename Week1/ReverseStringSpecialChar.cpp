//T(n) = O(n)
//space(n) = O(1)


#include<iostream>
using namespace std;

bool isAlphabet(char ch)
{
	return ((ch > 'a' && ch <'z' )|| (ch > 'A' && ch < 'Z'));
}
void reverseSpclChar(string& str, int l, int r)
{
	while(l<r)
	{
		if(!isAlphabet(str[l])) //we can use if( isalpha(str[l]) ! = 0) and for digits if(isdigit(str[l]) != 0)
		{
			
			l++;
		}
		
		else if(!isAlphabet(str[r]))
		{	
			r--;
		}
		
		else
		{
			swap(str[l],str[r]);
			r--; l++;
		}
	}
	
}

void print(string& str, int n)
{
	cout <<str<<endl;
}
int main()
{
	string str = "I@am_Gaurav Garg";
	int n = str.length();
	
	reverseSpclChar(str,0,n-1);
	print(str,n);
	
	return 0;
}
