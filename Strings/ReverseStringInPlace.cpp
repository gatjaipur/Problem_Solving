/*
Write a function that reverses a string. 
The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) 
extra memory.

Approach 1: using a temp variable and two pointer 
T = O(n), S = O(1)
*/

void reverseString(vector<char>& s) {
    int left = 0;
    int right = s.size() - 1;
    
    while(left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}