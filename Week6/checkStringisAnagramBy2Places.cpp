/*
Given two strings, the task is to find if a string ('a') can be obtained by rotating another string ('b') by two places.
Examples:

Input : a = "amazon" 
        b = "azonam"  // rotated anti-clockwise
Output : 1

Input : a = "amazon"
        b = "onamaz"  // rotated clockwise
Output : 1


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. In the next two line are two string a and b.

Output:
For each test case in a new line print 1 if the string 'a' can be obtained by rotating string 'b' by two places else print 0.

Constraints:
1<=T<=50
1<=length of a, b <100

Example:
Input:
2
amazon
azonam
geeksforgeeks
geeksgeeksfor
Output:
1
0

*/

#include <iostream>
using namespace std;


void isStrRotated(string a, string b)
{
    // char arr1[a.length()+1];
    // char arr2[b.length()+1];
    
    // strcpy(arr1,a.c_str);
    // strcpy(arr2,b.c_str);
    
    if(a.substr(0,2)==b.substr(b.length()-2,2) && a.substr(2)==b.substr(0,b.length()-2))
    {
                    cout<< "1"<<endl;

    }
    else
    {
        if(b.substr(2)==a.substr(0,a.length()-2) && a.substr(a.length()-2,2)==b.substr(0,2))
        {
                        cout<< "1"<<endl;

        }
        else
        {
            cout<< "0"<<endl;
        }
    }
}


int main() {

int T;
cin>>T;


std::string a;
std::string b;

while(T--)
{
    cin>>a;
    cin>>b;

isStrRotated(a,b);

}


	return 0;
}
