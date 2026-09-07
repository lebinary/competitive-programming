/*
 * 35. Search Insert Position
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 96 ms (beats 1.9%)
 * Memory: 25.3 MB (beats 100.0%)
 * Submitted: 2021-08-23 04:55:24 UTC
 * URL: https://leetcode.com/submissions/detail/542733391/
 */

public class Solution {
    public int SearchInsert(int[] nums, int target) {
        if(target > nums[nums.Length -1]){
            return nums.Length;
        }
        
        for(int i = 0; i < nums.Length; i++){
            if(target <= nums[i]){
                return i;
            }
        }
        
        return nums.Length;
    }
}
