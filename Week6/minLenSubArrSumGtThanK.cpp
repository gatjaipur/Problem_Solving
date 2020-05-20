// Min lenght subarray with sum greater than gven value T. C. = O(N^2)
/*
#include<iostream>
using namespace std;

int minLenSubArr(int arr[], int n, int k) {
	
	int minLength = n+1;
	
	
	for (int i = 0; i < n; i++) {
			int curSum = arr[i];

	if(	curSum > k) {
		return 1;
	}
		
		for(int j = i+1; j<n; j++) {
			
			curSum +=arr[j];
			if(curSum > k && (j-i + 1) < minLength) {
				minLength = j - i + 1;
			}
		}
	}
	
	return minLength;
}

int main() {
	int arr[] = {3, 5, 2, 5, 6, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	int k = 13;
	
	cout << minLenSubArr(arr, n, k);
	
	return 0;
}
*/
// Method 2 T C O(n)

#include<iostream>
using namespace std;

int minLenSubArr(int arr[], int n, int k) {
	
	int start = 0;
	int end = 0;
	int curSum = 0;
	int minLen = n+1;
	
	while(end < n) {
		
		while(end < n && curSum <= k) {
			if(curSum <=0 && k>0) {
				curSum = 0;
				start = end;
			}
			curSum+=arr[end++];
		}
		
		while(start < n && curSum > k) {
			
			if(end - start < minLen) {
				minLen = end - start;
			}
			curSum -= arr[start++];
		}
	}
	return minLen;
}

int main() {
	int arr[] = {3, 5, 2, 5, 6, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	int k = 13;
	
	cout << minLenSubArr(arr, n, k);
	
	return 0;
}
