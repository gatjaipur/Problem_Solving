//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target
//Input: nums = [2,7,11,15], target = 9
//Output: [0,1]

//Method 1 Using Map

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;
        std::unordered_map<int, int> existNum;
        std::unordered_map<int, int>::iterator itr;

        for (int i = 0; i < nums.size() ; i++) {
          int diff = target - nums[i];
          itr = existNum.find(diff);
          if (itr != existNum.end()) {
              output.push_back(i);
              output.push_back(itr->second);
              break;
          }
            existNum.insert({nums[i], i});
        }
        return output;
    }
};


// Method 2 Using Hashtable

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


// Method 3 Brute force

public int[] twoSum(int[] nums, int target) {
    for (int i = 0; i < nums.length; i++) {
        for (int j = i + 1; j < nums.length; j++) {
            if (nums[j] == target - nums[i]) {
                return new int[] { i, j };
            }
        }
    }
    throw new IllegalArgumentException("No two sum solution");
}
