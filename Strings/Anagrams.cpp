/*
Given two strings s and t, return true if the two strings are anagrams of 
each other, otherwise return false.

An anagram is a string that contains the exact same characters as 
another string, but the order of the characters can be different

Input: s = "racecar", t = "carrace"

Output: true


*/
/*
//Method 1 Use Sorting, T = O(nlogn) + O(mlogm), S = O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

//Method 2: Hash Table T = O(n+m), S = O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> countS;
        unordered_map<char, int> countT;
        for (int i = 0; i < s.length(); i++) {
            countS[s[i]]++;
            countT[t[i]]++;
        }
        return countS == countT;
    }
};

*/

//Method 3 Optimal T = O(n+m), S = O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> count(26, 0);
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int val : count) {
            if (val != 0) {
                return false;
            }
        }
        return true;
    }
};
