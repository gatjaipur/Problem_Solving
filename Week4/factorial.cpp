#include<iostream>
using namespace std;

// Method 1 Recursive

int fact(int n) {
	
	if(n == 0) {
		return 1;
	} else {
		return n*fact(n-1);
	}
}

int main() {
	int n = 5;
	cout << fact(n);
	return 0;
}

/* Method - 2 Iterative

int fact(int n) {
	
	int result = 1;
	
	if(n == 0 ) {
		return result;
	} 
	
	while(n>0) {
		result *= n;
		n--;
	}
	
	
}

int main() {
	int n = 5;
	cout << fact(n);
	return 0;
}
*/
