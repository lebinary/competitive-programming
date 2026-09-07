/*
 * 137. Single Number II
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 13.4 MB (beats 66.3%)
 * Submitted: 2026-03-23 11:43:01 UTC
 * URL: https://leetcode.com/submissions/detail/1956646697/
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size(), res = 0;

        for(int b = 0; b < 32; ++b) {
            int count = 0;
            for(int i = 0; i < n; ++i) {
                count += (nums[i] >> b) & 1;
            }
            int resBit = count % 3;
            res |= (resBit << b);
        }

        return res;
    }
};

/**
# Approach: bit manipulation
- for each bit:
    for each num:
        count the bit contribution
    res's bit = count % 3
- return res
**/
