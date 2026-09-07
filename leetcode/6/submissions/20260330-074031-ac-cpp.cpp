/*
 * 6. Zigzag Conversion
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 1 ms (beats 84.7%)
 * Memory: 14.1 MB (beats 56.9%)
 * Submitted: 2026-03-30 07:40:32 UTC
 * URL: https://leetcode.com/submissions/detail/1963592597/
 */

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        int n = s.size();
        vector<string> rows(numRows, "");

        int i = 0;
        bool isDown = false;
        for(char c : s) {
            rows[i] += c;

            if(i == 0 || i == numRows - 1) isDown = !isDown;

            if(isDown) i++;
            else i--;
        }

        string res = "";
        for(auto& row : rows) {
            res += row;
        }

        return res;
    }
};
/**
# Approach 1: Simulation
- if row = 0
    go botton in dir (1, 0)
- if row = bottom:
    go (-1, 1) to the top

Store in a matrix size [numRows][len]

TC: O(len * numRows)
SC: O(len * numRows)
**/
