// CPP program for rearrange an 
// array such that arr[i] = i. 
//Given an array of elements of length N, ranging from 0 to N – 1. All elements may not be present in the array.
//If element is not present then there will be -1 present in the array.
//Rearrange the array such that A[i] = i and if i is not present, display -1 at that place



//METHOD 1 using iteration logic
/*
#include <bits/stdc++.h> 

using namespace std; 

// Function to rearrange an array 
// such that arr[i] = i. 
int fix(int A[], int len) 
{ 
	for (int i = 0; i < len; i++) 
	{ 
		if (A[i] != -1 && A[i] != i) 
		{ 
			int x = A[i]; 

			// check if desired place 
			// is not vacate 
			while (A[x] != -1 && A[x] != x) 
			{ 
				// store the value from 
				// desired place 
				int y = A[x]; 

				// place the x to its correct 
				// position 
				A[x] = x; 

				// now y will become x, now 
				// search the place for x 
				x = y; 
			} 

			// place the x to its correct 
			// position 
			A[x] = x; 

			// check if while loop hasn't 
			// set the correct value at A[i] 
			if (A[i] != i) 
			{ 

				// if not then put -1 at 
				// the vacated place 
				A[i] = -1; 
			} 
		} 
	} 
} 

// Driver function. 
int main() 
{ 
	int A[] = { -1, -1, 6, 1, 9, 
				3, 2, -1, 4, -1 }; 

	int len = sizeof(A) / sizeof(A[0]); 
	fix(A, len); 

	for (int i = 0; i < len; i++) 
		cout << A[i] << " "; 
} 

*/


//METHOD 2 using set

// program for rearrange an 
// array such that arr[i] = i. 

/*
#include<stdio.h>
#include<set>

	// Function to rearrange an array 
	// such that arr[i] = i. 
	 int[] fix(int[] A) 
	{ 
		set<int> s;

		// Storing all the values in the HashSet 
		for(int i = 0; i < A.length; i++) 
		{ 
		s.add(A[i]); 
		} 

		for(int i = 0; i < A.length; i++) 
		{ 
		if(s.contains(i)) 
			A[i] = i; 
		else
			A[i] = -1; 
		} 

	return A; 
} 

	// Driver function. 
	int main() 
	{ 
		int A[] = {-1, -1, 6, 1, 9, 
					3, 2, -1, 4,-1}; 
		int n = sizeof(arr)/sizeof(arr[0]);		
				fix(A);	
		// Function calling
		for(int i =0; i<n; i++) 
		{
		
		cout << A[i] << " "; 
	}
		return 0;
	} 
} 

*/


//METHOD 3 using math logic swap arr[i] and arr[arr[i]]


// C++ program for rearrange an 
// array such that arr[i] = i. 
#include <bits/stdc++.h> 

using namespace std; 

void fix(int arr[], int len)
{
	 for(int i = 0; i < len;) 
            { 
                if(arr[i] >= 0 && arr[i] != i) 
                { 
                    int ele = arr[arr[i]]; 
                    arr[arr[i]] = arr[i]; 
                    arr[i] = ele; 
                } else { 
                    i++; 
                } 
            } 
}

int main() 
{ 
	int A[] = { -1, -1, 6, 1, 9, 
				3, 2, -1, 4, -1 }; 

	int len = sizeof(A) / sizeof(A[0]); 
	fix(A, len); 

	for (int i = 0; i < len; i++) 
		cout << A[i] << " "; 
} 

