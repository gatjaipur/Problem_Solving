#include<iostream>
#include<math.h>
using namespace std;

//int maxContinuousSum(int arr[], int n) {
//	
//	int sum = INT_MIN;
//	
//	int last = 0;
//	
//	for (int i = 0; i< n; i++) {
//		last+=arr[i];
//		sum = max(sum, last);
//		
//		if(last < 0) {
//			last = 0;
//		}
//	}
//	
//	return sum;
//	
//}


// Extension For getting index

int maxContinuousSum(int arr[], int n) {
	int start = 0;
	int end = 0;
	int s = 0;
	
	int sum = INT_MIN;
	
	int last = 0;
	
	for (int i = 0; i< n; i++) {
		last+=arr[i];
		
		
		if(last > sum) {
			sum = last;
			end = i;
			start = s;
		}
		
		
		
		if(last < 0) {
			last = 0;
			s = i+1;
		}
	}
	cout << " i " << start << " and " << " j " << end << endl;
	return sum;
	
}


int main() {
	
	int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout << maxContinuousSum(arr, n);
	
}
