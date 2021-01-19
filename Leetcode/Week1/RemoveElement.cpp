//Given an array nums and a value val, remove all instances of that value in-place and return the new length.


// Method 1 Using STL


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
return std::distance(nums.begin(), std::remove(nums.begin(), nums.end(), val));

    }
};


//Method 2

public int removeElement(int[] nums, int val) {
    int i = 0;
    for (int j = 0; j < nums.length; j++) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}


//Method 3

public int removeElement(int[] nums, int val) {
    int i = 0;
    int n = nums.length;
    while (i < n) {
        if (nums[i] == val) {
            nums[i] = nums[n - 1];
            // reduce array size by one
            n--;
        } else {
            i++;
        }
    }
    return n;
}
