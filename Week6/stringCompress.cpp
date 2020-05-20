#include<iostream>
#include <sstream>
using namespace std;

//Method -1 
/*
void encode(string str) {
	
	int n = str.length();
	
	for(int i = 0; i<n; i++) {
	
	int count = 1;
	
		while(i<n-1 && str[i] == str[i+1]) {
			count++;
			i++;
		}
		
		cout <<str[i] << count;
	}
}



int main() 
{ 
    string str = "geeksforgeeks"; 
     encode(str); 
} 

*/

//Method -2 

void encode (string str) {
	int n = str.length();
	
	int countConsecutive = 0;
	string compressed = "";
	for(int i = 0; i<n; i++) {
		countConsecutive++;
		
		if(i+1 >= n || str[i+1] != str[i]) {
			compressed += str[i];
			std::ostringstream oss;
			oss << countConsecutive;
compressed+=oss.str();
			countConsecutive = 0;
		}
	}
	

//	compressed+= std::to_string(1);
	cout << compressed;
}

int main() 
{ 
    string str = "geeksforgeeks"; 
     encode(str); 
} 
