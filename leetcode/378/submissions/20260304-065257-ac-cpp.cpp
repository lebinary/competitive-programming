/*
 * 378. Kth Smallest Element in a Sorted Matrix
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 0 ms (beats 100.0%)
 * Memory: 17 MB (beats 79.6%)
 * Submitted: 2026-03-04 06:52:58 UTC
 * URL: https://leetcode.com/submissions/detail/1937451039/
 */

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = INT_MIN;
        for(int i = 0; i < n; i++) {
            r = max(r, matrix[i].back());
        }

        while(l < r) {
            int m = l + (r - l) / 2;
            if(validator(matrix, n, k, m)) r = m;
            else l = m + 1;
        }

        return l;
    }

    bool validator(vector<vector<int>>& matrix, int n, int k, int cand) {
        int count = 0, j = n - 1;
        for(int i = 0; i < n; ++i) {
            while(j >= 0 && matrix[i][j] > cand) j--;
            count += j + 1;
        }

        return count >= k;
    }
};

/**
Approach:
- BS on the value
- For each row in the matrix:
    - Two pointers: shrink the r pointer while num > candidate
**/

