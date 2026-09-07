/*
 * 1861. Rotating the Box
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 56.7 MB (beats 68.4%)
 * Submitted: 2026-08-08 11:38:14 UTC
 * URL: https://leetcode.com/submissions/detail/2099038005/
 */

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        vector<vector<char>> res(n, vector<char>(m, '.'));
        
        for(int r = 0; r < m; ++r) {
            int groundIdx = n - 1;
            for(int c = n - 1; c >= 0; --c) {
                if(boxGrid[r][c] == '*') {
                    res[c][m - r - 1] = '*';
                    groundIdx = c - 1;
                } else if(boxGrid[r][c] == '#') {
                    res[groundIdx][m - r - 1] = '#';
                    groundIdx--;
                } 
            }
        }

        return res;
    }
};
