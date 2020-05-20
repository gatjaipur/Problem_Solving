//METHOD 1
//T(n) = O(n)
//Space = O(m + n)

#include<iostream>
using namespace std;
#define MAX 100

    void searchElement(int mat[][MAX], int n, int x)
	{
		int i = 0;
		int j = n-1;
		
		while(i < n && j>=0)
		{
			if(mat[i][j] == x)
			{
				cout << "Value is found at row : " << i << " and column : " << j ;
				return;
			}
			else
				if(mat[i][j] > x)
				{
					j--;
				}
				else
				{
					i++;
				}
		}
		
		cout << "Value is not found";
		return;
	}
	
	int main()
	{
		int mat[][MAX] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

//Here we need to mention size, for unknown size use 2 D vector for example, 
/*
	  int calculateDeterminantOfTheMatrix(vector<vector<int> > &matrix) 
	{
      int res = 0;
      for (int i = 0 ; i != matrix.size() ; i++)
      for(int j = 0 ; j != matrix[i].size() ; j++)
        res += matrix[i][j];
      return res;
    }
*/

int rows =  sizeof(mat)/ sizeof(mat[0]); // 2 rows  

int cols = sizeof(mat[0])/ sizeof(int);	
	  
	    int n = 4;
	  	int x = 5;
		searchElement(mat, n, x);
		return 0;
	}


//METHOD 2 Search one by one 
// T(n) = O(n^2)
