# 695. Max Area of Island
# Difficulty: Medium
# Status: Accepted
# Runtime: 43 ms (beats 5.3%)
# Memory: 19.3 MB (beats 99.0%)
# Submitted: 2024-12-15 07:35:19 UTC
# URL: https://leetcode.com/submissions/detail/1479223180/

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        R, C = len(grid), len(grid[0])

        max_area = 0
        visited = set()

        def dfs(r, c):
            if (
                r not in range(R) or
                c not in range(C) or
                (r, c) in visited or
                grid[r][c] == 0
            ):
                return 0
            
            visited.add((r,c))
            return (
                1 + 
                dfs(r+1, c) +
                dfs(r-1, c) +
                dfs(r, c+1) +
                dfs(r, c-1)
            )
        
        for r in range(R):
            for c in range(C):
                if grid[r][c] == 1 and (r, c) not in visited:
                    size = dfs(r, c)
                    max_area = max(max_area, size)
        return max_area                
