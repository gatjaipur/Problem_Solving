/*
METHOD 1 (Using temp array)

Input arr[] = [1, 2, 3, 4, 5, 6, 7], d = 2, n =7
1) Store d elements in a temp array
   temp[] = [1, 2]
2) Shift rest of the arr[]
   arr[] = [3, 4, 5, 6, 7, 6, 7]
3) Store back the d elements
   arr[] = [3, 4, 5, 6, 7, 1, 2]

Time complexity : O(n)
Auxiliary Space : O(d)

*/

//METHOD 2 (Rotate one by one)
//Time complexity : O(n * d)
//Auxiliary Space : O(1)


// C++ program to rotate an array by 
// d elements 
/*
#include <bits/stdc++.h> 
using namespace std; 


void leftRotatebyOne(int arr[], int n) 
{ 
	int temp = arr[0], i; 
	for (i = 0; i < n - 1; i++) 
		arr[i] = arr[i + 1]; 

	arr[i] = temp; 
} 

void leftRotate(int arr[], int d, int n) 
{ 
	for (int i = 0; i < d; i++) 
		leftRotatebyOne(arr, n); 
} 

void printArray(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
} 

int main() 
{ 
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	// Function calling 
	leftRotate(arr, 2, n); 
	printArray(arr, n); 

	return 0; 
} 

*/

//METHOD 3 (A Juggling Algorithm)
//Time complexity : O(n)
//Auxiliary Space : O(1)

// C++ program to rotate an array by 
// d elements 
/*
#include <bits/stdc++.h> 
using namespace std; 

int gcd(int a, int b) 
{ 
	if (b == 0) 
		return a; 

	else
		return gcd(b, a % b); 
} 

void leftRotate(int arr[], int d, int n) 
{ 
	for (int i = 0; i < gcd(d, n); i++) { 

		int temp = arr[i]; 
		int j = i; 

		while (1) { 
			int k = j + d; 
			if (k >= n) 
				k = k - n; 

			if (k == i) 
				break; 

			arr[j] = arr[k]; 
			j = k; 
		} 
		arr[j] = temp; 
	} 
} 

void printArray(int arr[], int size) 
{ 
	for (int i = 0; i < size; i++) 
		cout << arr[i] << " "; 
} 

int main() 
{ 
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	// Function calling 
	leftRotate(arr, 2, n); 
	printArray(arr, n); 

	return 0; 
} 

*/

//Method 4 Reverse algorithm
//T(n) = O(n)

// C++ program for reversal algorithm 
// of array rotation 
#include <bits/stdc++.h> 
using namespace std; 

/*Function to reverse arr[] from index start to end*/
void reverseArray(int arr[], int start, int end) 
{ 
	while (start < end) 
	{ 
		int temp = arr[start]; 
		arr[start] = arr[end]; 
		arr[end] = temp; 
		start++; 
		end--; 
	} 
} 

/* Function to left rotate arr[] of size n by d */
void leftRotate(int arr[], int d, int n) 
{ 
	reverseArray(arr, 0, d-1); 
	reverseArray(arr, d, n-1); 
	reverseArray(arr, 0, n-1); 
} 

void rightRotate(int arr[], int d, int n) 
{ 
    reverseArray(arr, 0, n-1); 
    reverseArray(arr, 0, d-1); 
    reverseArray(arr, d, n-1); 
}

// Function to print an array 
void printArray(int arr[], int size) 
{ 
	for (int i = 0; i < size; i++) 
	cout << arr[i] << " "; 
} 

/* Driver program to test above functions */
int main() 
{ 
	int arr[] = {1, 2, 3, 4, 5, 6, 7}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	int d = 2; 
	
	// Function calling 
	leftRotate(arr, d, n); 
	printArray(arr, n); 
	
	return 0; 
} 

/*
// Method -5 Using Mod Operator

void rotateArray(int arr[], int n, int d) {
	
	vector<int> res;
	
	for(int i = 0; i<n; i++) {
		res.push_back(arr[(i + d)%n]);
	}
	
	for(int i = 0; i<n; i++) {
		cout << res[i] << " ";
	}
}


int main() {
	
	int d = 2;
	int arr[] = {2, 5, 8, 4, 1, 9, 3, 3, 7};
	int n = sizeof(arr)/sizeof(arr[0]);
	rotateArray(arr, n, d);
	return 0;
}

*/
