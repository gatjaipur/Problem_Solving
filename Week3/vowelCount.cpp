#include<iostream>
#include <algorithm>

using namespace std;

int vowelCount(string str)
{
	int count = 0;
	
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	
	for(int i = 0 ; i < str.length() ; i++)
	{
		switch(str[i])
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			cout << str[i] << " ";
			count++;
			break;
			default: ;
		}
	}
	
	return count;
}

int main()
{
	string str = "I am Gaurav Garg";
	cout << "\n" << vowelCount(str) << endl;
	return 0;
}
