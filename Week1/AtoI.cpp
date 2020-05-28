
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
