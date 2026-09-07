/*
 * 3576. Transform Array to All Equal Elements
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 8 ms (beats 81.6%)
 * Memory: 163.2 MB (beats 33.9%)
 * Submitted: 2025-06-09 01:14:38 UTC
 * URL: https://leetcode.com/submissions/detail/1658129770/
 */

class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        return greedy(nums, k, true) || greedy(nums, k, false);
    }

    bool greedy(vector<int> nums, int k, bool positive) {
        for(int i = 0; i < nums.size() - 1; ++i) {
            if((positive && nums[i] == -1) || !positive && nums[i] == 1) {
                if(k == 0) return false;
                nums[i] *= -1;
                nums[i + 1] *= -1;
                k --;
            }
        }

        bool lastValid = (positive && nums.back() == 1) || (!positive && nums.back() == -1);

        return lastValid;
    }
};
