#include<iostream>
#include<stdio.h>

using namespace std;

int reverse(int x)
{
	bool flag = false;
	
	if(x<0 ) {
		flag = true; 
		x = 0-x;
	}
	
	long res = 0;
	long prev_rev_num =0;
	int p = x;
	
	while(p>0)
	{
		int mod = p%10;
		p=p/10;
		res = res*10 + mod;
		// checking if the reverse overflowed or not. 
        // The values of (rev_num - curr_digit)/10 and 
        // prev_rev_num must be same if there was no 
        // problem. 
        if ((res - mod)/10 != prev_rev_num) 
        { 
            printf("WARNING OVERFLOWED!!!\n"); 
            return 0; 
        } 
  
        prev_rev_num = res;
	}
	
	if(flag){
		res = 0 - res;
	}
	if(res> INT_MAX || res < INT_MIN){
		cout << "Integer Boundary Limits Exceeded";
		return 0;

	}
	int ans = (int) res;
	return ans;
}

int main()
{
	int num = -1234;
	cout << reverse(num);
return 0;
}
