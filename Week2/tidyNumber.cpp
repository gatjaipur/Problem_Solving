#include<iostream>
using namespace std;

bool tidy(int num)
{
    if(num < 0)
    {
        num*= -1;
    }
   int prev = 10;
   
   int rem;
   
   while(num)
   {
        rem = num%10;
        num/=10;
        
        if(prev < rem)
        {
            return false;
        }
        
        prev = rem;
   }
   return true;
}

int main()
{
    int number = -1234;    
    bool ans = tidy(number);
    cout << ans << endl;
    return 0;
}
