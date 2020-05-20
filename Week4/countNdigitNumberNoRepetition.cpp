#include<iostream>
#include <math.h>
using namespace std;

int countNdigitNumberNoRepetition(int N) {
	
	int high = (int)pow(10, N);
	int low = (int)pow(10, N-1);
	int count = high - low;
	
	int arr[10];
	int p =0;
	for(int i = low; i<high; i++) {
		
		for(int j = 0; j< 10; j++) {
			arr[j] = 0;
		}
		
		int temp = i;
		if(N > 1) {
		
		while(temp) {
			int mod = temp%10;
			arr[mod]++;
			if(arr[mod] == 2) {
				p++;
				cout << " repeated number is : "<< i << endl;
				break;
			}
			temp/=10;
		}
	}
		
	}
	
	
	int ans = count - p;
	return ans;	
}

int main() {
	
	int N = 2;
	cout << countNdigitNumberNoRepetition(N);
	return 0;
}
