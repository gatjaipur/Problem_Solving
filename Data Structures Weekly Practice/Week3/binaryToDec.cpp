#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
//If more than Int Capacity then use string
//int binaryToDecimal(string n) 
//{ 
//    string num = n; 
//    int dec_value = 0; 
//  
//    // Initializing base value to 1, i.e 2^0 
//    int base = 1; 
//  
//    int len = num.length(); 
//    for (int i = len - 1; i >= 0; i--) { 
//        if (num[i] == '1') 
//            dec_value += base; 
//        base = base * 2; 
//    } 
//  
//    return dec_value; 
//} 
//  
//// Driver program to test above function 
//int main() 
//{ 
//    string num = "10101001"; 
//    cout << binaryToDecimal(num) << endl; 
//} 

void binaryToDec(int n) {
	
	int num = 0;
	
	int p = 0;
	while(n) {
		num += ((n%10) * pow(2,p));
		
		p++;
		n/=10;
	}
	
	cout << num;
}

int main() 
{ 
	int n = 100;
    binaryToDec(n);
	return 0; 
} 
