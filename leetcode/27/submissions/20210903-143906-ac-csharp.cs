/*
 * 27. Remove Element
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 436 ms (beats 1.4%)
 * Memory: 30.7 MB (beats 100.0%)
 * Submitted: 2021-09-03 14:39:06 UTC
 * URL: https://leetcode.com/submissions/detail/548900705/
 */

public class Solution {
    public int RemoveElement(int[] nums, int val) {
        int writeIndex = 0;
        for(int i = 0; i < nums.Length; i++){
            if(nums[i] != val){
                nums[writeIndex] = nums[i];
                writeIndex++;
            }
        }
        return writeIndex;
    }
}
