	#include<iostream>
	using namespace std;
	
	void bubbleSort(int arr[], int n)
	{
		bool swapped = false; 
		
		for(int i = 0; i< n-1; i++)
		{
			swapped = false;
			for(int j = 0; j< n-i-1 ; j++)
			{
				if(arr[j]>arr[j+1])
				{
					swap(arr[j],arr[j+1]);
					swapped = true;
				}
			}
			
			if(!swapped)
			{
				break;		
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
		bubbleSort(arr, n);
		print(arr, n);
		return 0;
	}
