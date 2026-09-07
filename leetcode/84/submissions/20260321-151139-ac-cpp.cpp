/*
 * 84. Largest Rectangle in Histogram
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 15 ms (beats 86.1%)
 * Memory: 81.3 MB (beats 72.2%)
 * Submitted: 2026-03-21 15:11:39 UTC
 * URL: https://leetcode.com/submissions/detail/1954854969/
 */

class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size(), res = 0;
        stack<int> mono;
        mono.push(-1);

        for(int i = 0; i < n; ++i) {
            while(mono.size() > 1 && heights[i] < heights[mono.top()]) {
                int height = heights[mono.top()]; mono.pop();
                int width = i - mono.top() - 1;
                res = max(res, height * width);
            }
            mono.push(i);
        }

        while(mono.size() > 1) {
            int height = heights[mono.top()]; mono.pop();
            int width = n - mono.top() - 1;
            res = max(res, height * width);
        }

        return res;
    }
};

