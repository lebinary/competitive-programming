/*
 * 1664. Ways to Make a Fair Array
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 16 ms (beats 12.5%)
 * Memory: 107.5 MB (beats 31.0%)
 * Submitted: 2026-03-30 12:52:08 UTC
 * URL: https://leetcode.com/submissions/detail/1963822432/
 */

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<int> prefixOdds(n, 0);
        vector<int> prefixEvens(n, 0);

        int odds = 0, evens = 0;
        for(int i = 0; i < n; ++i) {
            if(i & 1) odds += nums[i];
            else evens += nums[i];
            
            prefixOdds[i] = odds;
            prefixEvens[i] = evens;
        }

        odds = 0, evens = 0;
        for(int i = n - 1; i >= 0; --i) {
            int preOdds = i - 1 >= 0 ? prefixOdds[i - 1] : 0;
            int preEvens = i - 1 >= 0 ? prefixEvens[i - 1] : 0;

            if(preOdds + evens == preEvens + odds) res++;

            if(i & 1) odds += nums[i];
            else evens += nums[i];
        }

        return res;
    }
};
/**
# Analysis:
- If remove an index, every index after it changes (odd -> even, even -> odd)

# Approach: Prefix Sum + Iterate backward
- Build prefixSum arrays for odd and even
- From right to left, keep track current odds and evens
    At each index (that is going to be remove), check:
        prefixEven + odds == prefixOdds + evens
**/
