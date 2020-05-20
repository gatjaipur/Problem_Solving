#include<iostream>
using namespace std;

void findOccurence(string line, string word) {
	int j =0;
	bool found = false;
	for(int i = 0; i < line.length(); i++) {
		
		while(j < word.length()) {
			if(word[j] != line[i+j]) {
				found = false;
				break;
			} else {
				found = true;
			}
			
			j++;
		}
		
		if(found) {
			cout << " Found word at " << (i + (j-1)) - (word.length() - 1) << " to "<< (i + (j-1)) << endl;
//			if only first occurence to be printed then apply break here
//			break;
		}
		
		j = 0;
	}
}

int main() {
	string line = "Fox ish a wild cat wish and it is has four legs";
	string word = "is";
	findOccurence(line, word);
	
	return 0;
}
