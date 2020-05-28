#include<iostream>
using namespace std;
	
void selectionSort(int arr[], int n)
{
	
	for(int i = 0; i< n-1; i++)
	{
		int min = i;
		
		for(int j = i+1; j < n; j++)
		{
			if(arr[j] < arr[min])
			{
				min =j;
			}
			
			if(min != i)
			{
				swap(arr[min], arr[i]);
			}
		}
	}
}
	
	
void print(int arr[], int n)
{
	for(int i = 0; i< n; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	int arr[] = {2,5,1,8,3,4,9,0};
	int n = sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr, n);
	print(arr, n);
	return 0;
}
