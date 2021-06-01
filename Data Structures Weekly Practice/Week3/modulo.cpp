#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

//Method - 1
//// This function returns remainder of num/divisor 
//// without using % (modulo) operator 
//int getRemainder(int num, int divisor) 
//{ 
//    return (num - divisor * (num / divisor)); 
//} 
  
//  
//  //Method - 2
  int getRemainder(int num, int divisor) 
{ 
  
    // While divisor is smaller 
    // than n, keep subtracting 
    // it from num 
    while (num >= divisor) 
        num -= divisor; 
  
    return num; 
} 


// Method - 3
//d must be a power of 2
//int getRemainder(int n, int d) 
//{ 
//  
//    // Bitwise AND with 3 
//    int x = (n & (d-1)); 
//  
//    // return  x 
//    return x; 
//} 

//// Driver program to test above functions 
int main() 
{ 
    // cout << 100 %0; 
    cout << getRemainder(45, 8); 
    return 0; 
}
