/*
Example 1: Given an array of positive integers nums and an integer k, 
find the length of the longest subarray whose 
sum is less than or equal to k.

Approach: Use Sliding Window
length of window = right - left + 1
T = O(n), S = O(1)

*/

int findLength(vector<int>& nums, int k) {
    // curr is the current sum of the window
    int left = 0, curr = 0, ans = 0;
    for (int right = 0; right < nums.size(); right++) {
        curr += nums[right];
        while (curr > k) {
            curr -= nums[left];
            left++;
        }
        
        ans = max(ans, right - left + 1);
    }
    
    return ans;
}