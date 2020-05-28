
/*
// Method 1 T(n) = O(nloglogn)

#include<iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;


void sieveOfErastosthenes(int n) {
	
	bool prime[n+1];
	memset(prime, true, sizeof(prime));
	
	for (int p = 2; p*p <= n; p++) {
		
		if(prime[p]) {
			
			for(int i = p*p; i <= n; i += p) {
				prime[i] = false;
			}
		}
	}
	
	
	for(int i = 2; i<= n; i++) {
		if(prime[i]) {
			cout << i << " ";
		}
	}
}

int main() {
	
	int n = 6;
	
	sieveOfErastosthenes(n);
	
 	return 0;
}
*/


/*
	Method - 2 T(n) = O(n)
*/



#include<iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

vector<long long> isPrime(10000, true);
vector<long long> prime;
vector<long long> sfs(10000);

void sieveOfErastosthenes(long long n) {
	
	isPrime[0] = false;
	isPrime[1] = false;
	
	for (long long int i = 2; i< n; i++) {
		if(isPrime[i]) {
			
			prime.push_back(i);
			sfs.push_back(i);
			
		} 	
		
		for (long long int j = 0; j < (int) prime.size() && i*prime[j] < n  && prime[j] <= sfs[i] ;j++) {
			
			isPrime[i*prime[j]] = false;
			sfs[i*prime[j]] = prime[j];
		}

	}
	
	
	for (int i = 0; i < prime.size() && prime[i]<= n; i++) {
		cout << prime[i] << " ";
	}
	
	

}

int main() {
	
	long long n = 6;
	
	sieveOfErastosthenes(n);
	
 	return 0;
}

