/*
Program for Chocolate and Wrapper Puzzle
Given following three values, the task is to find the total number of maximum chocolates you can eat.

money : Money you have to buy chocolates
price : Price of a chocolate
wrap : Number of wrappers to be returned for getting one extra chocolate
*/

//Method 1

/*
// Recursive C++ program to find maximum 
// number of chocolates 
#include <iostream> 
using namespace std; 

// Returns number of chocolates we can 
// have from given number of chocolates 
// and number of wrappers required to 
// get a chocolate. 
int countRec(int choc, int wrap) 
{ 
	// If number of chocolates is less than 
	// number of wrappers required. 
	if (choc < wrap) 
		return 0; 

	// We can immediatly get newChoc using 
	// wrappers of choc. 
	int newChoc = choc/wrap; 

	// Now we have "newChoc + choc%wrap" wrappers. 
	return newChoc + countRec(newChoc + choc%wrap, 
							wrap); 
} 

// Returns maximum number of chocolates we can eat 
// with given money, price of chocolate and number 
// of wrappers required to get a chocolate. 
int countMaxChoco(int money, int price, int wrap) 
{ 
	// We can directly buy below number of chocolates 
	int choc = money/price; 

	// countRec returns number of chocolates we can 
	// have from given number of chocolates 
	return choc + countRec(choc, wrap); 
} 

// Driver code 

int main() 
{ 
	int money = 15 ; // total money 
	int price = 1; // cost of each candy 
	int wrap = 3 ; // no of wrappers needs to be 

	// exchanged for one chocolate. 

	cout << countMaxChoco(money, price, wrap); 
	return 0; 
} 

*/

//Method 2

// Efficient C++ program to find maximum 
// number of chocolates 
#include <iostream> 
using namespace std; 

// Returns maximum number of chocolates we can eat 
// with given money, price of chocolate and number 
// of wrapprices required to get a chocolate. 
int countMaxChoco(int money, int price, int wrap) 
{ 
	// Corner case 
	if (money < price) 
	return 0; 

	// First find number of chocolates that 
	// can be purchased with the given amount 
	int choc = money / price; 

	// Now just add number of chocolates with the 
	// chocolates gained by wrapprices 
	choc = choc + (choc - 1) / (wrap - 1); 
	return choc; 
} 

// Driver code 
int main() 
{ 
	int money = 15 ; // total money 
	int price = 1; // cost of each candy 
	int wrap = 3 ; // no of wrappers needs to be 
	// exchanged for one chocolate. 

	cout << countMaxChoco(money, price, wrap); 
	return 0; 
} 

