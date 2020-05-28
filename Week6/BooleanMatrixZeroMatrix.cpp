/*
// C++ Code For A Boolean Matrix Question 
#include <bits/stdc++.h> 

using namespace std; 
#define R 3 
#define C 4 

void modifyMatrix(bool mat[R][C]) 
{ 
	bool row[R]; 
	bool col[C]; 

	int i, j; 
	
	for (i = 0; i < R; i++) 
	{ 
	row[i] = 0; 
	} 

	for (i = 0; i < C; i++) 
	{ 
	col[i] = 0; 
	} 

	// Store the rows and columns to be marked as 
	// 1 in row[] and col[] arrays respectively 
	for (i = 0; i < R; i++) 
	{ 
		for (j = 0; j < C; j++) 
		{ 
			if (mat[i][j] == 1) 
			{ 
				row[i] = 1; 
				col[j] = 1; 
			} 
		} 
	} 

	// Modify the input matrix mat[] using the 
	// above constructed row[] and col[] arrays 
	for (i = 0; i < R; i++) 
	{ 
		for (j = 0; j < C; j++) 
		{ 
			if ( row[i] == 1 || col[j] == 1 ) 
			{ 
				mat[i][j] = 1; 
			} 
		} 
	} 
} 

void printMatrix(bool mat[R][C]) 
{ 
	int i, j; 
	for (i = 0; i < R; i++) 
	{ 
		for (j = 0; j < C; j++) 
		{ 
			cout << mat[i][j]; 
		} 
		cout << endl; 
	} 
} 

// Driver Code 
int main() 
{ 
	bool mat[R][C] = { {1, 0, 0, 1}, 
					{0, 0, 1, 0}, 
					{0, 0, 0, 0}}; 

	cout << "Input Matrix \n"; 
	printMatrix(mat); 

	modifyMatrix(mat); 

	printf("Matrix after modification \n"); 
	printMatrix(mat); 

	return 0; 
} 

*/


// Method 2 O(1)

#include <bits/stdc++.h> 
using namespace std; 
#define R 3 
#define C 4 

void modifyMatrix(int mat[R][C]) 
{ 
	// variables to check if there are any 1 
	// in first row and column 
	bool row_flag = false; 
	bool col_flag = false; 

	// updating the first row and col if 1 
	// is encountered 
	for (int i = 0; i < R; i++) { 
		for (int j = 0; j < C; j++) { 
			if (i == 0 && mat[i][j] == 1) 
				row_flag = true; 

			if (j == 0 && mat[i][j] == 1) 
				col_flag = true; 

			if (mat[i][j] == 1) { 

				mat[0][j] = 1; 
				mat[i][0] = 1; 
			} 
		} 
	} 

	// Modify the input matrix mat[] using the 
	// first row and first column of Matrix mat 
	for (int i = 1; i < R; i++) { 
		for (int j = 1; j < C; j++) { 

			if (mat[0][j] == 1 || mat[i][0] == 1) { 
				mat[i][j] = 1; 
			} 
		} 
	} 

	// modify first row if there was any 1 
	if (row_flag == true) { 
		for (int i = 0; i < C; i++) { 
			mat[0][i] = 1; 
		} 
	} 

	// modify first col if there was any 1 
	if (col_flag == true) { 
		for (int i = 0; i < R; i++) { 
			mat[i][0] = 1; 
		} 
	} 
} 

/* A utility function to print a 2D matrix */
void printMatrix(int mat[R][C]) 
{ 
	for (int i = 0; i < R; i++) { 
		for (int j = 0; j < C; j++) { 
			cout << mat[i][j]; 
		} 
		cout << "\n"; 
	} 
} 

// Driver function to test the above function 
int main() 
{ 

	int mat[R][C] = { { 1, 0, 0, 1 }, 
					{ 0, 0, 1, 0 }, 
					{ 0, 0, 0, 0 } }; 

	cout << "Input Matrix :\n"; 
	printMatrix(mat); 

	modifyMatrix(mat); 

	cout << "Matrix After Modification :\n"; 
	printMatrix(mat); 
	return 0; 
} 

// This code is contributed by Nikita Tiwari 

