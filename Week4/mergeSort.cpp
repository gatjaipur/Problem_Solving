#include<iostream>
using namespace std;

void merge(int arr[], int p, int q, int r) {
	
	int n1 = q - p + 1;
	int n2 = r - q;
	
	int L[n1];
	int R[n2];
	
	for(int i = 0; i < n1; i++) {
		L[i] = arr[p +i];
	}
	
	
	for(int j = 0; j < n2; j++) {
		R[j] = arr[q+ 1 + j];
	}
		int i = 0;
		int j = 0;	
		int k = p;
	
	while(i < n1 && j < n2) {
		
		if(L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		
		k++;
	}
	
	
	while(i < n1) {
		arr[k++] = L[i++];
	}
	
		while(j < n2) {
		arr[k++] = R[j++];
	}
}



void mergeSort(int arr[], int p, int r) {
	if( p < r) {
		
			// Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int q = p+(r-p)/2;
	
	mergeSort(arr, p, q);
	mergeSort(arr, q + 1, r);
	merge(arr, p, q, r);
	}

		
}

void printArray(int arr[], int n) {
	for(int i =0; i< n; i++) {
		cout << arr[i] << " ";
		
	}	
}

int main() {
	
	int arr[] = {3, 2, 5, 1, 8, 3, 5, 2, 6, 2, 7};
	int n = sizeof(arr)/sizeof(arr[0]);
	mergeSort(arr, 0, n-1);
	printArray(arr, n);
	return 0;
}
