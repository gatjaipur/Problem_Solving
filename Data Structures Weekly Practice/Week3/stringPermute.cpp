#include <bits/stdc++.h> 
using namespace std; 

// Duplicates not handled
// Unsorted Permutations


//Method -1 swap
// TC : O(n^2 * n!)
void permute(string str, int l, int r) {

	if (l == r) {
		cout << str << " ";
	} else {
		for (int i = l; i<=r; i++) {
			swap(str[l], str[i]);
			
			permute(str, l+1, r);
			
			swap(str[l], str[i]);

		}
	}		
}

int main() {
	
	string str = "ABB";  
    int n = str.size();  
    permute(str, 0, n-1);
	return 0;
}


//Method - 2 rotate inbuilt function
/*

void permute(string str, string out) {
	
	if(str.length() == 0) {
		cout << out << " ";
	}
	
	for(int i = 0; i<str.length(); i++) {
		
		permute(str.substr(1), out + str[0]);
		rotate(str.begin(), str.begin() + 1, str.end());
	}
}

int main() 
{ 
    string str = "ABB"; 
    permute(str, ""); 
    return 0; 
}

*/

// Method - 3 substr
/*
 void permutation(string str, string ans) 
    { 
        // If string is empty 
        if (str.length() == 0) { 
  
            // Add the generated permutation to the 
            // set in order to avoid duplicates 
            cout << ans << " ";
            return; 
        } 
  
        for (int i = 0; i < str.length(); i++) { 
  
            // ith character of str 
            char ch = str[i]; 
  
            // Rest of the string after excluding 
            // the ith character 
            string ros = str.substr(0, i) 
                         + str.substr(i + 1); 
  
            // Recurvise call 
            permutation(ros, ans + ch); 
        }
	}
    int main(){
    	
    	   string s = "abb"; 
  
        // Generate permutations 
        permutation(s, "");
  
        return 0;
        
	}
    */
