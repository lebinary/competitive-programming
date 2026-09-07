/*
 * 311. Sparse Matrix Multiplication
 * Difficulty: Medium
 * Status: Accepted
 * Runtime: 3 ms (beats 37.8%)
 * Memory: 12.3 MB (beats 69.2%)
 * Submitted: 2026-03-23 14:36:51 UTC
 * URL: https://leetcode.com/submissions/detail/1956787481/
 */

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size(), k = mat1[0].size(), n = mat2[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        unordered_map<int, int> row1, col2;
        
        for(int r1 = 0; r1 < m; r1++) {
            row1.clear();
            for(int c1 = 0; c1 < k; c1++) {
                if(mat1[r1][c1] != 0) row1[c1] = mat1[r1][c1];
            }

            for(int c2 = 0; c2 < n; c2++) {
                col2.clear();
                for(int r2 = 0; r2 < k; r2++) {
                    if(mat2[r2][c2] != 0) col2[r2] = mat2[r2][c2];
                }

                if(row1.size() < col2.size()) swap(row1, col2);
                for(auto it = col2.begin(); it != col2.end(); ++it) {
                    if(row1[it->first]) res[r1][c2] += row1[it->first] * it->second;
                }
            };
        }

        return res;
    }
};

/**
# Approach: reduce to vector multiplication
- For each row in mat1:
    For each col in mat2:
        res += vectorMultiply(row, col)

def vectorMultiply(row, col):
    map1 = condense(row)
    map2 = condense(col)
    
    if(map1.size > map2.size) swap
    for it : map1:
        res += map2[it] if it in map2 
    return res
**/
