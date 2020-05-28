#include<iostream>
using namespace std;

//Method - 1 Using T B L R
void printSpiral(int mat[3][3], int m, int n) {
	
	int T = 0;
	int L = 0;
	int B = m-1;
	int R = n-1;
	int dir = 0;
	
	while(T<=B && L<=R) {
		if(dir == 0) {
					for(int i = L; i<=R; i++) {
						cout << mat[T][i] << " ";
					}
					T++;
					dir = 1;
				} 
				
		if(dir == 1) {
			for(int i = T; i<=B; i++) {
						cout << mat[i][R] << " ";
					}
					R--;
					dir = 2;
				} 
				
		
		
				if(dir == 2) {
			for(int i = R; i >= L; i--) {
						cout << mat[B][i] << " ";
					}
					B--;
					dir = 3;
				} 
				
		
		
				if(dir == 3) {
			for(int i = B; i >= T; i--) {
						cout << mat[i][L] << " ";
					}
					L++;
					dir = 0;
				} 		
		}		
	}
	


//Method -2 Using Switch case and layer
/*
void printSpiral(int mat[3][3], int m, int n) {
	
	int dir = 0;
int layer = 0;
int row = 0;
int cols = 0;

cout << mat[0][0] << " ";

	for(int i = 1; i< m*n; i++) {
		
		switch(dir) {
			
			case 0: { if( cols == n-layer-1) {
				row++;
				dir = 1;
			} else {
				cols++;
			}}
				break;
			
			case 1: { if( row == m-layer-1) {
				cols--;
				dir = 2;
			} else {
				row++;
			}}
				break;
			
						case 2: { if( cols == layer) {
				row--;
				dir = 3;
			} else {
				cols--;
			}}
				break;
			
						case 3: { if( row == layer + 1) {
				cols++;
				dir = 0;
				layer++;
			} else {
				row--;
			}}
				break;
			
				
		}
		
		cout << mat[row][cols] << " ";
	}

}
*/

/*
// Method - 3 Using minRow and minCols, clockwise direction, fill matrix in clockwise dir with natural numbers
// We can also print the matrix if exists using dir and if statements

void printSpiral(int mat[3][3], int m, int n) {
	
	int minRow = 0;
	int maxRow = m-1;
	int minCols = 0;
	int maxCols = n-1;
	
	int k = 1;
	while(k <= m*n) {
		
		for(int i = minCols; i <= maxCols; i++) {
			mat[minRow][i] = k;
			k++;
		}
		
				for(int i = minRow+1; i <= maxRow; i++) {
			mat[i][maxCols] =  k;
			k++;
		}
		
				for(int i = maxCols -1; i >= minCols; i--) {
			mat[maxRow][i] =  k;
			k++;
		}
		
				for(int i = maxRow-1; i >= minRow+1; i--) {
			mat[i][minCols] =  k;
			k++;
		}
		
		minRow++;
		minCols++;
		maxRow--;
		maxCols--;
	}

	for(int i = 0; i < m; i++) {
		for( int j = 0; j< n; j++) {
			cout << mat[i][j] << " ";
		}
	}
	
}

int main() {
	
	int mat[3][3];
	
	int m = sizeof(mat)/sizeof(mat[0]);
	int n = sizeof(mat[0])/sizeof(mat[0][0]);
	
	printSpiral(mat, m, n);
	
	return 0;
}
*/
/*
// Method - 3 Using minRow and minCols, clockwise direction, fill matrix in anti-clockwise dir with natural numbers
// We can also print the matrix if exists using dir and if statements

void printSpiral(int mat[3][3], int m, int n) {
	
	int minRow = 0;
	int maxRow = m-1;
	int minCols = 0;
	int maxCols = n-1;
	
	int k = 1;
	while(k <= m*n) {
		
		for(int i = minRow; i <= maxRow; i++) {
			mat[i][minCols] = k;
			k++;
		}
		
				for(int i = minCols+1; i <= maxCols; i++) {
			mat[maxRow][i] =  k;
			k++;
		}
		
				for(int i = maxRow -1; i >= minRow; i--) {
			mat[i][maxCols] =  k;
			k++;
		}
		
				for(int i = maxCols-1; i >= minCols+1; i--) {
			mat[minRow][i] =  k;
			k++;
		}
		
		minRow++;
		minCols++;
		maxRow--;
		maxCols--;
	}

	for(int i = 0; i < m; i++) {
		for( int j = 0; j< n; j++) {
			cout << mat[i][j] << " ";
		}
	}
	
}

int main() {
	
	int mat[3][3];
	
	int m = sizeof(mat)/sizeof(mat[0]);
	int n = sizeof(mat[0])/sizeof(mat[0][0]);
	
	printSpiral(mat, m, n);
	
	return 0;
}

*/
