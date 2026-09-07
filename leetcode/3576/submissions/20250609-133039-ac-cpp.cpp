/*
 * 3576. Transform Array to All Equal Elements
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 9 ms (beats 70.9%)
 * Memory: 163.4 MB (beats 19.6%)
 * Submitted: 2025-06-09 13:30:39 UTC
 * URL: https://leetcode.com/submissions/detail/1658667111/
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
