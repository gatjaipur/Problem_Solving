// Duplicate not handled (1, 2) is not same as (2, 1)
// C++ program to print all combination 
// of size r in an array of size n 

//Method -1
#include<bits/stdc++.h> 
using namespace std; 

void combinationUtil(int arr[], int data[], 
					int start, int end, 
					int index, int r); 

// The main function that prints 
// all combinations of size r 
// in arr[] of size n. This function 
// mainly uses combinationUtil() 
void printCombination(int arr[], int n, int r) 
{ 
	// A temporary array to store 
	// all combination one by one 
	int data[r]; 

	// Print all combination using 
	// temprary array 'data[]' 
	combinationUtil(arr, data, 0, n-1, 0, r); 
} 

// arr[] ---> Input Array 
//data[] ---> Temporary array to 
//store current combination 
//start & end ---> Staring and 
//Ending indexes in arr[] 
//index ---> Current index in data[] 
//r ---> Size of a combination to be printed 
void combinationUtil(int arr[], int data[], 
					int start, int end, 
					int index, int r) 
{ 
	// Current combination is ready 
	// to be printed, print it 
	if (index == r) 
	{ 
		for (int j = 0; j < r; j++) 
			cout << data[j] << " "; 
		cout << endl; 
		return; 
	} 

	// replace index with all possible 
	// elements. The condition "end-i+1 >= r-index" 
	// makes sure that including one element 
	// at index will make a combination with 
	// remaining elements at remaining positions 
	for (int i = start; i <= end && 
		end - i + 1 >= r - index; i++) 
	{ 
		data[index] = arr[i]; 
		combinationUtil(arr, data, i+1, 
						end, index+1, r); 
	} 
} 

// Driver code 
int main() 
{ 
	int arr[] = {1, 2, 3, 4, 5}; 
	int r = 3; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printCombination(arr, n, r); 
} 


//Method - 2
/*
// C++ Program to print all combination of 
// size r in an array of size n 
#include <bits/stdc++.h> 
using namespace std; 
void combinationUtil(int arr[], int n, int r, 
					int index, int data[], int i); 

// The main function that prints all 
// combinations of size r in arr[] 
// of size n. This function mainly 
// uses combinationUtil() 
void printCombination(int arr[], int n, int r) 
{ 
	// A temporary array to store 
	// all combination one by one 
	int data[r]; 

	// Print all combination using 
	// temprary array 'data[]' 
	combinationUtil(arr, n, r, 0, data, 0); 
} 

// arr[] ---> Input Array 
//n ---> Size of input array 
//r ---> Size of a combination to be printed 
//index ---> Current index in data[] 
//data[] ---> Temporary array to store current combination 
//i ---> index of current element in arr[] 
void combinationUtil(int arr[], int n, int r, 
					int index, int data[], int i) 
{ 
	// Current cobination is ready, print it 
	if (index == r) 
	{ 
		for (int j = 0; j < r; j++) 
			cout << data[j] << " "; 
		cout << endl; 
		return; 
	} 

	// When no more elements are there to put in data[] 
	if (i >= n) 
		return; 

	// current is included, put next at next location 
	data[index] = arr[i]; 
	combinationUtil(arr, n, r, index + 1, data, i + 1); 

	// current is excluded, replace it with next (Note that 
	// i+1 is passed, but index is not changed) 
	combinationUtil(arr, n, r, index, data, i+1); 
} 

// Driver code 
int main() 
{ 
	int arr[] = {1, 2, 3, 4, 5}; 
	int r = 3; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printCombination(arr, n, r); 
	return 0; 
} 
*/

/*

// Duplicate handled (1, 2) is same as (2, 1)

// C++ program to print all combination 
// of size r in an array of size n 
#include<bits/stdc++.h> 
using namespace std; 

void combinationUtil(int arr[], int data[], 
					int start, int end, 
					int index, int r); 

// The main function that prints 
// all combinations of size r 
// in arr[] of size n. This function 
// mainly uses combinationUtil() 

int compare (const void * a, const void * b)
{  return ( *(int*)a - *(int*)b );  }

void printCombination(int arr[], int n, int r) 
{ 
	// A temporary array to store 
	// all combination one by one 
	int data[r]; 
	
    // Sort array to handle duplicates
    qsort (arr, n, sizeof(int), compare);
    
	// Print all combination using 
	// temprary array 'data[]' 
	combinationUtil(arr, data, 0, n-1, 0, r); 
} 

// arr[] ---> Input Array 
//data[] ---> Temporary array to 
//store current combination 
//start & end ---> Staring and 
//Ending indexes in arr[] 
//index ---> Current index in data[] 
//r ---> Size of a combination to be printed 
void combinationUtil(int arr[], int data[], 
					int start, int end, 
					int index, int r) 
{ 
	// Current combination is ready 
	// to be printed, print it 
	if (index == r) 
	{ 
		for (int j = 0; j < r; j++) 
			cout << data[j] << " "; 
		cout << endl; 
		return; 
	} 

	// replace index with all possible 
	// elements. The condition "end-i+1 >= r-index" 
	// makes sure that including one element 
	// at index will make a combination with 
	// remaining elements at remaining positions 
	for (int i = start; i <= end && 
		end - i + 1 >= r - index; i++) 
	{ 
		data[index] = arr[i]; 
		combinationUtil(arr, data, i+1, 
						end, index+1, r); 
						
						// Since the elements are sorted, all occurrences of an element
        // must be together
        while (arr[i] == arr[i+1])
             i++;
	} 
} 

// Driver code 
int main() 
{ 
	int arr[] = {1, 2, 1}; 
	int r = 2; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printCombination(arr, n, r); 
} 

*/

/*
//Method - 2

// C++ Program to print all combination of 
// size r in an array of size n 
#include <bits/stdc++.h> 
using namespace std; 


int compare (const void * a, const void * b)
{  return ( *(int*)a - *(int*)b );  }


void combinationUtil(int arr[], int n, int r, 
					int index, int data[], int i); 

// The main function that prints all 
// combinations of size r in arr[] 
// of size n. This function mainly 
// uses combinationUtil() 
void printCombination(int arr[], int n, int r) 
{ 
	// A temporary array to store 
	// all combination one by one 
	int data[r]; 
	
	
    // Sort array to handle duplicates
    qsort (arr, n, sizeof(int), compare);

	// Print all combination using 
	// temprary array 'data[]' 
	combinationUtil(arr, n, r, 0, data, 0); 
} 

//arr[] ---> Input Array 
//n ---> Size of input array 
//r ---> Size of a combination to be printed 
//index ---> Current index in data[] 
//data[] ---> Temporary array to store current combination 
//i ---> index of current element in arr[] 
void combinationUtil(int arr[], int n, int r, 
					int index, int data[], int i) 
{ 
	// Current cobination is ready, print it 
	if (index == r) 
	{ 
		for (int j = 0; j < r; j++) 
			cout << data[j] << " "; 
		cout << endl; 
		return; 
	} 

	// When no more elements are there to put in data[] 
	if (i >= n) 
		return; 

	// current is included, put next at next location 
	data[index] = arr[i]; 
	combinationUtil(arr, n, r, index + 1, data, i + 1); 
	
							// Since the elements are sorted, all occurrences of an element
        // must be together
        while (arr[i] == arr[i+1])
             i++;

	// current is excluded, replace it with next (Note that 
	// i+1 is passed, but index is not changed) 
	combinationUtil(arr, n, r, index, data, i+1); 
} 

// Driver code 
int main() 
{ 
	int arr[] = {1, 2, 1}; 
	int r = 2; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printCombination(arr, n, r); 
	return 0; 
} 

*/
