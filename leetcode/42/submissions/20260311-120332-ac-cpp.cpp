/*
 * 42. Trapping Rain Water
 * Difficulty: Hard
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 26 MB (beats 77.6%)
 * Submitted: 2026-03-11 12:03:33 UTC
 * URL: https://leetcode.com/submissions/detail/1944958928/
 */

class Solution {
  public:
    int trap(vector<int> &height) {
        int n = height.size(), res = 0;
        int l = 0, r = n - 1;
        int maxL = height[l], maxR = height[r];
        
        while(l < r) {
            if(maxL < maxR) {
                res += max(0, maxL - height[l]);
                l++;
                maxL = max(maxL, height[l]);
            } else {
                res += max(0, maxR - height[r]);
                r--;
                maxR = max(maxR, height[r]);
            }
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
