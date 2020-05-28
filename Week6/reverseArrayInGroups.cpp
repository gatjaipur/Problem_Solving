//Time complexity of above solution is O(n).
//Auxiliary space used by the program is O(1).

#include<iostream>
using namespace std;


void reverseInGroups(int arr[], int k, int n)
{
	for(int i =0; i < n; i+=k)
	{
		int left = i;
		
		int right= min(i+ k -1, n-1);
		
		while(left<right)
		{
			swap(arr[left++], arr[right--]);
		}
	}
}



/*

// Variant 2 Reverse Alternate Groups

void reverseInGroups(int arr[], int k, int n)
{
	for(int i =0; i < n; i+=2*k)
	{
		int left = i;
		
		int right= min(i+ k -1, n-1);
		
		while(left<right)
		{
			swap(arr[left++], arr[right--]);
		}
	}
}

*/



// Variant 3 Reverse at given distance

/*

void reverseInGroups(int arr[], int k, int n)
{
	int m = 2; //distance
	
	for(int i =0; i < n; i+= k + m)
	{
		int left = i;
		
		int right= min(i+ k -1, n-1);
		
		while(left<right)
		{
			swap(arr[left++], arr[right--]);
		}
	}
}

*/

/*
// Variant 4 Reverse by doubling the group size, if k =1 , then 
//Input: 
//arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
//k = 1
//Output:  
//[1], [3, 2], [7, 6, 5, 4], [15, 14, 13, 12, 11, 10, 9, 8]


void reverseInGroups(int arr[], int k, int n)
{
	k = 1; //to demostrate better in this example
	
	for(int i =0; i < n; i+= k/2)
	{
		int left = i;
		
		int right= min(i+ k -1, n-1);
		
		while(left<right)
		{
			swap(arr[left++], arr[right--]);
		}
		
		k*=2;
	}
}


int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 , 12, 13, 14};
	int k = 3;
	int n = sizeof(arr)/sizeof(arr[0]);
		
	reverseInGroups(arr, k, n);
	
for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
        
	return 0;
}


*/

/*


// Variant 5 Reverse by doubling the group size with double frequency, if k =1 , then 
//Input: 
//arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
//k = 1
//Output:  
//[1], [2], [4, 3], [6, 5], [10, 9, 8, 7], [14, 13, 12, 11] 


void reverseInGroups(int arr[], int k, int n)
{
	k = 1; //to demostrate better in this example
	
	for(int i =0; i < n; i+= k)
	{
		int left = i;
		
		int right= min(i+ k -1, n-1);
		
		while(left<right)
		{
			swap(arr[left++], arr[right--]);
		}
		
		k*=2;
	}
}

*/
int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 , 12, 13, 14};
	int k = 3;
	int n = sizeof(arr)/sizeof(arr[0]);
		
	reverseInGroups(arr, k, n);
	
for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
        
	return 0;
}


