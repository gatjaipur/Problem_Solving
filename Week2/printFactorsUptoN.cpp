//print all the factors upto n
#include <iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

void printFactors(int n) {
	int root = sqrt(n);
	
	for(int i = 1; i <= root; i++) {
		if(n%i == 0) {
			cout << "factor is i " << i << endl;
			
			if(n/i != i) {
				cout << "factor another one is " << n/i << endl;
			}
		}
	}
}

int main() {
	
	int n = 99;
	printFactors(n);
	return 0;
}
