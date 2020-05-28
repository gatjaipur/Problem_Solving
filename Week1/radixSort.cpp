/* T(n) = Let there be d digits in input integers. Radix Sort takes O(d*(n+b)) time where b is the base for representing numbers, 
for example, for decimal system, b is 10. What is the value of d? If k is the maximum possible value, then d would be O(logb(k)). 
So overall time complexity is O((n+b) * logb(k)). Which looks more than the time complexity of comparison based sorting algorithms
for a large k. Let us first limit k. Let k <= nc where c is a constant. In that case, the complexity becomes O(nLogb(n)).
But it still doesn’t beat comparison based sorting algorithms.
*/

#include<iostream>
#include<string.h>
using namespace std;

int getMax(int arr[], int n)
{
	int max = arr[0];
	
	for(int i = 1; i<n; i++)
	{
		if(arr[i] > max)
		{
			max = arr[i];
		}
		
	}
	return max;
}

void countSort(int arr[], int n, int exp)
{
	
	int output[n];
	int count[10] = {0};

	
	for(int i = 0; i< n; i++)
	{
		count[(arr[i]/exp)%10]++;
		}	
		
	for(int i = 1; i<10; i++)
	{
		count[i]+=count[i-1];
	}
	
	for(int i = n-1; i>=0; i--)
	{
		output[count[(arr[i]/exp)%10] - 1] = arr[i];
		count[(arr[i]/exp)%10]--;
	}
	
	for(int i =0 ; i<n; i++)
	{
		arr[i] = output[i];
	}
}
void radix(int arr[], int n)
{
  int m = getMax(arr,n);
  
  for(int exp = 1; m/exp > 0; exp*=10)
  {
  	countSort(arr,n,exp);
	  }	
}

int main()
{
	int arr[]= {2, 6, 7, 1, 3};
	int n = sizeof(arr)/sizeof(arr[0]);  // if char arr[] = "I am Gaurav" then n = strlen(arr)

	radix(arr, n);
	
	for(int i =0; i< n; i++ )
	{
		cout << arr[i] << " ";
	}
	return 0;
}
