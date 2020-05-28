#include<iostream>
using namespace std;

////Method - 1
//int countValues (int n) 
//{ 
//    int countV = 0; 
//  
//    // Traverse all numbers from 0 to n and 
//    // increment result only when given condition 
//    // is satisfied. 
//    for (int i=0; i<=n; i++ ) 
//        if ((n+i) == (n^i) ) 
//            countV++; 
//  
//    return countV; 
//} 

//Method - 2
// N + i = N^i + N&i

int countNForEquation(int n) {
	int count = 0;
	
	while(n) {
			if(n&1 == 0) {
				count++;
				cout << n << endl;
			}
			n>>=1;
	}
	return 1 << count;
}

int main() 
{ 
	int n = 4;
	
    cout << countNForEquation(n) << endl;
	return 0; 
} 

