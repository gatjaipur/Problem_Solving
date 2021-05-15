#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

//A number is said to be a sparse number if in binary representation of the number no two or more consecutive bits are set

// Return true if n is sparse, else false 
bool checkSparse(int n) 
{ 
    // n is not sparse if there is set 
    // in AND of n and n/2 
    if (n & (n>>1)) 
        return false; 
  
    return true; 
} 

	
int sparseNumber(int x) 
{ 	

if(checkSparse(x)) {
		return x;
	}
    // Find binary representation of x and store it in bin[]. 
    // bin[0] contains least significant bit (LSB), next 
    // bit is in bin[1], and so on. 
    vector<bool> bin; 
    while (x != 0) 
    { 
        bin.push_back(x&1); 
        x >>= 1; 
    } 
  
    // There my be extra bit in result, so add one extra bit 
    bin.push_back(0); 
    int n = bin.size();  // Size of binary representation 
  
    // The position till which all bits are finalized 
    int last_final = 0; 
  
    // Start from second bit (next to LSB) 
    for (int i=1; i<n-1; i++) 
    { 
       // If current bit and its previous bit are 1, but next 
       // bit is not 1. 
       if (bin[i] == 1 && bin[i-1] == 1 && bin[i+1] != 1) 
       { 
            // Make the next bit 1 
            bin[i+1] = 1; 
  
            // Make all bits before current bit as 0 to make 
            // sure that we get the smallest next number 
            for (int j=i; j>=last_final; j--) 
                bin[j] = 0; 
  
            // Store position of the bit set so that this bit 
            // and bits before it are not changed next time. 
            last_final = i+1; 
        } 
    } 
  
    // Find decimal equivalent of modified bin[] 
    int ans = 0; 
    for (int i =0; i<n; i++) 
        ans += bin[i]*(1<<i); 
    return ans; 
} 
  
int main() 
{ 
	int n = 38;
     cout << sparseNumber(n) << endl;
	return 0; 
} 

