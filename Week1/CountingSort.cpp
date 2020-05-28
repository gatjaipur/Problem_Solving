//T(n) = O(n+k) , n-> number of inputs, k-> range of inputs, elements are in range of 1 to k
//T(n) = O(n^2) if elements are in range of 1 to n^2
//Space = O(n+k)

#include<iostream>
#include<string.h>
using namespace std;

void countSort(char arr[], int n)
{
	
	char output[n];
	int count[256];
	memset(count, 0, sizeof(count)); 

	
	for(int i = 0; i< n; i++)
	{
		++count[arr[i]];
		}	
		
	for(int i = 1; i<=255; i++)
	{
		count[i]+=count[i-1];
	}
	
	for(int i = 0; i<n; i++)
	{
		output[count[arr[i]] - 1] = arr[i];
		--count[arr[i]];
	}
	
	for(int i =0 ; i<n; i++)
	{
		arr[i] = output[i];
	}
}

int main()
{
	char arr[]= {'c', 'a' , 'g', 'z', 'v', 'n'};
	int n = sizeof(arr)/sizeof(arr[0]);  // if char arr[] = "I am Gaurav" then n = strlen(arr)

	countSort(arr, n);
	
	for(int i =0; i< n; i++ )
	{
		cout << arr[i] << " ";
	}
	return 0;
}
