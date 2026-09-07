/*
 * 733. Flood Fill
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 18.3 MB (beats 43.0%)
 * Submitted: 2026-08-27 14:02:34 UTC
 * URL: https://leetcode.com/submissions/detail/2121965054/
 */

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size(), currentColor = image[sr][sc];

        if(currentColor == color) return image;

        vector<tuple<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
        queue<tuple<int, int>> q;
        q.push({sr, sc});

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            image[r][c] = color;

            for(auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if(nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if(image[nr][nc] != currentColor) continue;
                q.push({nr, nc});
            }
        }

        return image;
    }
};
