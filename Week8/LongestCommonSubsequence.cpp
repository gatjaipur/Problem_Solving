//LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
//LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.


//T(n) = O(mn)


/* Dynamic Programming C/C++ implementation of LCS problem */
/*
#include<bits/stdc++.h> 
   
int max(int a, int b); 
   
// Returns length of LCS for X[0..m-1], Y[0..n-1] 
int lcs( char *X, char *Y, int m, int n ) 
{ 
   int L[m+1][n+1]; 
   int i, j; 
   
// Following steps build L[m+1][n+1] in bottom up fashion. Note  
 // that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] 
   for (i=0; i<=m; i++) 
   { 
     for (j=0; j<=n; j++) 
     { 
       if (i == 0 || j == 0) 
         L[i][j] = 0; 
   
       else if (X[i-1] == Y[j-1]) 
         L[i][j] = L[i-1][j-1] + 1; 
   
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]); 
     } 
   } 
     
 // L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] 
   return L[m][n]; 
} 
   
// Utility function to get max of 2 integers 
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 
   
int main() 
{ 
  char X[] = "AGGTAB"; 
  char Y[] = "GXTXAYB"; 
   
  int m = strlen(X); 
  int n = strlen(Y); 
   
  printf("Length of LCS is %d", lcs( X, Y, m, n ) ); 
  
  return 0; 
}

*/

// METHOD 2 
//Space = O(n)




// Space optimized C++ implementation 
// of LCS problem 
#include<bits/stdc++.h> 
using namespace std; 

// Returns length of LCS 
// for X[0..m-1], Y[0..n-1] 
int lcs(string &X, string &Y) 
{ 
	
	// Find lengths of two strings 
	int m = X.length(), n = Y.length(); 

	int L[2][n + 1]; 

	// Binary index, used to 
	// index current row and 
	// previous row. 
	bool bi; 

	for (int i = 0; i <= m; i++) 
	{ 
		
		// Compute current 
		// binary index 
		bi = i & 1; 

		for (int j = 0; j <= n; j++) 
		{ 
			if (i == 0 || j == 0) 
				L[bi][j] = 0; 

			else if (X[i-1] == Y[j-1]) 
				L[bi][j] = L[1 - bi][j - 1] + 1; 

			else
				L[bi][j] = max(L[1 - bi][j], 
							L[bi][j - 1]); 
		} 
	} 

	// Last filled entry contains 
	// length of LCS 
	// for X[0..n-1] and Y[0..m-1] 
	return L[bi][n]; 
} 

// Driver code 
int main() 
{ 
	string X = "AGGTAB"; 
	string Y = "GXTXAYB"; 

	printf("Length of LCS is %d\n", lcs(X, Y)); 

	return 0; 
} 

