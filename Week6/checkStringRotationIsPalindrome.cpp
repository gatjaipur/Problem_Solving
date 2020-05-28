//Time Complexity: O(n2)
//Auxiliary Space: O(n) for storing rotations

#include<iostream> 
#include<string> 
using namespace std; 

// A utility function to check if a string str is palindrome 
bool isPalindrome(string str) 
{ 
	// Start from leftmost and rightmost corners of str 
	int l = 0; 
	int h = str.length() - 1; 

	// Keep comparing characters while they are same 
	while (h > l) 
		if (str[l++] != str[h--]) 
			return false; 

	// If we reach here, then all characters were matching 
	return true; 
} 

// Function to check if a given string is a rotation of a 
// palindrome. 
bool isRotationOfPalindrome(string str) 
{ 
// If string iteself is palindrome 
if (isPalindrome(str)) 
		return true; 

// Now try all rotations one by one 
int n = str.length(); 
for (int i = 0; i < n-1; i++) 
{ 
	string str1 = str.substr(i+1, n-i-1); 
	string str2 = str.substr(0, i+1); 

	// Check if this rotation is palindrome 
	if (isPalindrome(str1.append(str2))) 
		return true; 
} 
return false; 
} 

// Driver program to test above function 
int main() 
{ 
	cout << isRotationOfPalindrome("aab") << endl; 
	cout << isRotationOfPalindrome("abcde") << endl; 
	cout << isRotationOfPalindrome("aaaad") << endl; 
	return 0; 
} 


/*

T(n) = O(n)
Space = O(1)

1) Let the given string be ‘str’ and length of string be ‘n’. Create a temporary string ‘temp’ which is of size 2n 
and contains str followed by str again. For example, let str be “aab”, temp would be “aabaab”.
2) Now the problem reduces to find a palindromic substring of length n in str. If there is palindromic substring of length n, 
then return true, else return false.
We can find whether there is a palindromic substring of size n or not in O(n) time

*/

