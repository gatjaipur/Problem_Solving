// C++ program to check whether two strings are 
// Permutations of each other 

//Method 1 Sorting

#include <bits/stdc++.h> 
using namespace std; 

/* function to check whether two strings are 
Permutation of each other */
/*

bool arePermutation(string str1, string str2) 
{ 
	// Get lenghts of both strings 
	int n1 = str1.length(); 
	int n2 = str2.length(); 

	// If length of both strings is not same, 
	// then they cannot be Permutation 
	if (n1 != n2) 
	return false; 

	// Sort both strings 
	sort(str1.begin(), str1.end()); 
	sort(str2.begin(), str2.end()); 

	// Compare sorted strings 
	for (int i = 0; i < n1; i++) 
	if (str1[i] != str2[i]) 
		return false; 

	return true; 
} 

int main() 
{ 
	string str1 = "test"; 
	string str2 = "ttew"; 
	if (arePermutation(str1, str2)) 
	printf("Yes"); 
	else
	printf("No"); 

	return 0; 
} 
*/

// Method -2 Using count array

// C++ program to check whether two strings are 
// Permutations of each other 
#include <bits/stdc++.h> 
using namespace std; 
# define NO_OF_CHARS 256 

/* function to check whether two strings are 
Permutation of each other */
bool arePermutation(string str1, string str2) 
{ 
	// Create 2 count arrays and initialize 
	// all values as 0 
	int count1[NO_OF_CHARS] = {0}; 
	int count2[NO_OF_CHARS] = {0}; 
	int i; 

	// For each character in input strings, 
	// increment count in the corresponding 
	// count array 
	for (i = 0; str1[i] && str2[i]; i++) 
	{ 
		count1[str1[i]]++; 
		count2[str2[i]]++; 
	} 

	// If both strings are of different length. 
	// Removing this condition will make the 
	// program fail for strings like "aaca" 
	// and "aca" 
	if (str1[i] || str2[i]) 
	return false; 

	// Compare count arrays 
	for (i = 0; i < NO_OF_CHARS; i++) 
		if (count1[i] != count2[i]) 
			return false; 

	return true; 
} 

/* Driver program to test to print printDups*/
int main() 
{ 
	string str1 = "geeksforgeeks"; 
	string str2 = "forgeeksgeeks"; 
	if ( arePermutation(str1, str2) ) 
	printf("Yes"); 
	else
	printf("No"); 

	return 0; 
} 

// Method-3 only one count array
/*
// C++ function to check whether two strings are 
// Permutations of each other 
bool arePermutation(string str1, string str2) 
{ 
	// Create a count array and initialize all 
	// values as 0 
	int count[NO_OF_CHARS] = {0}; 
	int i; 

	// For each character in input strings, 
	// increment count in the corresponding 
	// count array 
	for (i = 0; str1[i] && str2[i]; i++) 
	{ 
		count[str1[i]]++; 
		count[str2[i]]--; 
	} 

	// If both strings are of different length. 
	// Removing this condition will make the 
	// program fail for strings like "aaca" and 
	// "aca" 
	if (str1[i] || str2[i]) 
	return false; 

	// See if there is any non-zero value in 
	// count array 
	for (i = 0; i < NO_OF_CHARS; i++) 
		if (count[i]) 
			return false; 
	return true; 
} 
*/

