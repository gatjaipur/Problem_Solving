//Maximum adjacent difference in an array in its sorted form
//METHOD 1 USING SORTING
//T(n) = O(nlogn)
//Space = O(1)


#include <bits/stdc++.h> 
#include<algorithm>

using namespace std; 
  
int maxSortedAdjacentDiff(int* arr, int n) 
{
	
	if(n<2)
	{
		return 0;
	}
		sort(arr,arr+n);
int res = arr[1]-arr[0];

for(int i = 2; i<n; i++)
{
	if(arr[i] - arr[i-1] > res)
	{
	res = arr[i] - arr[i-1];	
		}	
}
return res;
}
int main() 
{ 
    int arr[] = { 1, 10, 5 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << maxSortedAdjacentDiff(arr, n) << endl; 
    return 0; 
} 




