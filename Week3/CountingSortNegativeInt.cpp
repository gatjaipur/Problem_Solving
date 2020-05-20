/*The counting sort algorithm is designed to sort integer values that are in a fixed range,
 so it can't be applied to sort strings. On the other hand, you could use radix sort for this problem.
  Radix sort works by sorting the input one digit or character at a time, and it's very well-suited for sorting strings.
*/

//METHOD 1 Using multiiple arrays for count of positive and negative values
//T(n)= O(n)

#include <iostream>
using namespace std;

int getMax(int arr[], int n)
{
    int max = arr[0];
    
    for(int i = 1; i< n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    
    return max;
}
int getMin(int arr[], int n)
{
    int min = arr[0];
    
    for(int i = 1; i< n; i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }
    
    return min;
}

void countingSort(int arr[], int n)
{
    int max = getMax(arr,n);
    int min = getMin(arr, n);
    
    int countPlusSize = max+1;
    int countMinusSize = (min*(-1)) +1;
    int countPlus[countPlusSize] = {0};
    int countMinus[countMinusSize] = {0};

    int output[n] ={0};

    for(int i =0 ; i< n; i++)
    {
        if(arr[i] >= 0)
        {
            ++countPlus[arr[i]];
        }
        else
        {
            ++countMinus[(arr[i]*(-1))];
        }
    }
    
    
    for(int i = countMinusSize-2; i >= 0; i--)
    {
        countMinus[i]+=countMinus[i+1];
    }
    
    for(int i = 1; i <= countPlusSize-1; i++)
    {
        countPlus[i]+=countPlus[i-1];
    }
    
    for(int i = 0; i< countPlusSize; i++)
    {
        countPlus[i]+= countMinus[0];
    }
    
    //reverse to make it stable sort i.e. the relative order of items with equal keys is preserved
     for(int i = n-1; i >= 0 ; i--)
    {
        if(arr[i]>=0)
        {
        output[countPlus[arr[i]] - 1] = arr[i];
        --countPlus[arr[i]];
        }
        else
        {
          output[countMinus[((arr[i])*(-1))] - 1] = arr[i];
        --countMinus[((arr[i])*(-1))]; 
        }
    }
    
     for(int i=0; i<n; i++)
    {
        arr[i] = output[i];
        std::cout << arr[i] << " " ;
    }

}




int main() {
	// your code goes here
	
	int arr[] = {-4, -1, 4, 8, 3, 2, 9};
	int n = sizeof(arr)/sizeof(arr[0]);

	countingSort(arr, n);
	
	return 0;
}



/*

//METHOD 2 Using map and Vectors

#include <iostream>
#include <vector>
#include <map>

void countSort(std::vector<int> &v)
{
	// create an empty map to store frequency of array elements
	std::map<int, int> freq;

	// store distinct values in the input array as key and 
	// their respective counts as values
	for (int i = 0; i < v.size(); i++) {
		freq[v.at(i)]++;
	}

	// traverse the map and overwrite the input array with sorted elements
	// (map will iterate based on the sorted order of keys)
	int i = 0;
	for (auto it: freq) {
		while (it.second--) {
			v[i++] = it.first;
		}
	}
}

// C++ program for count sort algorithm
int main()
{
	std::vector<int> v = { -4, -2, 1, 4, -1, 4, 2, 1, 10 };

	countSort(v);

	for (int &x: v) {
		std::cout << x << " ";
	}

	return 0;
}
*/
