 

class Solution {
public:
    int reverse(int x) {
        
        bool sign = false;
        
        long number = x;
        if (number < 0) {
            sign = true;
            number = 0-number;
        }
        
        int num = (int)number;
        long res = 0;
        
        while (num > 0) {
            int mod = num%10;
            res = res*10 + mod;
            num/=10;
        }
        
      if (res > INT_MAX || res < INT_MIN) {
          return 0;
      }
        
      num  = (int) res;
      if (sign) {
          num = 0 - num;
      }
        
      return num;
    
    }
};
