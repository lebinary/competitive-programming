# 200. Number of Islands
# Difficulty: Medium
# Status: Accepted
# Runtime: 304 ms (beats 5.0%)
# Memory: 24.2 MB (beats 29.2%)
# Submitted: 2024-10-27 07:26:57 UTC
# URL: https://leetcode.com/submissions/detail/1435018916/

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0

        rows, cols = len(grid), len(grid[0])
        visited = set()
        islands = 0

        def dfs(r, c):
            stack = []
            stack.append((r,c))

            while stack:
                curr_r, curr_c = stack.pop()

                directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
                for dr, dc in directions:
                    r, c = curr_r + dr, curr_c + dc
                    if r in range(rows) and \
                       c in range(cols) and \
                       grid[r][c] == "1" and \
                       (r, c) not in visited:
                        stack.append((r, c))
                        visited.add((r, c))

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == "1" and (r, c) not in visited:
                    # explore the island (can be bfs or dfs)
                    dfs(r, c)
                    islands += 1
        
        return islands
