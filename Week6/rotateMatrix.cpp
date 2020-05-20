// C++ program to rotate a matrix by 90 degrees 
#include <bits/stdc++.h> 
#define N 4 
using namespace std; 

void displayMatrix(int mat[N][N]); 

// An Inplace function to rotate a N x N matrix 
// by 90 degrees in anti-clockwise direction 
void rotateMatrix(int mat[][N]) 
{ 
for(int x = 0; x< N/2; x++) {
	
	for(int y = x; y < N-1-x; y++) {
		
		//For 90 anticlockwise

		int temp = mat[x][y];
		mat[x][y] = mat[y][N-1-x];
		mat[y][N-1-x] = mat[N-1-x][N-1-y];
		mat[N-1-x][N-1-y] = mat[N-1-y][x];
		mat[N-1-y][x] = temp;

//For 90 clockwise
//	int temp = mat[x][y];
//	mat[x][y] = mat[N-1-y][x];
//	mat[N-1-y][x] = mat[N-1-x][N-1-y];
//	mat[N-1-x][N-1-y] = mat[y][N-1-x];
//	mat[y][N-1-x] = temp;
	}
}
	
} 

// Function to print the matrix 
void displayMatrix(int mat[N][N]) 
{ 
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < N; j++) 
			printf("%2d ", mat[i][j]); 

		printf("\n"); 
	} 
	printf("\n"); 
} 

/* Driver program to test above functions */
int main() 
{ 
	// Test Case 1 
	int mat[N][N] = { 
		{ 1, 2, 3, 4 }, 
		{ 5, 6, 7, 8 }, 
		{ 9, 10, 11, 12 }, 
		{ 13, 14, 15, 16 } 
	}; 

	rotateMatrix(mat); 

	// Print rotated matrix 
	displayMatrix(mat); 

	return 0; 
} 

// Method 2 Using Transpose and Reverse

/*
// C++ program for left rotation of matrix by 90 
// degree without using extra space 
#include <bits/stdc++.h> 
using namespace std; 
#define R 4 
#define C 4 

// After transpose we swap elements of column 
// one by one for finding left rotation of matrix 
// by 90 degree 
void reverseColumns(int arr[R][C]) 
{ 
	for (int i = 0; i < C; i++) 
		for (int j = 0, k = C - 1; j < k; j++, k--) 
			swap(arr[j][i], arr[k][i]); 
} 

// Function for do transpose of matrix 
void transpose(int arr[R][C]) 
{ 
	for (int i = 0; i < R; i++) 
		for (int j = i; j < C; j++) 
			swap(arr[i][j], arr[j][i]); 
} 

// Function for print matrix 
void printMatrix(int arr[R][C]) 
{ 
	for (int i = 0; i < R; i++) { 
		for (int j = 0; j < C; j++) 
			cout << arr[i][j] << " "; 
		cout << '\n'; 
	} 
} 

// Function to anticlockwise rotate matrix 
// by 90 degree 
void rotate90(int arr[R][C]) 
{ 
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
	rotate90(arr); 
	printMatrix(arr); 
	return 0; 
} 
*/
