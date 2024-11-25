/*
You are given a binary string s (a string containing only "0" and "1"). 
You may choose up to one "0" and flip it to a "1". 
What is the length of the longest substring achievable that 
contains only "1"


Approach: Use Sliding Window
length of window = right - left + 1
T = O(n), S = O(1)
*/

int findLength(string s) {
    // curr is the current number of zeros in the window
    int left = 0, curr = 0, ans = 0;
    for (int right = 0; right < s.size(); right++) {
        if (s[right] == '0') {
            curr++;
        }
        
        while (curr > 1) {
            if (s[left] == '0') {
                curr--;
            }
            left++;
        }
        
        ans = max(ans, right - left + 1);
    }
    
    return ans;
}