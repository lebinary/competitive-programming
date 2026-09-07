# 994. Rotting Oranges
# Difficulty: Medium
# Status: Accepted
# Runtime: 5 ms (beats 22.8%)
# Memory: 17.7 MB (beats 100.0%)
# Submitted: 2024-12-17 13:53:48 UTC
# URL: https://leetcode.com/submissions/detail/1481149472/

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        R, C = len(grid), len(grid[0])
        DIRS = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        
        q = deque()
        fresh_count = 0

        for r in range(R):
            for c in range(C):
                if grid[r][c] == 2:
                    q.append((r, c))
                elif grid[r][c] == 1:
                    fresh_count += 1

        minute = 0
        while q and fresh_count > 0:
            for _ in range(len(q)):
                r, c = q.popleft()
                for dr, dc in DIRS:
                    nr, nc = r + dr, c + dc
                    if (
                        nr not in range(R) or
                        nc not in range(C) or
                        grid[nr][nc] != 1
                    ): continue

                    # make rotten
                    grid[nr][nc] = 2
                    fresh_count -= 1

                    q.append((nr, nc))
            
            minute += 1

        return minute if fresh_count == 0 else -1
