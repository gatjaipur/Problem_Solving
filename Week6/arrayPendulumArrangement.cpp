#include <bits/stdc++.h> 
/*
Input: arr[] = {2, 3, 5, 1, 4}
Output: 5 3 1 2 4
The minimum element is 1, so it is moved to the middle.
The next higher element 2 is moved to the right of the
middle element while the next higher element 3 is
moved to the left of the middle element and
this process is continued.

Input: arr[] = {11, 2, 4, 55, 6, 8}
Output: 11 6 2 4 8 55
*/

//Method 1 Using Aux Array 
/*
using namespace std;

void printArrayPendulum(int arr[], int n)
{
    int aux[n];
   sort(arr, arr+n);
   
   
   int mid = (n-1)/2;
   
   int j =1; int k =1;
   
   aux[mid] = arr[0];
   
   for(k = 1; k <=mid; k++)
   {
       aux[mid + k] = arr[j++];
       aux[mid - k] = arr[j++];
   }
   
   
   if(n%2 == 0)
   {
       aux[mid + k] = arr[j];
   }
   
   for(int i =0; i < n; i++)
   {
       cout << aux[i] << " ";
   }
}

int main() {
	//code
	int T;
	cin >> T;
	
	int n;
	while(T--)
	{
	    cin >> n;

	    int arr[n];
	    getchar();
	    for(int i =0; i < n; i++)
	    {
	        cin >> arr[i];
	    }
	    
	    printArrayPendulum(arr, n);
	    cout << "\n";
	    
	}
	
	return 0;
}
*/

//Method 2 Using Shifting of odd Indexes and Reverse

/*
For example, let arr[] = {2, 3, 5, 1, 4}
Sorted array will be arr[] = {1, 2, 3, 4, 5}.
After moving all odd index position elements to the right,
arr[] = {1, 3, 5, 2, 4} (1 and 3 are the odd index positions)
After reversing elements from 0 to (n – 1) / 2,
arr[] = {5, 3, 1, 2, 4} which is the required array.
*/

// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to print the Pendulum 
// arrangement of the given array 
void pendulumArrangement(int arr[], int n) 
{ 
	// Sort the array 
	sort(arr, arr + n); 

	int odd, temp, in, pos; 

	// pos stores the index of 
	// the last element of the array 
	pos = n - 1; 

	// odd stores the last odd index in the array 
	if (n % 2 == 0) 
		odd = n - 1; 
	else
		odd = n - 2; 

	// Move all odd index positioned 
	// elements to the right 
	while (odd > 0) { 
		temp = arr[odd]; 
		in = odd; 

		// Shift the elements by one position 
		// from odd to pos 
		while (in != pos) { 
			arr[in] = arr[in + 1]; 
			in++; 
		} 
		arr[in] = temp; 
		odd = odd - 2; 
		pos = pos - 1; 
	} 

	// Reverse the element from 0 to (n - 1) / 2 
	int start = 0, end = (n - 1) / 2; 

	for (; start < end; start++, end--) { 
		temp = arr[start]; 
		arr[start] = arr[end]; 
		arr[end] = temp; 
	} 

	// Printing the pendulum arrangement 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 11, 2, 4, 55, 6, 8 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	pendulumArrangement(arr, n); 

	return 0; 
} 

