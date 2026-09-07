/*
 * 704. Binary Search
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 31.2 MB (beats 81.3%)
 * Submitted: 2026-02-21 03:21:21 UTC
 * URL: https://leetcode.com/submissions/detail/1925887666/
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0, r = n - 1;

        while(l <= r) {
            int m = l + (r - l) / 2;
            
            if(nums[m] == target) return m;
            else if(nums[m] < target) l = m + 1;
            else r = m - 1;
        }

        return -1;
    }
};
