/*
You are given an integer array nums consisting of n elements, 
and an integer k.

Find a contiguous subarray whose length is equal to k that has 
the maximum average value and return this value. Any answer with a
calculation error less than 10-5 will be accepted.

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000

Approach: Sliding Window
Fixed Size Window, i and i-k
*/


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currSum = 0, maxSum = 0;
        
        // Initialize currSum and maxSum to the sum of the initial k elements
        for (int i = 0; i < k; i++)
            currSum += nums[i];
        maxSum = currSum;
        
        // Start the loop from the kth element 
        // Iterate until you reach the end
        for (int i = k; i < nums.size(); i++) {
            // Subtract the left element of the window
            // Add the right element of the window
            currSum += nums[i] - nums[i - k];
            
            // Update the max
            maxSum = max(maxSum, currSum);
        }
        
        // Since the problem requires average, we return the average
        return maxSum / k;
    }
};

