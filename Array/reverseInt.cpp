//  Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

// Example 1:

// Input: x = 123
// Output: 321
// Example 2:

// Input: x = -123
// Output: -321
// Example 3:

// Input: x = 120
// Output: 21
// Example 4:

// Input: x = 0
// Output: 0
 

// Constraints:

// -231 <= x <= 231 - 1

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
        int prev = 0;

        while (num > 0) {
            int mod = num%10;
            res = res*10 + mod;
            num/=10;

            if((prev != (res - mod)/10) ||  (prev < 0 && res > 0 ) || (prev>0 && res < 0)) {
                std::cout << "Overflow";
                return 0;
            }
            
            prev = res;
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

//Method 2
// Time Complexity: O(log(x)). There are roughly \log_{10}(x) digits in x.
// Space Complexity: O(1)

// class Solution {
// public:
//     int reverse(int x) {
//         int rev = 0;
//         while (x != 0) {
//             int pop = x % 10;
//             x /= 10;
//             if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
//             if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
//             rev = rev * 10 + pop;
//         }
//         return rev;
//     }
// };
