// C++ program for left rotation of matrix by 180 
#include <bits/stdc++.h> 
using namespace std; 

#define R 4 
#define C 4 

// Function to rotate the matrix by 180 degree 
void reverseColumns(int arr[R][C]) 
{ 
	for (int i = 0; i < C; i++) 
		for (int j = 0, k = C - 1; j < k; j++, k--) 
			swap(arr[j][i], arr[k][i]); 
} 

// Function for transpose of matrix 
void transpose(int arr[R][C]) 
{ 
	for (int i = 0; i < R; i++) 
		for (int j = i; j < C; j++) 
			swap(arr[i][j], arr[j][i]); 
} 

// Function for display the matrix 
void printMatrix(int arr[R][C]) 
{ 
	for (int i = 0; i < R; i++) { 
		for (int j = 0; j < C; j++) 
			cout << arr[i][j] << " "; 
		cout << '\n'; 
	} 
} 

// Function to anticlockwise rotate matrix 
// by 180 degree 
void rotate180(int arr[R][C]) 
{ 
	transpose(arr); 
	reverseColumns(arr); 
	transpose(arr); 
	reverseColumns(arr); 
} 

// Driven code 
int main() 
{ 
	int arr[R][C] = { { 1, 2, 3, 4 }, 
					{ 5, 6, 7, 8 }, 
					{ 9, 10, 11, 12 }, 
					{ 13, 14, 15, 16 } }; 
	rotate180(arr); 
	printMatrix(arr); 
	return 0; 
} 

//Method 2
/*

// C++ program to rotate a matrix by 180 degrees 
#include <bits/stdc++.h> 
#define N 3 
using namespace std; 

// Function to Rotate the matrix by 180 degree 
void rotateMatrix(int mat[][N]) 
{ 
	// Simply print from last cell to first cell. 
	for (int i = N - 1; i >= 0; i--) { 
		for (int j = N - 1; j >= 0; j--) 
			printf("%d ", mat[i][j]); 

		printf("\n"); 
	} 
} 

// Driven code 
int main() 
{ 
	int mat[N][N] = { 
		{ 1, 2, 3 }, 
		{ 4, 5, 6 }, 
		{ 7, 8, 9 } 
	}; 

	rotateMatrix(mat); 
	return 0; 
} 
*/
