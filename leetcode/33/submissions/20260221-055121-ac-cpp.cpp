/*
 * 33. Search in Rotated Sorted Array
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 15.2 MB (beats 37.0%)
 * Submitted: 2026-02-21 05:51:21 UTC
 * URL: https://leetcode.com/submissions/detail/1925997274/
 */


class Solution {
  public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(nums[m] == target) return m;
            
            if((nums[m] >= nums[0] && target < nums[0]) 
            || nums[m] < nums[0] && target >= nums[0]) {
                if(nums[m] < target) {
                    r = m - 1;
                } else l = m + 1;
            } else {
                if(nums[m] < target) {
                    l = m + 1;
                } else r = m - 1;
            }
        }

        return -1;
    }
};
