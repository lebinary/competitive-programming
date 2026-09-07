/*
 * 84. Largest Rectangle in Histogram
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 29 ms (beats 29.7%)
 * Memory: 81.4 MB (beats 72.2%)
 * Submitted: 2026-01-24 10:52:33 UTC
 * URL: https://leetcode.com/submissions/detail/1895235699/
 */


class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size(), best = 0;
        stack<int> stack;
        stack.push(-1);

        for (int i = 0; i < n; ++i) {
            while (stack.size() > 1 && heights[i] < heights[stack.top()]) {
                int height = heights[stack.top()];
                stack.pop();
                int width = i - stack.top() - 1;
                best = max(best, height * width);
            }
            stack.push(i);
        };

        while (stack.size() > 1) {
            int height = heights[stack.top()];
            stack.pop();
            int width = n - stack.top() - 1;
            best = max(best, height * width);
        }

        return best;
    }
};

