#include<iostream>
using namespace std;

int computeMagicNumber(int n) {
	
	int pow = 1;
	int answer = 0;
	
	while(n) {
		
		pow = pow*5;
		
		if(n&1) {
			answer += pow;
		}
		n>>=1;
	}
	return answer;
}


int main() 
{ 
	int n = 5;
	
    cout << computeMagicNumber(n) << endl;
	return 0; 
} 

