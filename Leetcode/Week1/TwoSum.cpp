// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Output: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]
 

// Constraints:

// 2 <= nums.length <= 103
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Only one valid answer exists.

//Method 1 Using Map

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> result;
//         map<int, int> count;
        
//         for(int i = 0; i<nums.size(); i++) {
//             map<int, int>::iterator it = count.find(target - nums[i]);
//             if(it != count.end()) {
//                 result.push_back(count[target - nums[i]]);
//                 result.push_back(i);
//                 break;
//             }
            
//         std::pair<map<int, int>::iterator, bool> ret = count.insert({nums[i], i});
//             if(!ret.second) {
//                 count[nums[i]] = i;
//             }
//         }
        
//         return result;
//     }
// };


// Method 2 Using Hashtable
// Time complexity : O(n). We traverse the list containing nn elements exactly twice. Since the hash table reduces the look up time to O(1), the time complexity is O(n).

// Space complexity : O(n). The extra space required depends on the number of items stored in the hash table, which stores exactly nn elements.

class Solution {
    public int[] twoSum(int[] nums, int target) {
      Hashtable<Integer, Integer> hashTable = new Hashtable<Integer, Integer>();
      int i = 0;
      while ((i < nums.length) && (hashTable.get(nums[i]) == null)) {      
        hashTable.put(target - nums[i], i);
        i++;
      }
      if (i < nums.length) {
        return new int[]{hashTable.get(nums[i]),i};
      } 
      return null;       
    }
}

// OR 

// public int[] twoSum(int[] nums, int target) {
//     Map<Integer, Integer> map = new HashMap<>();
//     for (int i = 0; i < nums.length; i++) {
//         map.put(nums[i], i);
//     }
//     for (int i = 0; i < nums.length; i++) {
//         int complement = target - nums[i];
//         if (map.containsKey(complement) && map.get(complement) != i) {
//             return new int[] { i, map.get(complement) };
//         }
//     }
//     throw new IllegalArgumentException("No two sum solution");
// }

// OR 

// public int[] twoSum(int[] nums, int target) {
//     Map<Integer, Integer> map = new HashMap<>();
//     for (int i = 0; i < nums.length; i++) {
//         int complement = target - nums[i];
//         if (map.containsKey(complement)) {
//             return new int[] { map.get(complement), i };
//         }
//         map.put(nums[i], i);
//     }
//     throw new IllegalArgumentException("No two sum solution");
// }


// Method 3 Brute force
// Time complexity : O(n^2)
// For each element, we try to find its complement by looping through the rest of array which takes O(n)
// Space complexity : O(1)

// public int[] twoSum(int[] nums, int target) {
//     for (int i = 0; i < nums.length; i++) {
//         for (int j = i + 1; j < nums.length; j++) {
//             if (nums[j] == target - nums[i]) {
//                 return new int[] { i, j };
//             }
//         }
//     }
//     throw new IllegalArgumentException("No two sum solution");
// }
