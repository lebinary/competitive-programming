/*
 * 6. Zigzag Conversion
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 305 ms (beats 5.1%)
 * Memory: 43.5 MB (beats 5.0%)
 * Submitted: 2026-03-29 15:16:25 UTC
 * URL: https://leetcode.com/submissions/detail/1962969839/
 */

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int n = s.size();
        vector<vector<char>> res(numRows, vector<char>(n, ' '));
        vector<vector<int>> dirs = {{1, 0}, {-1, 1}};

        int r = 0, c = 0, i = 0, d = 0;
        while(r < numRows && c < n && i < n) {
            res[r][c] = s[i++];

            if(r == 0) d = 0;
            else if(r == numRows - 1) d = 1;

            r += dirs[d][0];
            c += dirs[d][1];
        }

        string resStr(n, ' ');
        i = 0;
        for(int r = 0; r < numRows; ++r) {
            for(int c = 0; c < n; ++c) {
                if(res[r][c] != ' ') {
                    cout << res[r][c] << "|";
                    resStr[i++] = res[r][c];
                }
            }
            cout << endl;
        }

        return resStr;
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
