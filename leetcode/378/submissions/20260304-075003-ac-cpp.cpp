/*
 * 378. Kth Smallest Element in a Sorted Matrix
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 4 ms (beats 54.1%)
 * Memory: 16.9 MB (beats 95.0%)
 * Submitted: 2026-03-04 07:50:04 UTC
 * URL: https://leetcode.com/submissions/detail/1937493154/
 */

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0], r = matrix[n-1][n-1];

        while(l < r) {
            int m = l + (r - l) / 2;
            if(validator(matrix, n, k, m)) r = m;
            else l = m + 1;
        }

        return l;
    }

    bool validator(vector<vector<int>>& matrix, int n, int k, int cand) {
        int count = 0;
        
        for(int i = 0; i < n; ++i) {
            if(cand > matrix[i].back()) count += n;
            else if (cand < matrix[i][0]) continue;
            else {
                int l = 0, r = n - 1;
                while(l < r) {
                    int m = l + (r - l + 1) / 2;
                    if(matrix[i][m] <= cand) l = m;
                    else r = m - 1;
                }
                count += l + 1;
            }
        }

        return count >= k;
    }
};

/**
Approach 2:
- BS on the value
- For each row in the matrix:
    - BS to find column j s.t. matrix[i][j] <= candidate 
**/

