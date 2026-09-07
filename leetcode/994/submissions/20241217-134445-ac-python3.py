# 994. Rotting Oranges
# Difficulty: Medium
# Status: Accepted
# Runtime: 3 ms (beats 75.1%)
# Memory: 17.9 MB (beats 100.0%)
# Submitted: 2024-12-17 13:44:45 UTC
# URL: https://leetcode.com/submissions/detail/1481142717/

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        R, C = len(grid), len(grid[0])
        DIRS = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        
        q = deque()

        fresh_count = 0
        rotten = []
        for r in range(R):
            for c in range(C):
                if grid[r][c] == 2:
                    rotten.append((r, c))
                elif grid[r][c] == 1:
                    fresh_count += 1
        q.append(rotten)

        minute = 0
        while q:
            curr_rotten = q.popleft()

            next_rotten = []
            for r, c in curr_rotten:
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

                    next_rotten.append((nr, nc))

            if len(next_rotten) > 0:
                q.append(next_rotten)
                minute += 1

        if fresh_count == 0 and minute >= 0:
            return minute
        else:
            return -1
