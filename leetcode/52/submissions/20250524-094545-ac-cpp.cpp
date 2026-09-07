/*
 * 52. N-Queens II
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 3 ms (beats 40.4%)
 * Memory: 9.6 MB (beats 13.0%)
 * Submitted: 2025-05-24 09:45:46 UTC
 * URL: https://leetcode.com/submissions/detail/1642873809/
 */

class Solution {
public:
    vector<vector<int>> path;
    int N;

    int totalNQueens(int n) {
        int res = 0;
        N = n;

        for(int c = 0; c < N; ++c) {
            res += dfs(0, c);
        }

        return res;
    }
private:
    bool isValid(int r, int c) {
        if(path.empty()) return true;
        for(vector<int>& prev : path) {
            int prevR = prev[0], prevC = prev[1];
            if(prevC == c || abs(r - prevR) == abs(c - prevC)) return false;
        }
        return true;
    }

    int dfs(int r, int c) {
        if(r >= N-1) {
            return 1;
        }

        path.push_back({r, c});

        int res = 0;
        for(int nextC = 0; nextC < N; nextC++) {
            if(isValid(r+1, nextC)) {
                res += dfs(r+1, nextC);
            }
        }

        path.pop_back();

        return res;
    }
};
