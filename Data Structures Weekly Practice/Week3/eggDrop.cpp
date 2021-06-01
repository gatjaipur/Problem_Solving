#include<iostream>
using namespace std;

//Method 1

//int getMax(int a, int b) {
//	return ((a>b) ?  a : b);	
//}
//
//int eggDrop(int n, int k) {
//	if( k == 0 || k ==1) {
//		return k;
//	}
//	
//	if( n == 1) {
//		return k;
//	}
//	
//	int min = INT_MAX;
//	int res;
//	for(int i = 1; i<=k; i++) {
//		res = getMax(eggDrop(n-1, i-1), eggDrop(n, k-i));
//		if(res < min) {
//			min = res;
//		}
//	}
//	return min + 1;
//}

//Method 2

int getMax(int a, int b) {
	return ((a>b) ?  a : b);	
}

int eggDrop(int n, int k) {
	
	int drop[n+1][k+1] = {0};
	
	for(int i= 1; i<=n; i++) {
	
	drop[i][0] = 0;
	drop[i][1] = 1;
}

	for(int i = 1; i<=k; i++) {
		drop[1][i] = i;
	}
	
	int res;
	
	for(int i = 2; i<= n; i++) {	
	
	for(int j = 2; j<=k; j++) {
			drop[i][j] = INT_MAX;
			
			for(int x = 1; x<=j; x++){
				res = 1 + getMax(drop[i-1][x-1], drop[i][j-x]);
				if(res < drop[i][j]) {
					drop[i][j] = res;
				}
			}

	}
	
	}
	return drop[n][k];
}


int main() {
	int n = 2;
	int k = 10;
	cout << eggDrop(n, k);
	return 0;
}
