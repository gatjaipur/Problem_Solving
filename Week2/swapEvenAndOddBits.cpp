#include<iostream>
using namespace std;

int swapEvenOddBits(int n) {
	int even = n & 0xAAAAAAAA;
	int odd = n &  0x55555555;
	
	even >>=1;
	odd <<=1;
	
	return (even|odd);
}

int main() 
{ 
	int n = 5;
	
    cout << swapEvenOddBits(n) << endl;
	return 0; 
} 

