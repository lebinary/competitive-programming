/*
 * 3567. Minimum Absolute Difference in Sliding Submatrix
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 69 ms (beats 7.6%)
 * Memory: 48.9 MB (beats 5.1%)
 * Submitted: 2025-06-06 09:22:38 UTC
 * URL: https://leetcode.com/submissions/detail/1655530916/
 */

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));

        for(int i = 0; i < m - k + 1; ++i) {
            for(int j = 0; j < n - k + 1; ++j) {
                // O(n)
                vector<int> sub;
                unordered_set<int> seen;
                for(int a = i; a < i + k; ++a) {
                    for(int b = j; b < j + k; ++b) {
                        int num = grid[a][b]; 
                        if(seen.find(num) != seen.end()) continue;
                        seen.insert(num);
                        sub.push_back(num);
                    }
                }
                if(seen.size() == 1) {
                    ans[i][j] = 0;
                    continue;
                }

                // O(nlogn)
                sort(sub.begin(), sub.end());
                int minDiff = INT_MAX;
                for(int a = 1; a < sub.size(); ++a) {
                    minDiff = min(minDiff, abs(sub[a] - sub[a - 1]));
                }

                ans[i][j] = minDiff == INT_MAX ? 0 : minDiff;
            }
        }

        return ans;
    }
};
