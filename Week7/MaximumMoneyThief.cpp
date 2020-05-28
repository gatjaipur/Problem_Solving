/*
Given street of houses (a row of houses), each house having some amount of money kept inside; 
now there is a thief who is going to steal this money but he has a constraint/rule that he cannot steal/rob two adjacent houses.
Find the maximum money he can rob.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N and money.

Output:

Print maximum money he can rob.

Constraints:

1 <= T <= 100
1 <= money <= 100
1 <= N <= 1000

Example:

Input:

2

5 10

2 12

Output:

30

12
*/

/*
or
Simply we need to print the result as (n/2)*money if n is even else n is odd  then (n/2+1) *money
*/

#include <iostream>
using namespace std;

void calculateMaxMoney(int arr[])
{
    int houseArray[arr[0]];
    int count=0;
    
    for(int j=0; j<arr[0]; j+=2)
    {
        count++;
    }
    
    cout<< (count*arr[1])<<endl;
}

int main() {


int T;
cin>>T;

int arr[2];

while(T--)
{
for(int i=0; i<2; i++)
{
    cin>>arr[i];
}

calculateMaxMoney(arr);
}
	return 0;
}

