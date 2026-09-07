/*
 * 283. Move Zeroes
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 42.5 MB (beats 100.0%)
 * Submitted: 2021-09-11 05:23:25 UTC
 * URL: https://leetcode.com/submissions/detail/552928623/
 */

class Solution {
    public void moveZeroes(int[] nums) {
        int lastNonZeroIndex = 0;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] != 0){
                nums[lastNonZeroIndex] = nums[i];
                lastNonZeroIndex++;
            }
        }
        
        for(int i = lastNonZeroIndex; i < nums.length; i++){
            nums[i] = 0;
        }
    }
}
