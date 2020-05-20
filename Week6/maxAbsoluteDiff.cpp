#include<iostream>
#include<math.h>
using namespace std;

//Method 1 T. N = O(n^2)

/*
int maxAbsDiff(int arr[], int n) {
	
	int diff = INT_MIN;
	
	for(int i = 0; i< n; i++) {
		for(int j = 0; j<n; j++) {
			if(abs(arr[i] - arr[j]) + abs(i - j) >  diff) {
				diff = abs(arr[i] - arr[j]) + abs(i - j);
			}
		
		}
		
	}	
	
	return diff;
}

*/

//Method 2  T.C. O(n)

int maxAbsDiff(int arr[], int n) {
	
	int min1 = INT_MAX;
	int min2 = INT_MAX;
	int max1 = INT_MIN;
	int max2 = INT_MIN;
	
	for (int i = 0; i<n; i++) {
		min1 = min(min1, arr[i] + i);
		min2 = min(min2, arr[i] - i);
		max1 = max(max1, arr[i] + i);
		max2 = max(max2, arr[i] - i);
	}
	
	int res;
	res = max(res, max2 - min2);
	res = max(res, max1 - min1);
	
	return res;

} 
  
int main() {
	
	int arr[] = {-2, 2, 4, -4, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout << maxAbsDiff(arr, n);
	
}


