/* METHOD 1
// Taking 2 pointers and if one pointer finds space then iterate towards another pointer (or start swapping char ) and 
//save it in the string and then add space

#include <stdio.h> 

//Function to reverse any sequence starting with pointer 
  //begin and ending with pointer end  
void reverse(char* begin, char* end) 
{ 
    char temp; 
    while (begin < end) { 
        temp = *begin; 
        *begin++ = *end; 
        *end-- = temp; 
    } 
} 
  
	
void reverseWords(char* s) 
{ 
    char* word_begin = NULL; 
    char* temp = s; // temp is for word boundry 
  
    //STEP 1 of the above algorithm 
    while (*temp) { 
        //This condition is to make sure that the string start with 
          //valid character (not space) only
        if ((word_begin == NULL) && (*temp != ' ')) { 
            word_begin = temp; 
        } 
        if (word_begin && ((*(temp + 1) == ' ') || (*(temp + 1) == '\0'))) { 
            reverse(word_begin, temp); 
            word_begin = NULL; 
        } 
        temp++; 
    } // End of while 
  
}

int main() 
{ 
    char s[] = "i like this program very much"; 
    reverseWords(s); 
    printf("%s", s); 
    return 0; 
} 
*/


// METHOD 2 trim and split and then reversing each member of vector and adding space after that


//METHOD 3 We use a stack to push all words before space. As soon as we encounter a space, we empty the stack.

// C++ program to reverse individual words in a given  
// string using STL list 
#include <bits/stdc++.h> 
using namespace std; 
  
// reverses individual words of a string 
void reverseWords(string str) 
{ 
    stack<char> st; 
  
    // Traverse given string and push all characters 
    // to stack until we see a space. 
    for (int i = 0; i < str.length(); ++i) { 
        if (str[i] != ' ') 
            st.push(str[i]); 
  
        // When we see a space, we print contents 
        // of stack. 
        else { 
            while (st.empty() == false) { 
                cout << st.top(); 
                st.pop(); 
            } 
            cout << " "; 
        } 
    } 
  
    // Since there may not be space after 
    // last word. 
    while (st.empty() == false) { 
        cout << st.top(); 
        st.pop(); 
    } 
} 
  
// Driver program to test function 
int main() 
{ 
    string str = "Geeks for Geeks"; 
    reverseWords(str); 
    return 0; 
} 
