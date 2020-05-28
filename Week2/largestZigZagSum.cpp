#include<iostream>
#include <bits/stdc++.h> 
#define MAX 100

using namespace std;
int dp[MAX][MAX]; 


    int largestZZSrec(int mat[][MAX], int i, int j, int n)
	{
		if(dp[i][j] != -1)
		{
			return dp[i][j];
		}
		if(i == n-1)
		{
			return (dp[i][j] = mat[i][j]);
		}
		
		int zzs = 0;
		
		for(int k = 0; k < n; k++)
		{
			if(k!=j)
			{
				zzs = max(zzs, largestZZSrec(mat, i+1, k, n));
			}
		}
		return (dp[i][j] = (zzs + mat[i][j]));
	}
	
    int largestZZS(int mat[][MAX], int n) 
	{
   memset(dp, -1, sizeof(dp)); 
		
		int res =0;
		for(int j=0; j < n; j++)
		{
			res = max(res, largestZZSrec(mat,0,j,n));
		}
		return res;
		
	}
	
	int main() {
		int n = 3;
		int mat[][MAX] = {{4,2,1}, {3,9,6}, {11,3,15}};
		
		cout << largestZZS(mat, n) << endl;
		return 0;
	}


