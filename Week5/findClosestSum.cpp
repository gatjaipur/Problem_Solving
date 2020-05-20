#include<iostream>
#include<math.h>
using namespace std;

void findClosestSum(int arr[], int n, int sum) {
	
	int l = 0; 
	int r = n-1;
	int res_a = 0;
	int res_b = 0;
	int diff = INT_MAX;
	while(l<r) {
		
		if(abs((arr[l] + arr[r] ) - sum) < diff) {
			diff = abs((arr[l] + arr[r] ) - sum);
			res_a = l;
			res_b = r;
		} 
		
		if(arr[l] + arr[r] > sum) {
						r--;

		} else {			l++;

		}
	}
	
	cout << arr[res_a] << " + " << arr[res_b] ;
}

int main() {
	int arr[] = {2, 5, 3, 7, 2, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 15;
	
	findClosestSum(arr, n, sum);
	return 0;
}
