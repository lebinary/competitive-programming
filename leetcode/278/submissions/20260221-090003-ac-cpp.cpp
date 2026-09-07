/*
 * 278. First Bad Version
 * Difficulty: Easy
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 7.9 MB (beats 72.0%)
 * Submitted: 2026-02-21 09:00:03 UTC
 * URL: https://leetcode.com/submissions/detail/1926155677/
 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;

        while(l < r) {
            int m = l + (r - l) / 2;

            if(isBadVersion(m)) r = m;
            else l = m + 1;
        }

        return l;
    }
};
