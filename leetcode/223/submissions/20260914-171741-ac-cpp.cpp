/*
 * 223. Rectangle Area
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 11.3 MB (beats 5.2%)
 * Submitted: 2026-09-14 17:17:41 UTC
 * URL: https://leetcode.com/submissions/detail/2141821160/
 */

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int aArea = abs(ax2 - ax1) * abs(ay2 - ay1);
        int bArea = abs(bx2 - bx1) * abs(by2 - by1);
        if(ay1 >= by2 || ax1 >= bx2 || ax2 <= bx1 || ay2 <= by1) {
            return aArea + bArea;
        }

        vector<int> xs = {ax1, ax2, bx1, bx2};
        vector<int> ys = {ay1, ay2, by1, by2};
        sort(xs.begin(), xs.end());
        sort(ys.begin(), ys.end());
        
        int overlap = (xs[2] - xs[1]) * (ys[2] - ys[1]);

        return aArea + bArea - overlap; 
    }
};
