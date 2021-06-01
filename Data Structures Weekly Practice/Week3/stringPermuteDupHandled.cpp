//Duplicates handled
// Sorted Permutations

#include <bits/stdc++.h> 
using namespace std; 

// Method -1 Find Ceil


int compare(const void *a, const void *b) {
	return (*(char *)a - *(char *)b);
}

int findCeil(char str[], char first, int l, int r) {
	int ceilIndex = l;
	for(int i = l+1; i<=r; i++) {
		if(str[i] >first && str[ceilIndex] > str[i]) {
			ceilIndex = i;
		}
	}
	return ceilIndex;	
}

void reverse(char str[], int i, int j ){
	while(i < j) {
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}	
}

void sortedPermutations(char str[]) {
	
	
	int size = strlen(str);
	
	qsort(str, size, sizeof(str[0]), compare);
	
	bool isFinished = false;
	
	while(!isFinished) {
	
	cout << str << endl;
	int i;
	for( i = size - 2; i>= 0; --i) {
		if(str[i] < str[i+1]) {
			break;
		}
	}
		if(i == -1){
			isFinished = true;
		} else {
			int ceilIndex = findCeil(str, str[i], i+1, size -1);
			swap(str[i], str[ceilIndex]);
			qsort(str + i + 1, size - i -1, sizeof(str[0]), compare);
			//reverse(str, i+1, size -1);
		}
		

	}
}


int main()  
{  
    char str[] = "ABB";  
    sortedPermutations( str );  
    return 0;  
}


// Method -2 swap
/*
// C++ program to distinct permutations of the string 
#include <bits/stdc++.h> 
using namespace std; 

// Returns true if str[curr] does not matches with any of the 
// characters after str[start] 
bool shouldSwap(char str[], int start, int curr) 
{ 
	for (int i = start; i < curr; i++) 
		if (str[i] == str[curr]) 
			return 0; 
	return 1; 
} 



// Prints all distinct permutations in str[0..n-1] 
void findPermutations(char str[], int index, int n) 
{ 
	if (index >= n) { 
		cout << str << endl; 
		return; 
	} 

	for (int i = index; i < n; i++) { 

		// Proceed further for str[i] only if it 
		// doesn't match with any of the characters 
		// after str[index] 
		bool check = shouldSwap(str, index, i); 
		if (check) { 
			swap(str[index], str[i]); 
			findPermutations(str, index + 1, n); 
			swap(str[index], str[i]); 
		} 
	} 
} 

// Driver code 
int main() 
{ 
	char str[] = "ABB"; 
	int n = strlen(str); 
	findPermutations(str, 0, n); 
	return 0; 
} 
*/

// Method - 3 next_permutation
/*
//We can use next_permute() that modifies a string so that it stores lexicographically next permutation. 
//If current string is lexicographically largest, i.e., “CBA”, then next_permute() returns false
void permute(string str) {
	
	sort(str.begin(), str.end());
	
	do {
		cout << str << " ";
	}while(next_permutation(str.begin(), str.end()));
}


int main() 
{ 
    string str = "ABB"; 
    permute(str); 
    return 0; 
}
*/

// Method 4 bool array and substr
/*
 void permutation(string str, string ans) 
    { 
        // If string is empty 
        if (str.length() == 0) { 
  
            // Add the generated permutation to the 
            // set in order to avoid duplicates 
            cout << ans << " ";
            return; 
        } 
          bool alpha[26];

        for (int i = 0; i < str.length(); i++) { 
  
            // ith character of str 
            char ch = str[i]; 
  
            // Rest of the string after excluding 
            // the ith character 
            string ros = str.substr(0, i) 
                         + str.substr(i + 1); 
  
       if (alpha[ch - 'a'] == false) 
           {
			 permutation(ros, ans + ch); 
		}
            alpha[ch - 'a'] = true;
            // Recurvise call 
        }
	}
    int main(){
    	
    	   string s = "abb"; 
  
        // Generate permutations 
        permutation(s, "");
  
        return 0;
        
	}
   */ 
