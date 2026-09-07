/*
 * 85. Maximal Rectangle
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 1 ms (beats 95.0%)
 * Memory: 17.4 MB (beats 97.1%)
 * Submitted: 2026-03-22 10:29:22 UTC
 * URL: https://leetcode.com/submissions/detail/1955649606/
 */

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<int> height(n, 0);
        vector<int> left(n, 0);
        vector<int> right(n, n);

        for(int r = 0; r < m; ++r) {
            int currLeft = 0, currRight = n;

            for(int c = 0; c < n; ++c) {
                if(matrix[r][c] == '1') {
                    height[c]++;
                } else {
                    height[c] = 0;
                }
            }

            for(int c = 0; c < n; ++c) {
                if(matrix[r][c] == '1') {
                    left[c] = max(left[c], currLeft);
                } else {
                    left[c] = 0;
                    currLeft = c + 1;
                }
            }

            for(int c = n - 1; c >= 0; --c) {
                if(matrix[r][c] == '1') {
                    right[c] = min(right[c], currRight);
                } else {
                    right[c] = n;
                    currRight = c;
                }
            }

            for(int c = 0; c < n; ++c) {
                res = max(res, height[c] * (right[c] - left[c]));
            }
        }

        return res;
    }
};

/**
What state? How many?
- current position: rows * cols
- current size: 

# Approach 1:
- For each position, expand from the bottom right:
    - bottom right + r
    - bottom right + c
    - bottom right + r + c
TC: O(r * c * r * c) = 200^4 = 1.6 * 10^7 => TLE

# Approach 2:
- For each row, maintain a HISTORGRAM
    - Then solve the problem using the trick in LC84. Largest Rectangle in Histogram
TC: O(r * c)
SC: O(c)

# Approach 3:

**/
