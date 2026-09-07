# 329. Longest Increasing Path in a Matrix
# Difficulty: Hard
# Status: Accepted
# Runtime: 282 ms (beats 5.1%)
# Memory: 22.6 MB (beats 55.2%)
# Submitted: 2024-11-14 11:43:18 UTC
# URL: https://leetcode.com/submissions/detail/1452529675/

class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        rows, cols = len(matrix), len(matrix[0])
        visited = set()
        memo = {} # (i, j) -> longest_increasing
        def dfs(r, c):
            if (r, c) in visited:
                return 0
            if (r, c) in memo:
                return memo[(r, c)]
            
            nxt_res = 0
            directions = [(1, 0), (0, 1), (-1, 0), (0, -1)]
            for dr, dc in directions:
                nxt_r, nxt_c = r + dr, c + dc

                if nxt_r in range(rows) and nxt_c in range(cols) and matrix[nxt_r][nxt_c] > matrix[r][c]:
                    nxt_res = max(nxt_res, dfs(nxt_r, nxt_c))

            memo[(r, c)] = 1 + nxt_res
            return memo[(r, c)]

        # for each starting point, explore longest path
        res = 0
        for r in range(rows):
            for c in range(cols):
                res = max(res, dfs(r, c))
        
        return res
