#include<iostream>
using namespace std;

bool checkForReplace (string first, string second ) {
			bool found = false;

	for(int i = 0; i< first.length(); i++) {
		
		if(first[i] != second[i]) {
			if(found) {
							return false;
			}
			found = true;
		}
	}
	
	return true;
}

bool checkForInsert(string first, string second)
{
	int firstStrLen = first.length();
	int secondStrLen = second.length();
	

	if (firstStrLen > secondStrLen) {
			if(firstStrLen - secondStrLen > 1) {
		return false;
	}
	} else {
				if(secondStrLen - firstStrLen > 1) {
		return false;
	}	
	}
	
	int largerStrLen = ( firstStrLen > secondStrLen) ? firstStrLen : secondStrLen;
	
	int index1 = 0; 
	int index2 = 0;
	
	while(index1 < firstStrLen && index2 < secondStrLen) {
		
		if(first[index1] != second[index2]) {
			
			if(index1 != index2) {
				return false;
			}
			
		if (firstStrLen > secondStrLen) 
		{ index1++ ;}
		 else {
			index2++;
		} 
		
		} else
		{
			index1++;
			index2++;
		}
		
	}
	return true;
}

bool isEditDistanceOne (string first, string second) {
	
	if(first.length() == second.length()) {
		return checkForReplace(first, second);
	} 
	
	return checkForInsert(first, second);
}


int main() 
{ 
   string s1 = "gf"; 
   string s2 = "gds"; 
   isEditDistanceOne(s1, s2)? 
           cout << "Yes": cout << "No"; 
   return 0; 
} 


// Same Method but different way of writing 

/*
// C++ program to check if given two strings are 
// at distance one. 
#include <bits/stdc++.h> 
using namespace std; 

// Returns true if edit distance between s1 and 
// s2 is one, else false 
bool isEditDistanceOne(string s1, string s2) 
{ 
	// Find lengths of given strings 
	int m = s1.length(), n = s2.length(); 

	// If difference between lengths is more than 
	// 1, then strings can't be at one distance 
	if (abs(m - n) > 1) 
		return false; 

	int count = 0; // Count of edits 

	int i = 0, j = 0; 
	while (i < m && j < n) 
	{ 
		// If current characters don't match 
		if (s1[i] != s2[j]) 
		{ 
			if (count == 1) 
				return false; 

			// If length of one string is 
			// more, then only possible edit 
			// is to remove a character 
			if (m > n) 
				i++; 
			else if (m< n) 
				j++; 
			else //Iflengths of both strings is same 
			{ 
				i++; 
				j++; 
			} 
			
			// Increment count of edits 
			count++; 
		} 

		else // If current characters match 
		{ 
			i++; 
			j++; 
		} 
	} 

	// If last character is extra in any string 
	if (i < m || j < n) 
		count++; 

	return count == 1; 
} 

// Driver program 
int main() 
{ 
string s1 = "gfg"; 
string s2 = "gf"; 
isEditDistanceOne(s1, s2)? 
		cout << "Yes": cout << "No"; 
return 0; 
} 
*/
