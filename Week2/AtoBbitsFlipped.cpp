#include<iostream>
using namespace std;

////Method - 1
//int countSet(int n) {
//	int count = 0;
//	
//	while(n>0) {
//		count += (n&1);
//		n>>=1;
//		
//	}
//	return count;
//}  
//
//int aToBFlipCount(int A, int B) {
//	int C = A^B;
//	int ans = countSet(C);
//	return ans;
//}
//  

int aToBFlipCount(int A, int B) {
	int count = 0;
	
	while(A || B) {
	
	int last_bit_A = A&1;
	int last_bit_B = B&1;
	
	if(last_bit_A != last_bit_B)	{
		count++;
	}
	
	A>>=1;
	B>>=1;
	}
	
	return count;	
}

int main() 
{ 
	int A = 11;
	int B = 19;
    cout << aToBFlipCount(A, B) << endl;
	return 0; 
} 

