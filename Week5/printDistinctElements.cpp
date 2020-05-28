#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//Method 1 Using sort
/*
void distinctElements(int arr[], int n) {
	
	sort(arr, arr+n);
	
	for(int i = 0; i< n; i++) {
		bool flag = true;
			if((i < n-1 && arr[i] == arr[i+1]) || (i>0 && arr[i] == arr[i-1])) {
				flag = false;
			}
		if(flag) {
			cout << arr[i] << " ";
		}
	}
}

int main() {
	int arr[] = {2, 5, 3, 5, 7, 2, 6, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	distinctElements(arr, n);
	return 0;
}

*/

//Method 2 using set
#include<set>

void distinctElements(int arr[], int n) {

    set<int> s; 
	for(int i = 0; i<n; i++ ) {
		
		if(s.find(arr[i]) == s.end()) {
			s.insert(arr[i]);
		} else {
			s.erase(arr[i]);
		}
		
		
	}
	    set<int>::iterator it; 

	for (it = s.begin(); it != s.end(); ++it) 
        cout << ' ' << *it;
}

int main() {
	int arr[] = {2, 5, 3, 5, 7, 2, 6, 6};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	distinctElements(arr, n);
	return 0;
}

// Method 3

/*

// C++ program to print all distinct elements in a given array 
#include <bits/stdc++.h> 
using namespace std; 

void printDistinct(int arr[], int n) 
{ 
	// Pick all elements one by one 
	for (int i=0; i<n; i++) 
	{ 
		// Check if the picked element is already printed 
		int j; 
		for (j=0; j<i; j++) 
		if (arr[i] == arr[j]) 
			break; 

		// If not printed earlier, then print it 
		if (i == j) 
		cout << arr[i] << " "; 
	} 
} 

// Driver program to test above function 
int main() 
{ 
	int arr[] = {6, 10, 5, 4, 9, 120, 4, 6, 10}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printDistinct(arr, n); 
	return 0; 
}

*/
