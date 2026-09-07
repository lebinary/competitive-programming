/*
 * 51. N-Queens
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 88 ms (beats 5.7%)
 * Memory: 30.4 MB (beats 5.1%)
 * Submitted: 2025-12-27 09:50:07 UTC
 * URL: https://leetcode.com/submissions/detail/1866526233/
 */

class Solution {
  public:
    vector<vector<string>> res;

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> positions;
        dfs(n, 0, positions);
        return res;
    }

    vector<string> convert(int n, vector<vector<int>> &positions) {
        vector<string> table = vector<string>(n, string(n, '.'));
        for (vector<int> pos : positions) {
            int x = pos[0], y = pos[1];
            table[x][y] = 'Q';
        }
        return table;
    }

    bool invalid(vector<int> &posA, vector<int> &posB) {
        int xa = posA[0], ya = posA[1], xb = posB[0], yb = posB[1];
        return (abs(xa - xb) == abs(ya - yb) || ya == yb);
    }

    void dfs(int n, int i, vector<vector<int>> &positions) {
        if (i >= n) {
            vector<string> table = convert(n, positions);
            res.push_back(table);
            return;
        }

        for (int j = 0; j < n; ++j) {
            vector<int> curr = {i, j};

            if (any_of(positions.begin(), positions.end(), [&](vector<int> prev) { return invalid(curr, prev); })) {
                continue;
            }

            positions.push_back({i, j});
            dfs(n, i + 1, positions);
            positions.pop_back();
        }
    }
};
