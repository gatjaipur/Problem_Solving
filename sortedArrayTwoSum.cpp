// Method 1 Sorting and Two Pointer
// Complexity Analysis:  

// Time Complexity: Depends on what sorting algorithm we use. 
// If Merge Sort or Heap Sort is used then (-)(nlogn) in the worst case.
// If Quick Sort is used then O(n^2) in the worst case.

// Auxiliary Space: This too depends on sorting algorithm. The auxiliary space is O(n) for merge sort and O(1) for Heap Sort.

// C++ program to check if given array
// has 2 elements whose sum is equal
// to the given value

// #include <bits/stdc++.h>
// using namespace std;

// // Function to check if array has 2 elements
// // whose sum is equal to the given value
// bool hasArrayTwoCandidates(int A[], int arr_size,
// 						int sum)
// {
// 	int l, r;

// 	/* Sort the elements */
// 	sort(A, A + arr_size);

// 	/* Now look for the two candidates in
// 	the sorted array*/
// 	l = 0;
// 	r = arr_size - 1;
// 	while (l < r) {
// 		if (A[l] + A[r] == sum)
// 			return 1;
// 		else if (A[l] + A[r] < sum)
// 			l++;
// 		else // A[i] + A[j] > sum
// 			r--;
// 	}
// 	return 0;
// }

// /* Driver program to test above function */
// int main()
// {
// 	int A[] = { 1, 4, 45, 6, 10, -8 };
// 	int n = 16;
// 	int arr_size = sizeof(A) / sizeof(A[0]);

// 	// Function calling
// 	if (hasArrayTwoCandidates(A, arr_size, n))
// 		cout << "Array has two elements"
// 				" with given sum";
// 	else
// 		cout << "Array doesn't have two"
// 				" elements with given sum";

// 	return 0;
// }

//Method 2 Hashing 

// Time Complexity: O(n). 
// As the whole array is needed to be traversed only once.
// Auxiliary Space: O(n). 
// A hash map has been used to store array elements.
// Note: If the range of numbers includes negative numbers then also it will work fine.


// C++ program to check if given array
// has 2 elements whose sum is equal
// to the given value
#include <bits/stdc++.h>

using namespace std;

void printPairs(int arr[], int arr_size, int sum)
{
	unordered_set<int> s;
	for (int i = 0; i < arr_size; i++)
	{
		int temp = sum - arr[i];

		if (s.find(temp) != s.end())
			cout << "Pair with given sum "
				<< sum << " is (" << arr[i] << ","
					<< temp << ")" << endl;

		s.insert(arr[i]);
	}
}

/* Driver Code */
int main()
{
	int A[] = { 1, 4, 45, 6, 10, 8 };
	int n = 16;
	int arr_size = sizeof(A) / sizeof(A[0]);

	// Function calling
	printPairs(A, arr_size, n);

	return 0;
}


// Method 3: Using remainders of the elements less than x. 

// Time Complexity: O(n+x)
// Auxiliary Space: O(x)

// 1. Create an array with size x. 

// 2. Initialize all rem elements to zero.

// 3. Traverse the given array

// Do the following if arr[i] is less than x:
// r=arr[i]%x which is done to get the remainder.
// rem[r]=rem[r]+1 i.e. increasing the count of elements that have remainder r when divided with x.
// 4. Now, traverse the rem array from 1 to x/2.   

// If(rem[i]> 0 and rem[x-i]>0) then print “YES” and come out of the loop. This means that we have a pair that results in x upon doing.
// 5. Now when we reach at x/2 in the above loop   

// If x is even, for getting a pair we should have two elements with remainder x/2.
// If rem[x/2]>1 then print “YES” else print “NO”
// If it is not satisfied that is x is odd, it will have a separate pair with x-x/2.
// If rem[x/2]>1 and rem[x-x/2]>1 , then print “Yes” else, print”No”;

// Code in cpp to tell if there
// exists a pair in array whose
// sum results in x.
#include <iostream>
using namespace std;

// Funtion to print pairs
void printPairs(int a[], int n, int x)
{
	int i;
	int rem[x];
	for (i = 0; i < x; i++)
	{
	
		// initializing the rem
		// values with 0's.
		rem[i] = 0;
	}
	for (i = 0; i < n; i++)
	{
		if (a[i] < x)
		{

			// Perform the remainder
			// operation only if the
			// element is x, as numbers
			// greater than x can't
			// be used to get a sum x.
			// Updating the count of remainders.
			rem[a[i] % x]++;
		}
	}

	// Traversing the remainder list
	// from start to middle to
	// find pairs
	for (i = 1; i < x / 2; i++)
	{
		if (rem[i] > 0 && rem[x - i] > 0)
		{
		
			// The elements with remainders
			// i and x-i will
			// result to a sum of x.
			// Once we get two
			// elements which add up to x ,
			// we print x and
			// break.
			cout << "Yes"
				<< "\n";
			break;
		}
	}

	// Once we reach middle of
	// remainder array, we have to
	// do operations based on x.
	if (i >= x / 2)
	{
		if (x % 2 == 0)
		{
			if (rem[x / 2] > 1)
			{
			
				// if x is even and
				// we have more than 1
				// elements with remainder
				// x/2, then we will
				// have two distinct elements
				// which add up
				// to x. if we dont have
				//more than 1
				// element, print "No".
				cout << "Yes"
					<< "\n";
			}
			else
			{
				cout << "No"
					<< "\n";
			}
		}
		else
		{
		
			// When x is odd we continue
			// the same process
			// which we did in previous loop.
			if (rem[x / 2] > 0 &&
				rem[x - x / 2] > 0)
			{
				cout << "Yes"
					<< "\n";
			}
			else
			{
				cout << "No"
					<< "\n";
			}
		}
	}
}

/* Driver Code */
int main()
{
	int A[] = { 1, 4, 45, 6, 10, 8 };
	int n = 16;
	int arr_size = sizeof(A) / sizeof(A[0]);

	// Function calling
	printPairs(A, arr_size, n);

	return 0;
}
