/*
 * 3931. Check Adjacent Digit Differences
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 3 ms (beats 11.7%)
 * Memory: 8.8 MB (beats 14.7%)
 * Submitted: 2026-07-29 07:06:28 UTC
 * URL: https://leetcode.com/submissions/detail/2085749786/
 */

class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for(int i = 1; i < s.size(); ++i) {
            if(abs((s[i] - 'a') - (s[i - 1] - 'a')) > 2) return false;
        }

        return true;
    }
};
