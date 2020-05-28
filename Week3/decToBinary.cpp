#include<iostream>
#include<vector>
using namespace std;

////Method - 1
//void decToBinary(int n) {
//	
// // Size of an integer is assumed to be 32 bits 
//    for (int i = 31; i >= 0; i--) { 
//        int k = n >> i; 
//        if (k & 1) 
//            cout << "1"; 
//        else
//            cout << "0"; 
//    }
//}
  

//Method - 2
//
//void decToBinary(int n) {
//	
//	if(n >= 1) {
//		
//	decToBinary(n/2);
//	
//	cout << (n%2);
//}
//}


//Method - 3
// function for decimal to binary conversion 
// without using arithmetic operators 
//string decToBin(int n) 
//{ 
//    if (n == 0) 
//        return "0"; 
//      
//    // to store the binary equivalent of decimal 
//    string bin = "";     
//    while (n > 0)     
//    { 
//        // to get the last binary digit of the number 'n' 
//        // and accumulate it at the beginning of 'bin' 
//        bin = ((n & 1) == 0 ? '0' : '1') + bin; 
//          
//        // right shift 'n' by 1 
//        n >>= 1; 
//    } 
//      
//    // required binary number 
//    return bin; 
//}


//Method - 4

void decToBinary(int n) {
	
	vector<int> v;
	
	while(n) {
		
		v.push_back(n%2);
		
		n/=2;
		
	}
	
	for(int i = v.size() -1; i>=0; i--) {
		cout<<v.at(i);
	}
}

int main() 
{ 
	int n = 4;
    decToBinary(n);
	return 0; 
} 

