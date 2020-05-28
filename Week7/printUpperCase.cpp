#include<iostream>


using namespace std;

void printUpperCase(char str[]) {
	
	for(int i = 0; str[i]; i++) {
		if(str[i] >= 'a' && str[i] <= 'z') {
					str[i] = str[i] - 32;

		}
		cout << str[i];
	}	
}

int main() {
	
	char str[] = "Hi, This is Gaurav";
	printUpperCase(str);
	return 0;
}
