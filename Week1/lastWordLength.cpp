#include<iostream>

using namespace std;
// METHOD 1 using loop
/*
int lastWordLength(const string& str)
{
	if(str.empty())
	{
		return 0;
	}
	
	int n = str.length();
	bool flag = false;
	int len =0;
	for(int i = n-1; i>0 ; i--)
	{
		char ch = str[i];
		cout << ch <<endl;
		if((ch >= 'a' && ch <= 'z')||(ch >= 'A' && ch <= 'Z' ) )
		{
			flag = true; len++;
		}
		else
		{
			if(flag)
			{
				return len;
			}
		}
				
	}
			return len;

}
*/



// METHOD 2 Using Vector
#include<vector>
#include <bits/stdc++.h> 

int lastWordLength(const string& str)
{
	if(str.empty())
	{
		return 0;
	}
	vector<string> vec;
	stringstream ss(str);
	string intermediate;
	while(getline(ss, intermediate, ' '))
	{
		vec.push_back(intermediate);
	}
	
	return (vec.at(vec.size()-1).length());
}

int main()
{
	string str = "I am Gaurav Garg";
	cout << lastWordLength(str) <<endl;
	return 0;
}
