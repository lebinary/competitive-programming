/*
 * 223. Rectangle Area
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 10.6 MB (beats 5.2%)
 * Submitted: 2026-09-14 17:21:23 UTC
 * URL: https://leetcode.com/submissions/detail/2141825471/
 */

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int aArea = abs(ax2 - ax1) * abs(ay2 - ay1);
        int bArea = abs(bx2 - bx1) * abs(by2 - by1);
        if(ay1 >= by2 || ax1 >= bx2 || ax2 <= bx1 || ay2 <= by1) {
            return aArea + bArea;
        }

        int left = max(ax1, bx1), right = min(ax2, bx2);

        int bottom = max(ay1, by1), top = min(ay2, by2);

        int overlap = (right - left) * (top - bottom);

        return aArea + bArea - overlap; 
    }
};
