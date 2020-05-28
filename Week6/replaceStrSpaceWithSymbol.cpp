// Replace spaces in string with %20 upto the given index number length

#include<iostream>
using namespace std;

void replaceStrSpaceWithSymbol(string str, int n) {
	
	int count = 0;
	
	for(int i = 0; i< n; i++) {
		if(str[i] == ' ') {
			count++;
		}
	}
	
	// As the new %20 has 3 characters and the space included needs 2 more char for every space
	int newLength = n + count*2;
	char newStr[newLength + 1];
	
	for(int i = n -1; i>=0; i--) {
		if(str[i] == ' ') {
			newStr[newLength - 1] = '0';
			newStr[newLength - 2] = '2';
			newStr[newLength - 3] = '%';
			newLength-=3;

		} else
		{
			newStr[newLength - 1] = str[i];
			newLength--;
		}
	}
	int len = sizeof(newStr)/sizeof(newStr[0]);
//	
for(int i = 0; i< len-1; i ++) {
	cout << newStr[i];
}	
	string rem = str.substr(n);
cout << rem;
}

int main() {
	
	string str = " John is Good ";
	int index = 10;
	
	replaceStrSpaceWithSymbol(str, index);
	
	return 0;
}
