// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

// The algorithm for myAtoi(string s) is as follows:

// Read in and ignore any leading whitespace.
// Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
// Read in next the characters until the next non-digit charcter or the end of the input is reached. The rest of the string is ignored.
// Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
// If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
// Return the integer as the final result.
// Note:

// Only the space character ' ' is considered a whitespace character.
// Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.
 

// Example 1:

// Input: s = "42"
// Output: 42
// Explanation: The underlined characters are what is read in, the caret is the current reader position.
// Step 1: "42" (no characters read because there is no leading whitespace)
//          ^
// Step 2: "42" (no characters read because there is neither a '-' nor '+')
//          ^
// Step 3: "42" ("42" is read in)
//            ^
// The parsed integer is 42.
// Since 42 is in the range [-231, 231 - 1], the final result is 42.
// Example 2:

// Input: s = "   -42"
// Output: -42
// Explanation:
// Step 1: "   -42" (leading whitespace is read and ignored)
//             ^
// Step 2: "   -42" ('-' is read, so the result should be negative)
//              ^
// Step 3: "   -42" ("42" is read in)
//                ^
// The parsed integer is -42.
// Since -42 is in the range [-231, 231 - 1], the final result is -42.
// Example 3:

// Input: s = "4193 with words"
// Output: 4193
// Explanation:
// Step 1: "4193 with words" (no characters read because there is no leading whitespace)
//          ^
// Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
//          ^
// Step 3: "4193 with words" ("4193" is read in; reading stops because the next character is a non-digit)
//              ^
// The parsed integer is 4193.
// Since 4193 is in the range [-231, 231 - 1], the final result is 4193.
// Example 4:

// Input: s = "words and 987"
// Output: 0
// Explanation:
// Step 1: "words and 987" (no characters read because there is no leading whitespace)
//          ^
// Step 2: "words and 987" (no characters read because there is neither a '-' nor '+')
//          ^
// Step 3: "words and 987" (reading stops immediately because there is a non-digit 'w')
//          ^
// The parsed integer is 0 because no digits were read.
// Since 0 is in the range [-231, 231 - 1], the final result is 0.
// Example 5:

// Input: s = "-91283472332"
// Output: -2147483648
// Explanation:
// Step 1: "-91283472332" (no characters read because there is no leading whitespace)
//          ^
// Step 2: "-91283472332" ('-' is read, so the result should be negative)
//           ^
// Step 3: "-91283472332" ("91283472332" is read in)
//                      ^
// The parsed integer is -91283472332.
// Since -91283472332 is less than the lower bound of the range [-231, 231 - 1], the final result is clamped to -231 = -2147483648.
 

// Constraints:

// 0 <= s.length <= 200
// s consists of English letters (lower-case and upper-case), digits (0-9), ' ', '+', '-', and '.'.

//Method 1

class Solution {
public:
    
    bool isDigit(char c) {
        return (c>='0' && c<= '9');    
    }
    
    int myAtoi(string s) {

        string str = s;
        size_t start = str.find_first_not_of(' ');
        
        //Leading space trimming
        if(start == string::npos) {
            str = "";
        } else {
            str = str.substr(start);
        }
        
        int sign = 1;
        int i = 0;
        
        if(str[i] == '-') {
            i++;
            sign = -1;
        } else if (str[i] == '+') {
            i++;
        }
        
        long res = 0;
        bool first_char_digit = false;
        
        for(; str[i]; i++) {
            if (isDigit(str[i])) {
                
                first_char_digit = true;
                int rem = (str[i] - '0');
                
                if((sign*res) > INT_MAX/10 || ((sign*res) == INT_MAX/10 && rem > 7)) {
                    return INT_MAX;
                } else if((sign*res) < INT_MIN/10 || ((sign*res) == INT_MIN/10 && rem < -8))                    {
                    return INT_MIN;
                }
                
                res = res*10 + (str[i] - '0');

            } else {
                if(first_char_digit) {
                    break;
                } else {
                    return 0;
                }
            }
        }
        
        
        
        if (sign*res >= INT_MAX) {
            return INT_MAX;
        }
          if (sign*res <= INT_MIN) {
            return INT_MIN;
        }
                int final = (int) res;

        return sign*final;
        
    }
};


//Method 2 Java

// public int myAtoi(String str) {
//     int index = 0, sign = 1, total = 0;
//     //1. Empty string
//     if(str.length() == 0) return 0;

//     //2. Remove Spaces
//     while(str.charAt(index) == ' ' && index < str.length())
//         index ++;

//     //3. Handle signs
//     if(str.charAt(index) == '+' || str.charAt(index) == '-'){
//         sign = str.charAt(index) == '+' ? 1 : -1;
//         index ++;
//     }
    
//     //4. Convert number and avoid overflow
//     while(index < str.length()){
//         int digit = str.charAt(index) - '0';
//         if(digit < 0 || digit > 9) break;

//         //check if total will be overflow after 10 times and add digit
//         if(Integer.MAX_VALUE/10 < total || Integer.MAX_VALUE/10 == total && Integer.MAX_VALUE %10 < digit)
//             return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;

//         total = 10 * total + digit;
//         index ++;
//     }
//     return total * sign;
// }