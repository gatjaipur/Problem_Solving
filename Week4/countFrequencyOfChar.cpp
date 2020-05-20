#include<iostream>
using namespace std;

void countFrequencyOfChar(char ch, string str) {
		int count[256] = {0};
		
		for(int i = 0; i< str.length(); i++) {
			count[str[i]]++;
			
			//or
			// if(str[i] == 'a') { count ++;}

		}
					cout << count[ch] << endl;

}

int main() {
	
	string str = " Gaurav Garg";
	char ch = 'a';
	countFrequencyOfChar(ch, str);
	return 0;
}
