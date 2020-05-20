#include <bits/stdc++.h> 
using namespace std; 
//Method - 1 T.C. O(n^2)
/*
void findPairForSum(int arr[], int l, int r, int sum) {
	
	
	while(l<r) {
			if(arr[l] + arr[r] == sum) {
			cout << arr[l] << " + " << arr[r] << endl;
			l++; r--;
		} else if(arr[l] + arr[r] < sum) {
			l++;
		} else {
			r--;
		}
	}
}

// Driver program 
int main() 
{ 
	int arr[] = {1, 2, 1, 3, 4, 2, 3};
	int sum = 4; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	sort(arr, arr+n);
	
	findPairForSum(arr, 0, n-1, sum); 
	return 0; 
} 
*/

//Method 2 T.C. O(n)

void findPairForSum(int arr[], int n, int sum) {

bool temp[n];

memset(temp, false, sizeof(temp));

for(int i = 0; i<n; i++) {
	
	int diff = sum - arr[i];
	
	if(i>=0 && temp[diff]) {
		cout << diff << " + " << arr[i] << endl;
	}
	
	temp[arr[i]] = true;

}

}

// Driver program 
int main() 
{ 
	int arr[] = {1, 2, 1, 3, 4, 2, 3};
	int sum = 4; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	
	findPairForSum(arr, n, sum); 
	return 0; 
} 
