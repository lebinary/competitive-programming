/*
 * 540. Single Element in a Sorted Array
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 26 MB (beats 94.6%)
 * Submitted: 2026-02-21 10:05:20 UTC
 * URL: https://leetcode.com/submissions/detail/1926210535/
 */

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        int l = 0, r = n - 1;

        while(l <= r) {
            int m = l + (r - l) / 2;
            int leftVal = m - 1 < 0 ? -1 : nums[m - 1];
            int rightval = m + 1 >= n ? -1 : nums[m + 1];

            if(nums[m] != leftVal && nums[m] != rightval) return nums[m];
  
            int leftSize = nums[m] != leftVal ? m : m - 1;  
            if(leftSize % 2 == 0) l = m + 1;
            else r = m - 1;
        }

        return -1;
    }
};
