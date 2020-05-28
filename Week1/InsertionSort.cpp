#include<iostream>

using namespace std;

void sort(int arr[], int n)
{
	
	for(int j = 1; j < n; ++j)
	{
		int key = arr[j];
		int i = j-1;
		
		while(i>=0 && arr[i]>key)
		{
			arr[i+1] = arr[i];
			i = i-1;
		}
		
		arr[i+1] = key;
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
	int arr[] = {2, 5, 1 , 6, 10, 3, 8, 4};
	int n = sizeof(arr)/sizeof(arr[0]);
	sort(arr,n);
	print(arr,n);
	return 0;
}
