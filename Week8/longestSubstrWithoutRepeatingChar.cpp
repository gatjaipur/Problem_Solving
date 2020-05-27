//Length of the longest substring without repeating characters

// Method 1 T(n) = O(n^3)
/*
// C++ program to find the length of the longest substring 
// without repeating characters 
#include <bits/stdc++.h> 
using namespace std; 

// This functionr eturns true if all characters in str[i..j] 
// are distinct, otherwise returns false 
bool areDistinct(string str, int i, int j) 
{ 

	// Note : Default values in visited are false 
	vector<bool> visited(26); 

	for (int k = i; k <= j; k++) { 
		if (visited[str[k] - 'a'] == true) 
			return false; 
		visited[str[k] - 'a'] = true; 
	} 
	return true; 
} 

// Returns length of the longest substring 
// with all distinct characters. 
int longestUniqueSubsttr(string str) 
{ 
	int n = str.size(); 
	int res = 0; // result 
	for (int i = 0; i < n; i++) 
		for (int j = i; j < n; j++) 
			if (areDistinct(str, i, j)) 
				res = max(res, j - i + 1); 
	return res; 
} 

// Driver code 
int main() 
{ 
	string str = "geeksforgeeks"; 
	cout << "The input string is " << str << endl; 
	int len = longestUniqueSubsttr(str); 
	cout << "The length of the longest non-repeating "
			"character substring is "
		<< len; 
	return 0; 
} 

*/

// Method 2 O(n2)
/*
// C++ program to find the length of the longest substring 
// without repeating characters 
#include <bits/stdc++.h> 
using namespace std; 

int longestUniqueSubsttr(string str) 
{ 
	int n = str.size(); 
	int res = 0; // result 

	// Note : Default values in visited are false 
	vector<bool> visited(256); 

	for (int i = 0; i < n; i++) { 
		for (int j = i; j < n; j++) { 

			// If current character is visited 
			// Break the loop 
			if (visited[str[j]] == true) 
				break; 

			// Else update the result if 
			// this window is larger, and mark 
			// current character as visited. 
			else { 
				res = max(res, j - i + 1); 
				visited[str[j]] = true; 
			} 
		} 

		// Remove the first character of previous 
		// window 
		visited[str[i]] = false; 
	} 
	return res; 
} 

// Driver code 
int main() 
{ 
	string str = "geeksforgeeks"; 
	cout << "The input string is " << str << endl; 
	int len = longestUniqueSubsttr(str); 
	cout << "The length of the longest non-repeating "
			"character substring is "
		<< len; 
	return 0; 
} 
*/

// Method 3 (Linear Time)

//Time Complexity: O(n + d) where n is length of the input string and d is number of characters in input string alphabet. For example, if string consists of lowercase English characters then value of d is 26.
//Auxiliary Space: O(d)

// C++ program to find the length of the longest substring 
// without repeating characters 
#include <bits/stdc++.h> 
using namespace std; 
#define NO_OF_CHARS 256 

int longestUniqueSubsttr(string str) 
{ 
	int n = str.size(); 

	int res = 0; // result 

	// last index of all characters is initialized 
	// as -1 
	vector<int> lastIndex(NO_OF_CHARS, -1); 

	// Initialize start of current window 
	int i = 0; 

	// Move end of current window 
	for (int j = 0; j < n; j++) { 

		// Find the last index of str[j] 
		// Update i (starting index of current window) 
		// as maximum of current value of i and last 
		// index plus 1 
		i = max(i, lastIndex[str[j]] + 1); 

		// Update result if we get a larger window 
		res = max(res, j - i + 1); 

		// Update last index of j. 
		lastIndex[str[j]] = j; 
	} 
	return res; 
} 

// Driver code 
int main() 
{ 
	string str = "geeksforgeeks"; 
	cout << "The input string is " << str << endl; 
	int len = longestUniqueSubsttr(str); 
	cout << "The length of the longest non-repeating "
			"character substring is "
		<< len; 
	return 0; 
} 

