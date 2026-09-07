# 200. Number of Islands
# Difficulty: Medium
# Status: Accepted
# Runtime: 328 ms (beats 5.0%)
# Memory: 28.8 MB (beats 13.1%)
# Submitted: 2024-12-15 07:17:08 UTC
# URL: https://leetcode.com/submissions/detail/1479212130/

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        # constants
        R, C = len(grid), len(grid[0])

        visited = set()
        count = 0

        def expand(r, c):
            if (
                r not in range(R) or
                c not in range(C) or
                grid[r][c] == "0" or
                (r, c) in visited
            ):
                return
            
            visited.add((r, c))

            # expand surroundings
            expand(r+1, c)
            expand(r-1, c)
            expand(r, c+1)
            expand(r, c-1)
        
        # counting islands
        for r in range(R):
            for c in range(C):
                if (r,c) not in visited and grid[r][c] == "1":
                    expand(r, c)
                    count += 1
        
        return count
