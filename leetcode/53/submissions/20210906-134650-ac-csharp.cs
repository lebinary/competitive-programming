/*
 * 53. Maximum Subarray
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 84 ms (beats 5.5%)
 * Memory: 26 MB (beats 100.0%)
 * Submitted: 2021-09-06 13:46:50 UTC
 * URL: https://leetcode.com/submissions/detail/550376080/
 */

public class Solution {
    public int MaxSubArray(int[] nums) {
        if(nums.Length == 1) return nums[0];
        
        int maxSoFar = nums[0];
        int maxEndHere = 0;
        
        for(int i = 0; i < nums.Length; i++){
            maxEndHere += nums[i];
            if(maxEndHere > maxSoFar){
                maxSoFar = maxEndHere;
            }
            if(maxEndHere < 0){
                maxEndHere = 0;
            }
        }
        
        return maxSoFar;
    }
}
