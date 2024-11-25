//Method-1
/*
// C++ program to rotate an array by
// d elements

// Time complexity : O(n * d) 
// Auxiliary Space : O(1)

#include <bits/stdc++.h>
using namespace std;

// Function to left Rotate arr[] of
// size n by 1
void leftRotatebyOne(int arr[], int n)
{
	int temp = arr[0], i;
	for (i = 0; i < n - 1; i++)
		arr[i] = arr[i + 1];

	arr[n-1] = temp;
}

// Function to left rotate arr[] of size n by d
void leftRotate(int arr[], int d, int n)
{
	for (int i = 0; i < d; i++)
		leftRotatebyOne(arr, n);
}

//utility function to print an array 
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

//Driver program to test above functions 
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

//Method -2  (Using temp array to store the d elements)
// Time complexity : O(n) 
// Auxiliary Space : O(d)


//Method -3 Juggling Algorithm
// Time complexity : O(n) 
// Auxiliary Space : O(1)
 
// C++ program to rotate an array by
// d elements
#include <bits/stdc++.h>
using namespace std;

/*Fuction to get gcd of a and b*/
int gcd(int a, int b)
{
	if (b == 0)
		return a;

	else
		return gcd(b, a % b);
}

/*Function to left rotate arr[] of siz n by d*/
void leftRotate(int arr[], int d, int n)
{
	/* To handle if d >= n */
	d = d % n;
	int g_c_d = gcd(d, n);
	for (int i = 0; i < g_c_d; i++) {
		/* move i-th values of blocks */
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

// Function to print an array
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

/* Driver program to test above functions */
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function calling
	leftRotate(arr, 2, n);
	printArray(arr, n);

	return 0;
}


//Method 4 Reversal Algorithm
// Time Complexity : O(n)

// C++ program for reversal algorithm
// of array rotation
// #include <bits/stdc++.h>
// using namespace std;

// /*Function to reverse arr[] from index start to end*/
// void reverseArray(int arr[], int start, int end)
// {
// 	while (start < end) {
// 		int temp = arr[start];
// 		arr[start] = arr[end];
// 		arr[end] = temp;
// 		start++;
// 		end--;
// 	}
// }

// /* Function to left rotate arr[] of size n by d */
// void leftRotate(int arr[], int d, int n)
// {
// 	if (d == 0)
// 		return;
// 	// in case the rotating factor is
// 	// greater than array length
// 	d = d % n;

// 	reverseArray(arr, 0, d - 1);
// 	reverseArray(arr, d, n - 1);
// 	reverseArray(arr, 0, n - 1);
// }

// /* Function to right rotate arr[] of size n by d */
// void rightRotate(int arr[], int d, int n)
// {
// 	if (d == 0)
// 		return;
// 	// in case the rotating factor is
// 	// greater than array length
// 	d = d % n;

// 	reverseArray(arr, 0, n - 1);
// 	reverseArray(arr, 0, d - 1);
// 	reverseArray(arr, d, n - 1);
// }

// // Function to print an array
// void printArray(int arr[], int size)
// {
// 	for (int i = 0; i < size; i++)
// 		cout << arr[i] << " ";
// }

// /* Driver program to test above functions */
// int main()
// {
// 	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
// 	int n = sizeof(arr) / sizeof(arr[0]);
// 	int d = 2;

// 	// Function calling
// 	leftRotate(arr, d, n);
// 	printArray(arr, n);

// 	return 0;
// }


