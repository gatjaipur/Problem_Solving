// C++ Program to perform 3 way Merge Sort 
#include <bits/stdc++.h> 
using namespace std; 
/*
Time Complexity: In case of 2-way Merge sort we get the equation: T(n) = 2T(n/2) + O(n)
Similarly, in case of 3-way Merge sort we get the equation: T(n) = 3T(n/3) + O(n)
By solving it using Master method, we get its complexity as O(n log 3n)..
*/

/* Merge the sorted ranges [low, mid1), [mid1,mid2) 
and [mid2, high) mid1 is first midpoint 
index in overall range to merge mid2 is second 
midpoint index in overall range to merge*/
void merge(int data[], int low, int mid1, 
		int mid2, int high, int fArray[]) 
{ 
	int i = low, j = mid1, k = mid2, l = low; 

	// choose smaller of the smallest in the three ranges 
	while ((i < mid1) && (j < mid2) && (k < high)) 
	{ 
		if(data[i] < data[j]) 
		{ 
			if(data[i] < data[k]) 
			{ 
				fArray[l++] = data[i++]; 
			} 
			else
			{ 
				fArray[l++] = data[k++]; 
			} 
		} 
		else
		{ 
			if(data[j] < data[k]) 
			{ 
				fArray[l++] = data[j++]; 
			} 
			else
			{ 
				fArray[l++] = data[k++]; 
			} 
		} 
	} 

	// case where first and second ranges 
	// have remaining values 
	while ((i < mid1) && (j < mid2)) 
	{ 
		if(data[i] < data[j]) 
		{ 
			fArray[l++] = data[i++]; 
		} 
		else
		{ 
			fArray[l++] = data[j++]; 
		} 
	} 

	// case where second and third ranges 
	// have remaining values 
	while ((j < mid2) && (k < high)) 
	{ 
		if(data[j] < data[k]) 
		{ 
			fArray[l++] = data[j++]; 
		} 
		else
		{ 
			fArray[l++] = data[k++]; 
		} 
	} 

	// case where first and third ranges have 
	// remaining values 
	while ((i < mid1) && (k < high)) 
	{ 
		if(data[i] < data[k]) 
		{ 
			fArray[l++] = data[i++]; 
		} 
		else
		{ 
			fArray[l++] = data[k++]; 
		} 
	} 

	// copy remaining values from the first range 
	while (i < mid1) 
		fArray[l++] = data[i++]; 

	// copy remaining values from the second range 
	while (j < mid2) 
		fArray[l++] = data[j++]; 

	// copy remaining values from the third range 
	while (k < high) 
		fArray[l++] = data[k++]; 
} 


/* Performing the merge sort algorithm on the 
given array of values in the rangeof indices 
[low, high). low is minimum index, high is 
maximum index (exclusive) */
void mergeSort3WayRec(int fArray[], int low, 
					int high, int data[]) 
{ 
	// If array size is 1 then do nothing 
	if (high - low < 2) 
		return; 

	// Splitting array into 3 parts 
	int mid1 = low + ((high - low) / 3); 
	int mid2 = low + 2 * ((high - low) / 3) + 1; 

	// Sorting 3 arrays recursively 
	mergeSort3WayRec(data, low, mid1, fArray); 
	mergeSort3WayRec(data, mid1, mid2, fArray); 
	mergeSort3WayRec(data, mid2, high, fArray); 

	// Merging the sorted arrays 
	merge(data, low, mid1, mid2, high, fArray); 
} 

void mergeSort3Way(int data[], int n) 
{ 
	// if array size is zero return null 
	if (n == 0) 
		return; 

	// creating duplicate of given array 
	int fArray[n]; 

	// copying elements of given array into 
	// duplicate array 
	for (int i = 0; i < n; i++) 
		fArray[i] = data[i]; 

	// sort function 
	mergeSort3WayRec(fArray, 0, n, data); 

	// copy back elements of duplicate array 
	// to given array 
	for (int i = 0; i < n; i++) 
		data[i] = fArray[i]; 
} 

// Driver Code 
int main() 
{ 
	int data[] = {45, -2, -45, 78, 30, 
				-42, 10, 19, 73, 93}; 
	mergeSort3Way(data,10); 
	cout << "After 3 way merge sort: "; 
	for (int i = 0; i < 10; i++) 
	{ 
		cout << data[i] << " "; 
	} 
	return 0; 
} 

// This code is contributed by Rashmi Kumari 

