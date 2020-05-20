//Method - 1
/*
// Simple CPP program to print all permutations 
// of a string that follow given constraint 
#include <bits/stdc++.h> 
using namespace std; 

void permute(string& str, int l, int r) 
{ 

	// Check if current permutation is 
	// valid 
	if (l == r) { 
		if (str.find("AB") == string::npos) 
			cout << str << " "; 
		return; 
	} 

	// Recursively generate all permutation 
	for (int i = l; i <= r; i++) { 
		swap(str[l], str[i]); 
		permute(str, l + 1, r); 
		swap(str[l], str[i]); 
	} 
} 

// Driver Code 
int main() 
{ 
	string str = "ABC"; 
	permute(str, 0, str.length() - 1); 
	return 0; 
} 

*/

//Method -2
// Backtracking based CPP program to print all 
// permutations of a string that follow given 
// constraint 
#include <bits/stdc++.h> 
using namespace std; 

bool isSafe(string &str, int l, int i, int r) 
{ 
	// If previous character was 'A' and character 
	// is 'B', then do not proceed and cut down 
	// the recursion tree. 
	if (l != 0 && str[l-1] == 'A' && str[i] == 'B') 
	return false; 

	// This condition is explicitly required for 
	// cases when last two characters are "BA". We 
	// do not want them to swapped and become "AB" 
	if (r == l+1 && str[i] == 'A' && str[l] == 'B') 
	return false; 

return true; 
} 

void permute(string& str, int l, int r) 
{ 
	// We reach here only when permutation 
	// is valid 
	if (l == r) { 
		cout << str << " "; 
		return; 
	} 
	
	// Fix all characters one by one 
	for (int i = l; i <= r; i++) { 

	// Fix str[i] only if it is a 
	// valid move. 
	if (isSafe(str, l, i, r)) { 
		swap(str[l], str[i]); 
		permute(str, l + 1, r); 
		swap(str[l], str[i]); 
	} 
	} 
} 

// Driver Code 
int main() 
{ 
	string str = "ABC"; 
	permute(str, 0, str.length() - 1); 
	return 0; 
} 

