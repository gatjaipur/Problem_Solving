/* METHOD 1 USING TRIM AND SPLIT
*
*
#include<stdio.h>
#include<stdlib.h>
#include <bits/stdc++.h>

	 using namespace std;
	
	void revWords(	vector<string>& v_strTokens, int n)
	{
		for(int i = n-1 ; i>=0 ; i-- )
		{
			cout << v_strTokens.at(i) << " ";
		}
	}
	
	
	int main()
	{
		string str = "I am Gaurav";
		            //Trimming the string
	    int iTrimIndex;
		iTrimIndex = str.find_first_not_of(" \t");
	    str.erase(0, iTrimIndex);
	            
	    iTrimIndex = str.find_last_not_of(" \t");
	    if(string::npos != iTrimIndex)
	    {
	    	str.erase(iTrimIndex +1);
		}
		
			// Splitting the string into vector with delimitter as space
			vector <string> v_strTokens;
			stringstream strStream(str);
			string strIntermediate;
			while(getline(strStream, strIntermediate, ' '))
    		{
       		 v_strTokens.push_back(strIntermediate);
   			}
   			
   	int n = v_strTokens.size();
	   		
		revWords(v_strTokens, n);
		return 0;
	}
	
	*/
	
/* METHOD 2 USING WORD REVERSAL AND THEN STRING REVERSAL	
	
#include <stdio.h> 

Function to reverse any sequence starting with pointer 
  begin and ending with pointer end  
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
  
    //STEP 2 of the above algorithm 
    reverse(s, temp - 1); 
}

int main() 
{ 
    char s[] = "i like this program very much"; 
    reverseWords(s); 
    printf("%s", s); 
    return 0; 
} 

*/

//METHOD 3 ITERATING FROM LAST AND SAVING IT IN A RESULTANT STRING WITH THE HELP OF 2 POINTERS

#include<iostream> 
  
using namespace std; 
  
string wordReverse(string str) 
{ 
    int i = str.length() - 1; 
    int start, end = i + 1; 
    string result = ""; 
      
    while(i >= 0) 
    { 
        if(str[i] == ' ') 
        { 
            start = i + 1; 
            while(start != end) 
                result += str[start++]; 
              
            result += ' '; 
              
            end = i; 
        } 
        i--; 
    } 
    start = 0; 
    while(start != end) 
        result += str[start++]; 
      
    return result; 
} 
  
// Driver code 
int main() 
{ 
    string str = "I AM A GEEK"; 
      
    cout << wordReverse(str); 
      
    return 0; 
} 

