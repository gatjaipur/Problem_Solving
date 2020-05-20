#include<iostream>
using namespace std;

int partition(int arr[], int p, int r) {
	
	int pivot = arr[r];
	
	int i = p-1;
	
	for(int j = p; j< r; j++) {
		
		if(arr[j] <= pivot) {
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	
	int tempVar = arr[i+1];
	arr[i+1] = arr[r];
	arr[r] = tempVar;
	
	return i+1;
}


void quickSort(int arr[], int p, int r) {
	
	if(p < r) {
			int q = partition(arr, p, r);
			
			quickSort(arr, p, q-1);
			quickSort(arr, q+1, r);

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
	quickSort(arr, 0, n-1);
	printArray(arr, n);
	return 0;
}
