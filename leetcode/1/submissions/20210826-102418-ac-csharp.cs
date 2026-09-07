/*
 * 1. Two Sum
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 510 ms (beats 5.0%)
 * Memory: 32.2 MB (beats 100.0%)
 * Submitted: 2021-08-26 10:24:18 UTC
 * URL: https://leetcode.com/submissions/detail/544506086/
 */

public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        for(int i = 0; i < nums.Length; i++){
            for(int j = i+1; j < nums.Length; j++){
                if(nums[i] + nums[j] == target){
                    return new int[]{i, j};
                }
            }
        }
        return new int[]{};
    }
}
