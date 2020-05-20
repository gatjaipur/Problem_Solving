#include<iostream>
#include<string>
using namespace std;

// Returns true if s1 is substring of s2 
bool isSubstring(string s1, string s2) 
{ 
    int M = s1.length(); 
    int N = s2.length(); 
  
    for (int i = 0; i <= N - M; i++) { 
        int j; 
  
        for (j = 0; j < M; j++) 
            if (s2[i + j] != s1[j]) 
                break; 
  
        if (j == M) 
            return true; 
    } 
  
    return false; 
} 

bool isRotation(string a, string b) {
	
	int len = a.length();
	
	if(len == b.length() && len>0) {
		
		string aa = a + a;
		return isSubstring(b, aa);
	}	
	return false;
}

int main() {
	
	string a = "GAURAV";
	string b = "RAVGAU";
	cout << isRotation(a, b);
	return 0;
}
