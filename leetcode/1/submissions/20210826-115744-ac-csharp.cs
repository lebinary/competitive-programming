/*
 * 1. Two Sum
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 252 ms (beats 5.0%)
 * Memory: 32.9 MB (beats 100.0%)
 * Submitted: 2021-08-26 11:57:44 UTC
 * URL: https://leetcode.com/submissions/detail/544534804/
 */

public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> dic = new Dictionary<int, int>();
        for(int i = 0; i < nums.Length; i++){
            
            //find value in Dictinary
            if (dic.TryGetValue(target - nums[i], out int index))
            {
                return new int[] { index, i };
            }
            
            //Add value in Dictionary
            if (dic.ContainsKey(nums[i]) == false)
            {
                dic.Add(nums[i], i);
            }
        }
        return new int[]{};
    }
}
