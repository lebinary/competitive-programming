# 200. Number of Islands
# Difficulty: Medium
# Status: Accepted
# Runtime: 319 ms (beats 5.0%)
# Memory: 24.2 MB (beats 29.2%)
# Submitted: 2024-10-27 07:26:02 UTC
# URL: https://leetcode.com/submissions/detail/1435018309/

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0

        rows, cols = len(grid), len(grid[0])
        visited = set()
        islands = 0

        def bfs(r, c):
            q = deque()
            q.append((r,c))

            while q:
                curr_r, curr_c = q.popleft()

                directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
                for dr, dc in directions:
                    r, c = curr_r + dr, curr_c + dc
                    if r in range(rows) and \
                       c in range(cols) and \
                       grid[r][c] == "1" and \
                       (r, c) not in visited:
                        q.append((r, c))
                        visited.add((r, c))

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == "1" and (r, c) not in visited:
                    # explore the island (can be bfs or dfs)
                    bfs(r, c)
                    islands += 1
        
        return islands
