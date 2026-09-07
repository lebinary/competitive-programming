# 695. Max Area of Island
# Difficulty: Medium
# Status: Accepted
# Runtime: 50 ms (beats 5.3%)
# Memory: 18.6 MB (beats 100.0%)
# Submitted: 2024-10-28 10:12:15 UTC
# URL: https://leetcode.com/submissions/detail/1436090013/

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        visited = set()
        res = 0

        def dfs(r, c):
            if r not in range(rows) or\
                c not in range(cols) or\
                grid[r][c] == 0 or\
                (r,c) in visited:
                return 0
            
            # mark as visited
            visited.add((r, c))

            # calculate the size of island
            size = 1
            directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
            for dr, dc in directions:
                adjacent_r, adjacent_c = r + dr, c + dc
                if adjacent_r in range(rows) and\
                    adjacent_c in range(cols) and\
                    grid[adjacent_r][adjacent_c] == 1 and\
                    (adjacent_r, adjacent_c) not in visited:
                    size += dfs(adjacent_r, adjacent_c)

            return size

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1 and (r,c) not in visited:
                    # explore the island
                    size = dfs(r, c)
                    res = max(res, size)

        return res
