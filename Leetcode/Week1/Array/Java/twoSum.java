class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> elements = new HashMap<Integer, Integer>();
        int[] res = new int[2];
        for(int i = 0; i < nums.length; i++) {
            if(elements.containsKey(target - nums[i])) {
                res[0] = elements.get(target - nums[i]);
                res[1] = i;
            } else {
                elements.put(nums[i], i);
            }
        }
        return res;
    }
}