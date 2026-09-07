# 994. Rotting Oranges
# Difficulty: Medium
# Status: Accepted
# Runtime: 11 ms (beats 14.3%)
# Memory: 12.4 MB (beats 61.0%)
# Submitted: 2026-08-19 19:52:03 UTC
# URL: https://leetcode.com/submissions/detail/2113197375/

class Solution(object):
    def orangesRotting(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        dirs = [(0, 1), (1, 0), (-1, 0), (0, -1)]
        visited = set()
        fresh = 0
        q = deque()
        
        for r in range(m):
            for c in range(n):
                if grid[r][c] == 1:
                    fresh += 1

                if grid[r][c] == 2:
                    for dr, dc in dirs:
                        nr, nc = r + dr, c + dc
                        
                        if nr < 0 or nr >= m or nc < 0 or nc >= n:
                            continue
                        if (nr, nc) in visited:
                            continue
                        if grid[nr][nc] != 1:
                            continue

                        q.append((nr, nc))
                        visited.add((nr, nc))
                               
        minutes = 0
        while q:
            k = len(q)
            
            for _ in range(k):
                r, c = q.popleft()
 
                grid[r][c] = 2
                fresh -= 1

                for dr, dc in dirs:
                    nr, nc = r + dr, c + dc

                    if nr < 0 or nr >= m or nc < 0 or nc >= n:
                        continue
                    if (nr, nc) in visited:
                        continue
                    if grid[nr][nc] != 1:
                        continue

                    q.append((nr, nc))
                    visited.add((nr, nc))

            minutes += 1
        
        return minutes if fresh == 0 else -1
