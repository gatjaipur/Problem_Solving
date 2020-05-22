/*Jarvis is weak in computing palindromes for Alphanumeric characters.
While Ironman is busy fighting Thanos, he needs to activate sonic punch but Jarvis is stuck in computing palindromes.
You are given a string containing the alphanumeric character. Find whether the string is palindrome or not.
If you are unable to solve it then it may result in the death of Iron Man.

Input:
The first line of the input contains t, the number of test cases. Each line of the test case contains string 'S'.

Output:
Each new line of the output contains "YES" if the string is palindrome and "NO" if the string is not a palindrome.

Constraints:
1<=t<=100
1<=|S|<=100000
Note: Consider alphabets and numbers only for palindrome check. Ignore symbols and whitespaces.

Example:
Input:
2
I am :IronnorI Ma, i
Ab?/Ba

Output:
YES
YES
*/

#include<iostream>
#include <cstring>
#include<ctype.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	
	while(t--)
	{
	string s;
	getline(cin,s);
	
	while (s.length()==0 )
            getline(cin, s);
	
	string s1="";
	for(int i=0;i<s.length();i++)
	{
	    if(isalnum(s[i])) 
	    {
	        if(int(s[i])>=65 && int(s[i])<=90)
	        {
	            int c= s[i]+32;
	            s1+=char(c);
	        }else s1+=s[i];
	    }
	}
	
	int i=0,j=s1.length()-1;
	int flag=0;
	while(i<j)
	{
	    if(s1[i]!=s1[j])
	    {
	        flag=1; break;
	    }else{
	        i++; j--;
	    }
	}if(flag==1) cout<<"NO"<<endl; else cout<<"YES"<<endl;}
	return 0;
}
