// Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

 

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
 

// Constraints:

// 1 <= s.length <= 2 * 105
// s consists only of printable ASCII characters.

//Method 1

// class Solution {
// public:
    
    
//     bool isAplphabetNumeric(char c) {
//         return ( (c >= 'a' && c <= 'z') || ( c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') );
//     }
    
//     string reverse(string s) {
//         int n = s.length();
        
//         int begin = 0;
//         int end = n -1;
        
//         while(begin < end){
//             char temp = s[begin];
//             s[begin] = s[end];
//             s[end] = temp;
//             begin++;
//             end--;
//         }
        
//         return s;
//     }
    
//     bool isPal(string s) {
//         return (s.compare(reverse(s)) == 0);
//     }
    
//     bool isPalindrome(string s) {
//         std::transform(s.begin(), s.end(), s.begin(), ::tolower);
//         string temp;
//         for (int i = 0; s[i]; i++) {
//             if(isAplphabetNumeric(s[i])) {
//                 temp+= s[i];
//             }
//         }
                    
//         return isPal(temp);

//     }
// };


//Method 2
// Complexity Analysis

// Time complexity : O(n), in length nn of the string.

// We need to iterate thrice through the string:

// When we filter out non-alphanumeric characters, and convert the remaining characters to lower-case.
// When we reverse the string.
// When we compare the original and the reversed strings.
// Each iteration runs linear in time (since each character operation completes in constant time). Thus, the effective run-time complexity is linear.

// Space complexity : O(n), in length nn of the string. We need O(n) additional space to stored the filtered string and the reversed string.
// class Solution {
//  public:
//   bool isPalindrome(string s) {
//     string filtered_string, reversed_string;

//     for (auto ch : s) {
//       if (isalnum(ch))
//         filtered_string += tolower(ch);
//     }

//     reversed_string.resize(filtered_string.size());
//     reverse_copy(filtered_string.begin(), filtered_string.end(),
//                  reversed_string.begin());

//     return filtered_string == reversed_string;
//   }
// };


//Method 3 Two Pointers

// Time complexity : O(n), in length nn of the string. We traverse over each character at-most once, until the two pointers meet in the middle, or when we break and return early.

// Space complexity : O(1). No extra space required, at all.

class Solution {
 public:
  bool isPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
      while (i < j && !isalnum(s[i]))
        i++;
      while (i < j && !isalnum(s[j]))
        j--;

      if (tolower(s[i]) != tolower(s[j]))
        return false;
    }

    return true;
  }
};