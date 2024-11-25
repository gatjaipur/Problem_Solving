/*
Given an array of positive integers nums and an integer k, 
return the number of subarrays where the product of all the elements 
in the subarray is strictly less than k.

For example, given the input nums = [10, 5, 2, 6], k = 100, 
the answer is 8. The subarrays with products less than k are:

[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]

Approach: Use Sliding Window
number of subarrays = right - left + 1
T = O(n), S = O(1)

*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }

        int ans = 0, left = 0, curr = 1;
        for (int right = 0; right < nums.size(); right++) {
            curr *= nums[right];
            while (curr >= k) {
                curr /= nums[left];
                left++;
            }
            
            ans += right - left + 1;
        }
        
        return ans;
    }
};