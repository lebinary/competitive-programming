/*
 * 1944. Number of Visible People in a Queue
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 17 ms (beats 39.3%)
 * Memory: 88.6 MB (beats 61.1%)
 * Submitted: 2026-01-02 13:39:13 UTC
 * URL: https://leetcode.com/submissions/detail/1872076015/
 */

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> res(n, 0);
        stack<int> stack;
        stack.push(heights[n-1]);

        for(int i = n - 2; i >= 0; --i) {
            while(!stack.empty() && heights[i] > stack.top()) {
                stack.pop();
                res[i]++;
            }

            if(!stack.empty()) res[i]++;
            stack.push(heights[i]);
        }

        return res;
    }
};
