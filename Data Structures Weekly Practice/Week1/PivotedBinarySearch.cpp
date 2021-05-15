#include<iostream>

using namespace std;

	int findPivot(int arr[], int low, int high)
	{
		if(low > high) { return -1;}
		if(low == high) {return low;}

			int mid = (high + low)/2;
			
			if( mid < high && arr[mid] > arr[mid + 1])
			{
				return mid;
			}
			if( mid > low && arr[mid] < arr[mid - 1])
			{
				return mid-1;
			}
			if(arr[low] >= arr[mid])
			{
				return findPivot(arr, low, mid-1);
				
			}else
			{
				return findPivot(arr, mid+1, high);
			}
		
	}
	
	int BinarySearch(int arr[], int left, int right, int key)
    {
        while(right>= left)
        {
            int mid = (left + right)/2;
            if(arr[mid] == key)
            {
                return mid;
            }
            else if(arr[mid] > key)
            {
                right = mid-1;
            }
            else if(arr[mid]<key)
            {
                left = mid+1;
            }
        }
        // if(right>=left)
        // {
        //     int mid = (left + right)/2;
        //     if(arr[mid] == key)
        //     {
        //         return mid;
        //     }
        //     else if(arr[mid] > key)
        //     {
        //         return BS(arr, left, mid-1, key);
        //     }
        //     else if(arr[mid]<key)
        //     {
        //         return BS(arr, mid+1, right, key);
        //     }
            
        // }
         return -1;
    }
	
	int pivotedArray(int arr[], int n, int key)
	{
		int pivot = findPivot(arr,0, n-1);
		if(pivot == -1 )
		{
			return BinarySearch(arr,0,n-1,key);
		}
		if(arr[pivot] == key)
		{
			return pivot;
		}
		else if( arr[0] < key )
		{
			return BinarySearch(arr, 0 , pivot -1, key);
		}
		else
		{
			return BinarySearch(arr, pivot +1, n-1, key);
		}
	}
	
	
	
	
	int main()
	{
		int arr[] = {5 , 6 , 1 ,2 ,3, 4};
		int key = 1;
		
        int n = sizeof(arr)/sizeof(arr[0]);
				
		int res = pivotedArray(arr, n, key);
		
		if(res == -1)
		{ cout <<"Key not found in arr" << endl; }
		else
		{	cout<<"Key found in arr at " << res << endl ;
		}
		
		return 0;
		
	}


