#include<iostream>
using namespace std;


int getSingle(int arr[], int n) {
	int res = 0;
	for (int i = 0; i < 32; i++) {
		int count = 0;
		for(int j = 0; j < n; j++) {
			if(arr[j] & (1 << i)) {
					count++;
			}
			
		}
		
		if(count%3) {
		  res |= (1<<i);
		}
	}
	
	return res;
}

int main() {
	
int arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 2, 2, 3, 7};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    cout << "The element with single occurrence is " << getSingle(arr, n);  
    return 0; 
}
