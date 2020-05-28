//  Created by Tenzin Chemi on 13/11/13.
//  Copyright (c) 2013 tenzin chemi. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// C++ implementation of Radix Sort 
#include<iostream> 
using namespace std; 

// A utility function to get maximum value in arr[] 
int getMax(int arr[], int n) 
{ 
	int mx = arr[0]; 
	for (int i = 1; i < n; i++) 
		if (arr[i] > mx) 
			mx = arr[i]; 
	return mx; 
} 

// A function to do counting sort of arr[] according to 
// the digit represented by exp. 
void countSort(int arr[], int n, int exp) 
{ 
	int output[n]; // output array 
	int i, count[10] = {0}; 

	// Store count of occurrences in count[] 
	for (i = 0; i < n; i++) 
		count[ (arr[i]/exp)%10 ]++; 

	// Change count[i] so that count[i] now contains actual 
	// position of this digit in output[] 
	for (i = 1; i < 10; i++) 
		count[i] += count[i - 1]; 

	// Build the output array 
	for (i = n - 1; i >= 0; i--) 
	{ 
		output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
		count[ (arr[i]/exp)%10 ]--; 
	} 

	// Copy the output array to arr[], so that arr[] now 
	// contains sorted numbers according to current digit 
	for (i = 0; i < n; i++) 
		arr[i] = output[i]; 
} 

// The main function to that sorts arr[] of size n using 
// Radix Sort 
void radixsort(int arr[], int n) 
{ 
	// Find the maximum number to know number of digits 
	int m = getMax(arr, n); 

	// Do counting sort for every digit. Note that instead 
	// of passing digit number, exp is passed. exp is 10^i 
	// where i is current digit number 
	for (int exp = 1; m/exp > 0; exp *= 10) 
		countSort(arr, n, exp); 
} 

// A utility function to print an array 
void print(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; 
} 

int main() {
    int *data,i, n;
    int neg[10],pos[10],j=0,k=0,l=0;
    printf("Enter the no of entries:");
    scanf("%d", &n);
    data = (int *)malloc(sizeof (int) * n);
    printf("Enter your inputs:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    
    for(i=0;i<n;i++){
        if(data[i]<0){
            neg[j] = data[i];
            neg[j] = abs(neg[j]);
            j++;
            
        } else {
            pos[k] = data[i];
            k++;
        }
    }
    radixsort(neg, j);
    
    printf("\n Negative Numbers\n");
    for(i=0;i<j;i++){
        printf("%d | ",neg[i]);
    }
    radixsort(pos, k);
    
    printf("\n Positive Numbers\n");
    for(i=0;i<k;i++){
        printf("%d | ",pos[i]);
    }
    
    
    l = j-1;
    for(i=0;i<j;i++){
        data[i] = neg[l];
        data[i] = data[i]*(-1);
        l=l-1;
        
    }
    
    l = 0;
    for(i=j;i<n;i++){
        data[i] = pos[l++];
    }
    
    printf("\nData After Sorting:\n");
    for (i = 0; i < n; i++)
        printf("%-5d ", data[i]);
    printf("\n");
    
    return 0;
}

