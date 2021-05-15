
/* Method 1 - Using stringstream
// A program to demonstrate the use of stringstream
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	string s = "12345";

	// object from the class stringstream
	stringstream geek(s);

	// The object has the value 12345 and stream
	// it to the integer x
	int x = 0;
	geek >> x;

	// Now the variable x holds the value 12345
	cout << "Value of x : " << x;

	return 0;
}
*/

//Method 2
#include<iostream>
using namespace std;

bool numericChar(char ch)
{
    if(ch >= '0' && ch <= '9')
    {
        return true;
    }
        return false;
}
int myAtoI(char str[])
{
   if(str == NULL)
   {
       return 0;
   }

   int i =0;
   int res = 0;

   int sign = 1;

   if(str[0] == '-')
   {
       sign = -1;
       i++;
   }

   for(; str[i]; i++)
   {
      if(!numericChar(str[i]))
      {
          return 0;
      }

      res = res*10 + str[i] - '0';
   }

   return sign*res;
}

int main()
{
    char arr[] = "-1231";
    int ans = myAtoI(arr);
    cout << ans << endl;
    return 0;
}

//Method 3 Using stoi

// C++ program to demonstrate working of stoi()
// Work only if compiler supports C++11 or above.
// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {
// 	string str1 = "45";
// 	string str2 = "3.14159";
// 	string str3 = "31337 geek";

// 	int myint1 = stoi(str1);
// 	int myint2 = stoi(str2);
// 	int myint3 = stoi(str3);

// 	cout << "stoi(\"" << str1 << "\") is "
// 		<< myint1 << '\n';
// 	cout << "stoi(\"" << str2 << "\") is "
// 		<< myint2 << '\n';
// 	cout << "stoi(\"" << str3 << "\") is "
// 		<< myint3 << '\n';

// 	return 0;
// }

//Method 4 Using atoi

// // For C++11 above
// #include <iostream>
// #include <cstdlib>
// using namespace std;

// int main()
// {
// 	const char *str1 = "42";
// 	const char *str2 = "3.14159";
// 	const char *str3 = "31337 geek";
	
// 	int num1 = atoi(str1);
// 	int num2 = atoi(str2);
// 	int num3 = atoi(str3);

// 	cout << "atoi(\"" << str1
// 			<< "\") is " << num1 << '\n';
// 	cout << "atoi(\"" << str2
// 			<< "\") is " << num2 << '\n';
// 	cout << "atoi(\"" << str3
// 			<< "\") is " << num3 << '\n';
	
// return 0;
// }

