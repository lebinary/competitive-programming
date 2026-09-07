/*
 * 35. Search Insert Position
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 100 ms (beats 1.9%)
 * Memory: 25.2 MB (beats 100.0%)
 * Submitted: 2021-08-23 04:53:28 UTC
 * URL: https://leetcode.com/submissions/detail/542732663/
 */

public class Solution {
    public int SearchInsert(int[] nums, int target) {
        for(int i = 0; i < nums.Length; i++){
            if(target <= nums[i]){
                return i;
            }
        }
        return nums.Length;
    }
}
