//Method 1 Sort array, return arr[n-2];

//Method -2 

#include<iostream>
using namespace std;

int findSecondMax(int arr[], int n) {
	
	int maximum = INT_MIN;
	int secondMaximum = INT_MIN;
	
	for(int i = 0; i<n; i++) {
		if(arr[i] > maximum) {
			secondMaximum = maximum;
			maximum = arr[i];
		} else if (arr[i] > secondMaximum) {
			secondMaximum = arr[i];
		}
	}
	
	return secondMaximum;
}


int main() {
	int arr[] = {4, 2, 6, 1, 9, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << findSecondMax(arr, n);	
	return 0;
}
