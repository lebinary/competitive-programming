/*
 * 85. Maximal Rectangle
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 3 ms (beats 91.0%)
 * Memory: 19.1 MB (beats 75.8%)
 * Submitted: 2026-03-21 15:49:37 UTC
 * URL: https://leetcode.com/submissions/detail/1954884178/
 */

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<int> heights(n, 0);

        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {
                if(matrix[r][c] == '0') heights[c] = 0;
                else heights[c]++;
            }

            stack<int> mono = {};
            mono.push(-1);

            for(int c = 0; c < n; ++c) {
                while(mono.size() > 1 && heights[c] < heights[mono.top()]) {
                    int height = heights[mono.top()]; mono.pop();
                    int width = c - mono.top() - 1;
                    res = max(res, height * width);
                }
                mono.push(c);
            }
            while(mono.size() > 1) {
                int height = heights[mono.top()]; mono.pop();
                int width = n - mono.top() - 1;
                res = max(res, height * width);
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
**/
