/*
 * 1424. Diagonal Traverse II
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 51 ms (beats 80.1%)
 * Memory: 86.6 MB (beats 71.1%)
 * Submitted: 2026-03-29 11:05:22 UTC
 * URL: https://leetcode.com/submissions/detail/1962774304/
 */

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size(), n = 0;
        for(int r = 0; r < m; ++r) n = max(n, (int)nums[r].size());
        vector<vector<int>> diags(m + n);

        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < nums[r].size(); c++) {
                diags[r + c].push_back(nums[r][c]);
            }
        }

        vector<int> res;
        for(int i = 0; i < diags.size(); ++i) {
            if(diags[i].size() == 0) continue;
            for(int j = diags[i].size() - 1; j >= 0; --j) res.push_back(diags[i][j]);
        }

        return res;
    }
};

/**
# Approach 1: Simulation
Create a subroutine to scan (1,1) direction, only stop if (r < 0 || c >= n)
for each row:
    subroutine(row, 0)
for each col:
    subroutine(r-1, col)
=> TC: O(m * max(n)) => TLE


# Approach 2: use the sum of r and c, if r1 + c1 == r2 + c2, then these 2 points in the same diag
TC: O(m * avg(n))
**/
