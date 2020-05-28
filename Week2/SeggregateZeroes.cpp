#include<iostream>

using namespace std;

	void Segg0(int arr[], int left, int right)
	{
		while(left < right)
		{
			while(left < right && arr[left] == 0)
			{
				left++;
			}
			
			while(left < right && arr[right] == 1)
			{
				right--;
			}
			
			if(left< right)
			{
				arr[left] = 0;
				arr[right] = 1;
				left++; right--;
			}
		}
	}
	
	void printArray(int arr[], int n)
	{
		for(int i = 0; i < n ; i++)
		{
			cout << arr[i] << endl;
		}
	}
	
	int main()
	{
		int arr[] = {0,1,1,1,0,0,0,1};
		int n = sizeof(arr)/sizeof(arr[0]);
				
		Segg0(arr, 0 , n-1);
		
		printArray(arr, n);
		
		return 0;
		
	}

