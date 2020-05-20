#include <iostream>
#include<math.h>
using namespace std;

void printPrimeFactors(int n) {
	
	bool isPrime = true;
	
	while(n%2 == 0) {
		cout << " 2 ";
		n/=2;
		isPrime = false;
	}
	
	for(int i = 3; i<=sqrt(n); i++) {
		if(n%i == 0) {
			cout<< " " << i << " " << n/i << " ";
			n/=i;
					isPrime = false;
		}
	}
	
	if(isPrime) {
		cout << " 1 " << n;
	}
}

int main() {
	
	int n = 101;
	printPrimeFactors(n);
	return 0;
}
