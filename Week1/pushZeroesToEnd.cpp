//METHOD 1 Iterating till n and ignoring zeroes to add them at last
//T(n) = O(n)
//Space = O(1)

/*
	
	// A C++ program to move all zeroes at the end of array 
#include <iostream> 
using namespace std; 
  
// Function which pushes all zeros to end of an array. 
void pushZerosToEnd(int arr[], int n) 
{ 
    int count = 0;  // Count of non-zero elements 
  
    // Traverse the array. If element encountered is non- 
    // zero, then replace the element at index 'count'  
    // with this element 
    for (int i = 0; i < n; i++) 
        if (arr[i] != 0) 
            arr[count++] = arr[i]; // here count is  
                                   // incremented 
  
    // Now all non-zero elements have been shifted to  
    // front and  'count' is set as index of first 0.  
    // Make all elements 0 from count to end. 
    while (count < n) 
        arr[count++] = 0; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int arr[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    pushZerosToEnd(arr, n); 
    cout << "Array after pushing all zeros to end of array :n"; 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    return 0; 
} 


*/
	
	//METHOD 2 Iterating till n and swapping non zero elements with iterator
	//T(n) = O(n)
	//Space = O(1)

// C++ implementation to move all zeroes at 
// the end of array 
#include <iostream> 
using namespace std; 
  
// function to move all zeroes at 
// the end of array 
void moveZerosToEnd(int arr[], int n) 
{ 
    // Count of non-zero elements 
    int count = 0; 
  
    // Traverse the array. If arr[i] is non-zero, then 
    // swap the element at index 'count' with the 
    // element at index 'i' 
    for (int i = 0; i < n; i++) 
        if (arr[i] != 0) 
            swap(arr[count++], arr[i]); 
} 
  
// function to print the array elements 
void printArray(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
} 
  
// Driver program to test above 
int main() 
{ 
    int arr[] = { 0, 1, 9, 8, 4, 0, 0, 2, 
                         7, 0, 6, 0, 9 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << "Original array: "; 
    printArray(arr, n); 
  
    moveZerosToEnd(arr, n); 
  
    cout << "\nModified array: "; 
    printArray(arr, n); 
  
    return 0; 
}

