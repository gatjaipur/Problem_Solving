/*
Squares of a Sorted Array
Given an integer array nums sorted in non-decreasing order, 
return an array of the squares of each number sorted in 
non-decreasing order.

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].


Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

Approach 1: Square each number in array and then sort. T = O(nlogn)
Approach 2: Two Pointer as sorted array, compare squares of extreme ends 
for greater number and then fill it in last pos of result
T = O(n) ; S = O(1)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i =0;i<nums.size();i++){
            nums[i] = nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};


*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       
                
        vector<int> ans(nums.size());
     
        int start = 0, end = nums.size() - 1;
        int i = end; // insert position.
        while (start <= end) { // <  or <=  ?   be careful about ==
            int pow1 = nums[start] * nums[start];
            int pow2 = nums[end] * nums[end];
            if (pow1 > pow2) {
                ans[i--] = pow1;
                start++;
            } else {
                ans[i--] = pow2;
                end--;
            }
        }
        return ans;

        }
};

