#include<iostream>
using namespace std;

void stockBuySell(int price[], int n) {
	
	if(n == 1) {
		return;
	}
	int i = 0;

	
	while(i < n-1) {
		
		while(i< n-1 && price[i]>=price[i+1]) {
			i++;
		}
		
		if(i == n-1) {
 break;		}
		
		int buy = i++;
		
		while(i< n && price[i] >= price[i-1]) {
			i++;
		}
		
int sell = i-1;
 cout << " buy " << buy << " and sell " << sell << endl;
	}
}


/* If we are allowed to buy and sell only once, then we can use following algorithm.
 Maximum difference between two elements. Here we are allowed to buy and sell multiple times */
int main() 
{ 
    // Stock prices on consecutive days 
    int price[] = { 100, 180, 260, 310, 40, 535, 695 }; 
    int n = sizeof(price) / sizeof(price[0]); 
  
    // Fucntion call 
    stockBuySell(price, n); 
  
    return 0; 
} 
