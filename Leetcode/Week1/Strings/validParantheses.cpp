// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
 

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true
// Example 3:

// Input: s = "(]"
// Output: false
// Example 4:

// Input: s = "([)]"
// Output: false
// Example 5:

// Input: s = "{[]}"
// Output: true
 

// Constraints:

// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.

class Solution {
public:
    bool isValid(string s) {
        
        if(s.length() == 1) {
            return false;
        }
        
        stack<char> expect_char;
        bool open = false;
        
        for (int i = 0; s[i]; i++) {
            
            if(i> 0 && !expect_char.empty() && expect_char.top() == s[i]) {
                expect_char.pop();
                if (expect_char.empty()) {
                    open = false;
                }
                continue;
            } 
            else {
                
                switch (s[i]){
                
                case '(': {expect_char.push(')'); open = true;}
                break;
                case '{': {expect_char.push('}'); open = true;}
                break;
                case '[': {expect_char.push(']'); open = true;}
                break;
                default: {
                    if(open || expect_char.empty()) {
                        return false;
                    }
                }
                }
            }
        }
        
        if(expect_char.empty()) {
                    return true;
        }
        
        return false;
    }
};


//Method 2
// Time complexity : O(n) because we simply traverse the given string one character at a time and push and pop operations on a stack take O(1) time.
// Space complexity : O(n) as we push all opening brackets onto the stack and in the worst case, we will end up pushing all the brackets onto the stack. 
// class Solution {

//   // Hash table that takes care of the mappings.
//   private HashMap<Character, Character> mappings;

//   // Initialize hash map with mappings. This simply makes the code easier to read.
//   public Solution() {
//     this.mappings = new HashMap<Character, Character>();
//     this.mappings.put(')', '(');
//     this.mappings.put('}', '{');
//     this.mappings.put(']', '[');
//   }

//   public boolean isValid(String s) {

//     // Initialize a stack to be used in the algorithm.
//     Stack<Character> stack = new Stack<Character>();

//     for (int i = 0; i < s.length(); i++) {
//       char c = s.charAt(i);

//       // If the current character is a closing bracket.
//       if (this.mappings.containsKey(c)) {

//         // Get the top element of the stack. If the stack is empty, set a dummy value of '#'
//         char topElement = stack.empty() ? '#' : stack.pop();

//         // If the mapping for this bracket doesn't match the stack's top element, return false.
//         if (topElement != this.mappings.get(c)) {
//           return false;
//         }
//       } else {
//         // If it was an opening bracket, push to the stack.
//         stack.push(c);
//       }
//     }

//     // If the stack still contains elements, then it is an invalid expression.
//     return stack.isEmpty();
//   }
// }

// //Method 2 Python

// class Solution(object):
//     def isValid(self, s):
//         """
//         :type s: str
//         :rtype: bool
//         """

//         # The stack to keep track of opening brackets.
//         stack = []

//         # Hash map for keeping track of mappings. This keeps the code very clean.
//         # Also makes adding more types of parenthesis easier
//         mapping = {")": "(", "}": "{", "]": "["}

//         # For every bracket in the expression.
//         for char in s:

//             # If the character is an closing bracket
//             if char in mapping:

//                 # Pop the topmost element from the stack, if it is non empty
//                 # Otherwise assign a dummy value of '#' to the top_element variable
//                 top_element = stack.pop() if stack else '#'

//                 # The mapping for the opening bracket in our hash and the top
//                 # element of the stack don't match, return False
//                 if mapping[char] != top_element:
//                     return False
//             else:
//                 # We have an opening bracket, simply push it onto the stack.
//                 stack.append(char)

//         # In the end, if the stack is empty, then we have a valid expression.
//         # The stack won't be empty for cases like ((()
//         return not stack