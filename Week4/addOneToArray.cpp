#include<iostream>
#include <vector>
using namespace std;

void addOne(int arr[], int n) {
	
	
	int carry = 0;
	arr[n-1] += 1;
	
	if(arr[n-1] == 10) {
		arr[n-1] = 0;
		carry = 1;
	}
	
	for(int i = n-2; i >=0; i--) {
		
		if(carry == 1) {
			arr[i] +=1;	
			carry = 0;		
		}
	    if(arr[i] == 10) {
		arr[i] = 0;
		carry = 1;
	}
	}
	
	vector<int> res;
	
	if(carry == 1) {
		res.push_back(1);
		carry = 0;
	}
	
	for (int i = 0; i<n; i++) {
		
		//To chech that output doesn't start with 0
		if(arr[i] == 0 && res.size() == 0) {
			continue;
		}
		res.push_back(arr[i]);
	}
	
	for(int i = 0; i< res.size(); i++) {
		cout << res[i] << " ";
	}
	
}

int main() {
	
	int arr[] = {9, 9, 9, 9};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	addOne(arr, n);
	
 	return 0;
}
