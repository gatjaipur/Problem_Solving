/*
Given two strings s and t, return true if s is a subsequence of t, 
or false otherwise.

A subsequence of a string is a sequence of characters that can be obtained
 by deleting some (or none) of the characters from the original string, 
 while maintaining the relative order of the remaining characters. 
 For example, "ace" is a subsequence of "abcde" while "aec" is not.
 
 Approach is Two pointer due to two strings and order is considered
 T = O(n); S = O(1)
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        
        return i == s.size();
    }
};
