
#include<bits/stdc++.h> 
using namespace std; 
/*
// C++ implementation to check if 
// characters of a given string can 
// be rearranged to form a palindrome 
#include<bits/stdc++.h> 
using namespace std; 
#define NO_OF_CHARS 256 


bool canFormPalindrome(string str) 
{ 
	// Create a count array and initialize all 
	// values as 0 
	int count[NO_OF_CHARS] = {0}; 

	// For each character in input strings, 
	// increment count in the corresponding 
	// count array 
	for (int i = 0; str[i]; i++) 
		count[str[i]]++; 

	// Count odd occurring characters 
	int odd = 0; 
	for (int i = 0; i < NO_OF_CHARS; i++) 
	{ 
		if (count[i] & 1) 
			odd++; 

		if (odd > 1) 
			return false; 
	} 

	// Return true if odd count is 0 or 1, 
	return true; 
} 

int main() 
{ 
canFormPalindrome("geeksforgeeks")? cout << "Yes\n": 
									cout << "No\n"; 
canFormPalindrome("geeksogeeks")? cout << "Yes\n": 
									cout << "No\n"; 
return 0; 
} 
*/
// Method -2 Using list 

/*

#include<bits/stdc++.h> 
using namespace std; 

bool canFormPalindrome(string str) 
{ 

	// Create a list 
	vector<char> list; 

	// For each character in input strings, 
	// remove character if list contains 
	// else add character to list 
	for (int i = 0; i < str.length(); i++) 
	{ 
		auto pos = find(list.begin(), list.end(), str[i]); 
		if (pos != list.end()) 
		{ 
			auto posi = find(list.begin(), list.end(),str[i]); 
			list.erase(posi); 
		} 
		else
			list.push_back(str[i]); 
	} 

	// if character length is even list is expected to be empty 
	// or if character length is odd list size is expected to be 1 
	if (str.length() % 2 == 0 && list.empty() // if string length is even 
		|| (str.length() % 2 == 1 && list.size() == 1)) // if string length is odd 
		return true; 
	else
		return false; 

} 

// Driver program 
int main() 
{ 
	if (canFormPalindrome("geeksforgeeks")) 
		cout << ("Yes") << endl; 
	else
		cout << ("No") << endl; 

	if (canFormPalindrome("geeksogeeks")) 
		cout << ("Yes") << endl; 
	else
		cout << ("No") << endl; 
} 
*/

// Method 3

int charNum (char ch) {
	
	if(ch >= 'a' && ch <= 'z') {
		return ch - 'a';
	}
	return -1;
}
int toggle (int bitVec, int index) {
	if(index < 0) {
		return bitVec;
	}
	int mask = 1<<index;
	
	if((bitVec & mask) == 0) {
		bitVec |= mask;
		
	}	else {
		bitVec &= ~mask;
	}
	return bitVec;
}

int createBitVec(string str){
	int bitVec = 0;
	
	for(int i = 0; str[i]; i++) {
		int x = charNum(str[i]);
		bitVec = toggle(bitVec, x);
	}
	return bitVec;	
}

bool checkExactlyOneBitSet(int bitVec) {
	return ( (bitVec & (bitVec-1))	== 0);
}

bool canFormPalindrome(string str) 
{
	int bitVec = createBitVec(str);
	return ((bitVec == 0) || checkExactlyOneBitSet(bitVec));
}

int main() 
{ 
	if (canFormPalindrome("geeksforgeeks")) 
		cout << ("Yes") << endl; 
	else
		cout << ("No") << endl; 

	if (canFormPalindrome("geeksogeeks")) 
		cout << ("Yes") << endl; 
	else
		cout << ("No") << endl; 
} 
