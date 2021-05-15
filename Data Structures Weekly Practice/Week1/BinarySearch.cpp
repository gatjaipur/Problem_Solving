
/* 
* We can also use binary_search
#include <algorithm> 
std::vector<int> v;
std::sort (v.begin(), v.end()); //as binary_search always work on sorted list
  if (std::binary_search (v.begin(), v.end(), value))
	  //returns true if found else returns false
 

*/
#include <bits/stdc++.h> 

using namespace std;

    int BS(int arr[], int left, int right, int key)
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
    int main() {
        
        int arr[] = {2,4,6,2,4,2,2,4,6,33,4,21};
        int n = sizeof(arr)/sizeof(arr[0]);
        int key = 4;
        
        //if array is unsorted, BS will be beneficial to only sorted values
   	    sort(arr, arr+n); 
        int res;
        res = BS(arr,0,n-1,key);
        if(res == -1){ cout<< "Key not present" <<endl;}
        else 
        { 
            //if array has identical values then to return the first occurrence of the value
            while(arr[--res] == key);
            cout << "Key is present at " << (res +1) <<endl; 
            
        }
        
        return 0;
    }


