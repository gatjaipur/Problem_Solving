// C++ program to check if given string is 
// an interleaving of the other two strings 
//C is said to be interleaving A and B, if it contains all characters of A and B and order of all characters in individual strings is preserved. See previous post for examples.
//Time Complexity: O(m+n) where m and n are the lengths of strings A and B respectively.
// Note that the above approach doesn’t work if A and B have some characters in common. For example, if string A = “AAB”, string B = “AAC” and string C = “AACAAB”, then the above method will return false

#include <bits/stdc++.h> 
using namespace std; 
//Method - 1

// Returns true if C is an interleaving of A and B, 
// otherwise returns false 
bool isInterleaved (char A[], char B[], char C[]) 
{ 
	// Iterate through all characters of C. 
	while (*C != 0) 
	{ 
		if (*A == *C) 
			A++; 

		else if (*B == *C) 
			B++; 

		else
			return false; 
		
		C++; 
	} 

	if (*A || *B) 
		return false; 

	return true; 
} 

int main() 
{ 
	char A[] = "AB"; 
	char B[] = "CD"; 
	char C[] = "ACBG"; 
	if (isInterleaved(A, B, C) == true) 
		cout << C << " is interleaved of " << A << " and " << B; 
	else
		cout << C << " is not interleaved of " << A << " and " << B; 

	return 0; 
} 


// Method 2
// Time Complexity: O(MN)
// Auxiliary Space: O(MN)
/*
 
#include <iostream> 
#include <string.h> 
using namespace std; 
 
bool isInterleaved(char* A, char* B, char* C) 
{ 
	// Find lengths of the two strings 
	int M = strlen(A), N = strlen(B); 

	// Let us create a 2D table to store solutions of 
	// subproblems. C[i][j] will be true if C[0..i+j-1] 
	// is an interleaving of A[0..i-1] and B[0..j-1]. 
	bool IL[M + 1][N + 1]; 

	memset(IL, 0, sizeof(IL)); // Initialize all values as false. 

	if ((M + N) != strlen(C)) 
		return false; 

	// Process all characters of A and B 
	for (int i = 0; i <= M; ++i) { 
		for (int j = 0; j <= N; ++j) { 
			// two empty strings have an empty string 
			// as interleaving 
			if (i == 0 && j == 0) 
				IL[i][j] = true; 

			// A is empty 
			else if (i == 0) { 
				if (B[j - 1] == C[j - 1]) 
					IL[i][j] = IL[i][j - 1]; 
			} 

			// B is empty 
			else if (j == 0) { 
				if (A[i - 1] == C[i - 1]) 
					IL[i][j] = IL[i - 1][j]; 
			} 

			else if (A[i - 1] == C[i + j - 1] && B[j - 1] != C[i + j - 1]) 
				IL[i][j] = IL[i - 1][j]; 

			else if (A[i - 1] != C[i + j - 1] && B[j - 1] == C[i + j - 1]) 
				IL[i][j] = IL[i][j - 1]; 

			// Current character of C matches with that of both A and B 
			else if (A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1]) 
				IL[i][j] = (IL[i - 1][j] || IL[i][j - 1]); 
		} 
	} 

	return IL[M][N]; 
} 

void test(char* A, char* B, char* C) 
{ 
	if (isInterleaved(A, B, C)) 
		cout << C << " is interleaved of " << A << " and " << B << endl; 
	else
		cout << C << " is not interleaved of " << A << " and " << B << endl; 
} 

int main() 
{ 
	test("XXY", "XXZ", "XXZXXXY"); 
	test("XY", "WZ", "WZXY"); 
	test("XY", "X", "XXY"); 
	test("YX", "X", "XXY"); 
	test("XXY", "XXZ", "XXXXZY"); 
	return 0; 
} 

*/

