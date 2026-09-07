/*
 * 26. Remove Duplicates from Sorted Array
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 412 ms (beats 5.3%)
 * Memory: 33.8 MB (beats 100.0%)
 * Submitted: 2021-09-01 06:03:19 UTC
 * URL: https://leetcode.com/submissions/detail/547649333/
 */

public class Solution {
    public int RemoveDuplicates(int[] nums) {
        if(nums.Length == 0){
            return 0;
        }
        int uniqueIndex = 1;
        for(int i = 1; i < nums.Length; i++){
            if(nums[i] != nums[i-1]){
                nums[uniqueIndex] = nums[i];
                uniqueIndex ++;
            }
        }
        return uniqueIndex;
    }
}
