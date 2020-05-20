#include<iostream>
using namespace std;
//a number that is divisible by 2, 3 and 5 is ugly number

/*
int maxDivide(int a, int b) {
	while(a%b == 0) {
		a = a/b;
	}	
	return a;
}

int checkUgly(int no) {
	no = maxDivide(no, 2);
	no = maxDivide(no, 3);
	no = maxDivide(no, 5);
	
	if(no == 1) {
		return 1;
		
	}
	
	return 0;
}

int uglyNumber(int n) {
	
	int count = 1;
	int i = 1;
	
	while(count < n) {
				i++;
		if(checkUgly(i) == 1) {
			count++;
		}
	}
	
	return i;
}



int main() {
	
	int n = 150;
	cout << uglyNumber(n);
	return 0;
}

*/

//Method - 2

int uglyNumber(int n) {
	
	int ugly[n];
	int next_ugly_number = 1;
	int i2 = 0;
	int i3 = 0;
	int i5 = 0;

	int next_multiple_of_2 = 2;
	int next_multiple_of_3 = 3;
	int next_multiple_of_5 = 5;
	ugly[0] = 1;
	
	for(int i = 1; i < n; i++) {
		next_ugly_number = min(next_multiple_of_2, min(next_multiple_of_5, next_multiple_of_3));
		ugly[i] = next_ugly_number;
		
		if(next_ugly_number == next_multiple_of_2) {
			i2++;
			next_multiple_of_2 = ugly[i2]*2;
		}
		
				if(next_ugly_number == next_multiple_of_3) {
			i3++;
			next_multiple_of_3 = ugly[i3]*3;
		}
		
				if(next_ugly_number == next_multiple_of_5) {
			i5++;
			next_multiple_of_5 = ugly[i5]*5;
		}
	}
	return next_ugly_number;

}

int main() {
	
	int n = 150;
	cout << uglyNumber(n);
	return 0;
}
