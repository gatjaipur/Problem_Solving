/* METHOD 1 MAKING OWN SWAP METHOD
*
*/
#include<bits/stdc++.h>
using namespace std;

string reverse(string str, int start, int end)
{
	
	if(str.empty())
	{
		return str;
	}

	
	if(start<end)
	{
		char temp;
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		
		return reverse(str, start+1, end-1);
	}
	
	return str;
	
	
}


void print(string str, int n)
{
	cout<<str<<endl;
}
int main()
{
	string str = "I am Gaurav";
	int n = str.length();

	string revStr = reverse(str, 0 , n-1);
	print(revStr,n);
	return 0;
}









/* METHOD 2 USING SWAP BUILT IN FUNCTION
*
*
// A Simple C++ program to reverse a string 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to reverse a string 
void reverseStr(string& str) 
{ 
    int n = str.length(); 
  
    // Swap character starting from two 
    // corners 
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
} 
  
// Driver program 
int main() 
{ 
    string str = "geeksforgeeks"; 
    reverseStr(str); 
    cout << str; 
    return 0; 
} 

*/

/* METHOD 3 Using inbuilt “reverse” function: 
*
*

#include <bits/stdc++.h> 
using namespace std; 
int main() 
{ 
    string str = "geeksforgeeks"; 
  
    // Reverse str[beign..end] 
    reverse(str.begin(), str.end()); 
  
    cout << str; 
    return 0; 
} 
*/

/* METHOD 4
* Getting reverse of a const string:
*
*

// C++ program to get reverse of a cosnt string 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to reverse string and return 
// reverse string pointer of that 
char* reverseConstString(char const* str) 
{ 
    // find length of string 
    int n = strlen(str); 
  
    // create dynamic pointer char array 
    char *rev = new char[n+1]; 
  
    // copy of string to ptr array 
    strcpy(rev, str); 
  
    // Swap character starting from two 
    // corners 
    for (int i=0, j=n-1; i<j; i++,j--) 
        swap(rev[i], rev[j]);        
      
    // return pointer of reversed string 
    return rev; 
} 
  
// Driver code 
int main(void) 
{ 
    const char *s = "GeeksforGeeks"; 
    printf("%s", reverseConstString(s)); 
    return (0); 
} 

*/



/* Method 5 using own swap function with loop

#include<bits/stdc++.h>
using namespace std;
string reverse(string str, int start, int end)
{
	
	if(str.empty())
	{
		return str;
	}

	
	while(start<end)
	{
		char temp;
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		
		start++;
		end--;
	}
	
	return str;
	
	
}


void print(string str, int n)
{
	cout<<str<<endl;
}
int main()
{
	string str = "I am Gaurav";
	int n = str.length();

	string revStr = reverse(str, 0 , n-1);
	print(revStr,n);
	return 0;
}

*/


/* METHOD 6 imply print backwards
*

// C++ program to print reverse of a string 
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to reverse a string 
void reverse(string str) 
{ 
   for (int i=str.length()-1; i>=0; i--) 
      cout << str[i];  
} 
  
// Driver code 
int main(void) 
{ 
    string s = "GeeksforGeeks"; 
    reverse(s); 
    return (0); 
} 

*/
