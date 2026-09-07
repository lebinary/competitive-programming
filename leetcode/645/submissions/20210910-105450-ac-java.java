/*
 * 645. Set Mismatch
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 1 ms (beats 99.9%)
 * Memory: 40.7 MB (beats 100.0%)
 * Submitted: 2021-09-10 10:54:50 UTC
 * URL: https://leetcode.com/submissions/detail/552550354/
 */

class Solution {
    public int[] findErrorNums(int[] nums) {
        int[] arr = new int[nums.length + 1];
        int dup = -1, missing = 1;
        for(int i=0; i < nums.length; i++){
            arr[nums[i]] += 1;
        }
        for(int i=1; i < arr.length; i++){
            if(arr[i] == 0){
                missing = i;
            }
            else if(arr[i] == 2){
                dup = i;
            }
        }
        return new int[] {dup, missing};
    }
}
