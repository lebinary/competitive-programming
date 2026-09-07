# 329. Longest Increasing Path in a Matrix
# Difficulty: Hard
# Status: Accepted
# Runtime: 338 ms (beats 5.1%)
# Memory: 21.6 MB (beats 87.1%)
# Submitted: 2024-11-14 12:11:24 UTC
# URL: https://leetcode.com/submissions/detail/1452546289/

class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        rows, cols = len(matrix), len(matrix[0])
        memo = {} # (i, j) -> longest_increasing
        def dfs(r, c, prev_val):
            if (
                r not in range(rows) or
                c not in range(cols) or
                matrix[r][c] <= prev_val
            ):
                return 0
            if (r, c) in memo:
                return memo[(r, c)]
            
            nxt_res = 0
            directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]
            for dr, dc in directions:
                nxt_r, nxt_c = r + dr, c + dc

                nxt_res = max(nxt_res, dfs(nxt_r, nxt_c, matrix[r][c]))

            memo[(r, c)] = 1 + nxt_res
            return memo[(r, c)]

        # for each starting point, explore longest path
        res = 0
        for r in range(rows):
            for c in range(cols):
                res = max(res, dfs(r, c, -1))
        
        return res
