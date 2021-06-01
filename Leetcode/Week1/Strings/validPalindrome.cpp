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


//Method 2 C++
// Complexity Analysis

// Time complexity : O(n), in length nn of the string.

// We need to iterate thrice through the string:

// When we filter out non-alphanumeric characters, and convert the remaining characters to lower-case.
// When we reverse the string.
// When we compare the original and the reversed strings.
// Each iteration runs linear in time (since each character operation completes in constant time). Thus, the effective run-time complexity is linear.

// Space complexity : O(n), in length n of the string. We need O(n) additional space to stored the filtered string and the reversed string.

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

//Method 2 Java

// class Solution {
//   public boolean isPalindrome(String s) {
//     StringBuilder builder = new StringBuilder();

//     for (char ch : s.toCharArray()) {
//       if (Character.isLetterOrDigit(ch)) {
//         builder.append(Character.toLowerCase(ch));
//       }
//     }

//     String filteredString = builder.toString();
//     String reversedString = builder.reverse().toString();

//     return filteredString.equals(reversedString);
//   }

//   /** An alternate solution using Java 8 Streams */
//   public boolean isPalindromeUsingStreams(String s) {
//     StringBuilder builder = new StringBuilder();

//     s.chars()
//         .filter(c -> Character.isLetterOrDigit(c))
//         .mapToObj(c -> Character.toLowerCase((char) c))
//         .forEach(builder::append);

//     return builder.toString().equals(builder.reverse().toString());
//   }
// }

//Method 2 Python

// class Solution:
//     def isPalindrome(self, s: str) -> bool:

//         filtered_chars = filter(lambda ch: ch.isalnum(), s)
//         lowercase_filtered_chars = map(lambda ch: ch.lower(), filtered_chars)

//         filtered_chars_list = list(lowercase_filtered_chars)
//         reversed_chars_list = filtered_chars_list[::-1]

//         return filtered_chars_list == reversed_chars_list


//Method 3 Two Pointers C++

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

//Method 3 Two Pointers Java

class Solution {
  public boolean isPalindrome(String s) {
    for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
      while (i < j && !Character.isLetterOrDigit(s.charAt(i))) {
        i++;
      }
      while (i < j && !Character.isLetterOrDigit(s.charAt(j))) {
        j--;
      }

      if (Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(j)))
        return false;
    }

    return true;
  }
}


//Method 3 Two Pointers Python

class Solution:
    def isPalindrome(self, s: str) -> bool:

        i, j = 0, len(s) - 1

        while i < j:
            while i < j and not s[i].isalnum():
                i += 1
            while i < j and not s[j].isalnum():
                j -= 1

            if s[i].lower() != s[j].lower():
                return False

            i += 1
            j -= 1

        return True