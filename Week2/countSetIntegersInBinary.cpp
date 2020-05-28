#include<iostream>
using namespace std;

//Method - 1
//int countSet(int n) {
//	int count = 0;
//	
//	while(n) {
//		n = n & (n-1);
//		count++;
//		
//	}
//	return count;
//}

//Method-2

int countSet(int n) {
	int count = 0;
	
	while(n>0) {
		count += (n&1);
		n>>=1;
		
	}
	return count;
}  
  
int main() 
{ 
	int n = 2;
    cout << countSet(n) << endl;
	return 0; 
} 

