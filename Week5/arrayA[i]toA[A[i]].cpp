//Rearrange an array so that arr[i] becomes arr[arr[i]] with O(1) extra space
// If A[0] = 1 and A[1] = 2  then A[0] = 2

//METHOD 1 using mathematical logic
//T(n) = O(n)
//Space = O(1)

#include <iostream> 
using namespace std; 

// The function to rearrange an array in-place so that arr[i] 
// becomes arr[arr[i]]. 
void rearrange(int arr[], int n) 
{ 
	// First step: Increase all values by (arr[arr[i]]%n)*n 
	for (int i=0; i < n; i++) 
		arr[i] += (arr[arr[i]]%n)*n; 

//every element holds both old values and new values. 
//Old value can be obtained by arr[i]%n and new value can be obtained
//by arr[i]/n
	// Second Step: Divide all values by n 
	for (int i=0; i<n; i++) 
		arr[i] /= n; 
} 

// A utility function to print an array of size n 
void printArr(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 


/* Driver program to test above functions*/
int main() 
{ 
	int arr[] = {3, 2, 0, 1}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	cout << "Given array is \n"; 
	printArr(arr, n); 

	rearrange(arr, n); 

	cout << "Modified array is \n"; 
	printArr(arr, n); 
	return 0; 
} 

