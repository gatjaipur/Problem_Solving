// C++ code to Segregate 0s and 1s in an array
#include <bits/stdc++.h>
using namespace std;

// Function to segregate 0s and 1s
void segregate0and1(int arr[], int n)
{
	int count = 0; // Counts the no of zeros in arr

	for (int i = 0; i < n; i++) {
		if (arr[i] == 0)
			count++;
	}

	// Loop fills the arr with 0 until count
	for (int i = 0; i < count; i++)
		arr[i] = 0;

	// Loop fills remaining arr space with 1
	for (int i = count; i < n; i++)
		arr[i] = 1;
}

// Function to print segregated array
void print(int arr[], int n)
{
	cout << "Array after segregation is ";

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

// Driver function
int main()
{
	int arr[] = { 0, 1, 0, 1, 1, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	
	segregate0and1(arr, n);
	print(arr, n);
	
	return 0;
}

// Method 2 (Use two indexes to traverse) 
// Time Complexity: O(n)

// C++ program to sort a binary array in one pass
#include <bits/stdc++.h>
using namespace std;

/*Function to put all 0s on left and all 1s on right*/
void segregate0and1(int arr[], int size)
{
	/* Initialize left and right indexes */
	int left = 0, right = size-1;

	while (left < right)
	{
		/* Increment left index while we see 0 at left */
		while (arr[left] == 0 && left < right)
			left++;

		/* Decrement right index while we see 1 at right */
		while (arr[right] == 1 && left < right)
			right--;

		/* If left is smaller than right then there is a 1 at left
		and a 0 at right. Exchange arr[left] and arr[right]*/
		if (left < right)
		{
			arr[left] = 0;
			arr[right] = 1;
			left++;
			right--;
		}
	}
}

/* Driver code */
int main()
{
	int arr[] = {0, 1, 0, 1, 1, 1};
	int i, arr_size = sizeof(arr)/sizeof(arr[0]);

	segregate0and1(arr, arr_size);

	cout << "Array after segregation ";
	for (i = 0; i < 6; i++)
		cout << arr[i] << " ";
	return 0;
}

