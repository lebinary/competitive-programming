/*
 * 42. Trapping Rain Water
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 6 ms (beats 4.6%)
 * Memory: 27.1 MB (beats 35.3%)
 * Submitted: 2026-04-02 11:27:31 UTC
 * URL: https://leetcode.com/submissions/detail/1966743724/
 */

class Solution {
  public:
    int trap(vector<int> &height) {
        int n = height.size(), res = 0;
        stack<int> mono;

        for(int i = 0; i < n; ++i) {
            while(!mono.empty() && height[i] > height[mono.top()]) {
                int top = mono.top();
                mono.pop();

                if(mono.empty()) break;

                int hei = min(height[i], height[mono.top()]) - height[top];
                int wid = i - mono.top() - 1;
                res += hei * wid;
            }

            mono.push(i);
        }

        return res;
    }
};

















/**
Ideas: Need to find the concave, ie [2,1,3]
- given position i, if we know:
    maxL = max_height[0..i]
    maxR = max_height[i..n]
    
    Then we count the water in position i to res, because it will be trapped.
        maxL >= pos[i] <= maxR
    
- Approach: use sliding window
    [l+1, r] when maxL < maxR
    [l, r-1] when maxL >= maxR

**/
