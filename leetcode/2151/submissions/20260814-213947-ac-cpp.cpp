/*
 * 2151. Maximum Good People Based on Statements
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 30 ms (beats 71.4%)
 * Memory: 11.7 MB (beats 69.6%)
 * Submitted: 2026-08-14 21:39:47 UTC
 * URL: https://leetcode.com/submissions/detail/2107071927/
 */

class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size(), res = 0;
        for(int mask = 0; mask < 1 << n; ++mask) {
            if(valid(statements, n, mask)) {
                res = max(res, __builtin_popcount(mask));
            }
        }
        return res;
    }

    bool valid(vector<vector<int>>& statements, int& n, int mask) {
        for(int i = 0; i < n; ++i) {
            if(mask >> i & 1) {
                for(int j = 0; j < n; ++j) {
                    if(statements[i][j] != 2 && statements[i][j] - (mask >> j & 1) != 0) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
/**
Approach 1: Backtracking 
- for each person, theres 2 possibility: good or bad, try all possibilities, only record the one with valid
What valid means?
    if the current path say person ith is good, but the statement he made has contradiction then its invalid
    else: valid

TC: O(2^n * n^2)
SC: O(n)

Approach 2: bitmasking
The outer loop essentially try all possible configurations of good/bad for each person
TC: O(2^n * n^2)
SC: O(1)
**/
