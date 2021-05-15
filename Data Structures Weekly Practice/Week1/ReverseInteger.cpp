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
        if ((res - mod)/10 != prev_rev_num || (res>0 && prev_rev_num<0) || (res<0 && prev_rev_num>0)) 
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

//Method - 2
/*
Time Complexity: O(log(x)). 
Space Complexity: O(1)

If reversed is > MAX or < MIN, we know we've already exceeded the threshold, so we return 0.
However if reversed is == to MAX/MIN, then we just have to compare our 'pop' variable against the right-most digit of the max/min values. i.e. pop > 7 or pop < -8

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
*/