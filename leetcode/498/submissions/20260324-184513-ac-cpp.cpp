/*
 * 498. Diagonal Traverse
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 15 ms (beats 36.2%)
 * Memory: 40.3 MB (beats 6.3%)
 * Submitted: 2026-03-24 18:45:14 UTC
 * URL: https://leetcode.com/submissions/detail/1958135693/
 */

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res(m * n);
        deque<pair<int, int>> dq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        dq.push_back({0, 0});
        visited[0][0] = true;
        int dir = 1, resIdx = 0;

        while(!dq.empty()) {
            int k = dq.size();

            if(dir == 0) {
                for(int i = 0; i < k; ++i) {
                    auto [r, c] = dq.front();
                    dq.pop_front();

                    res[resIdx++] = mat[r][c];

                    if(c + 1 < n && !visited[r][c + 1]) {
                        dq.push_back({r, c + 1});
                        visited[r][c + 1] = true;
                    }
                    if(r + 1 < m && !visited[r + 1][c]) {
                        dq.push_back({r + 1, c});
                        visited[r + 1][c] = true;
                    }
                }
            } else {
                for(int i = 0; i < k; ++i) {
                    auto [r, c] = dq.back();
                    dq.pop_back();

                    res[resIdx++] = mat[r][c];

                    if(r + 1 < m && !visited[r + 1][c]) {
                        dq.push_front({r + 1, c});
                        visited[r + 1][c] = true;
                    }
                    if(c + 1 < n && !visited[r][c + 1]) {
                        dq.push_front({r, c + 1});
                        visited[r][c + 1] = true;
                    }
                }
            }

            dir = !dir;
        }

        return res;
    }
};

/**
[1, 2,  3,  4]
[5, 6,  7,  8]
[9, 10, 11, 12]

## Approach: BFS with on diagonal, reverse alternating
**/
