# 994. Rotting Oranges
# Difficulty: Medium
# Status: Accepted
# Runtime: 11 ms (beats 5.2%)
# Memory: 16.9 MB (beats 100.0%)
# Submitted: 2024-10-30 12:07:43 UTC
# URL: https://leetcode.com/submissions/detail/1438157405/

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])

        fresh_count = [0]
        q = deque()
        visited = set()

        # udpate fresh_count and add rotten fruits to the queue
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    fresh_count[0] += 1
                elif grid[r][c] == 2:
                    q.append((r,c))
                    visited.add((r,c))

        # helper to add fresh fruit to the queue
        def addFruit(r, c):
            if (
                r in range(rows) and
                c in range(cols) and
                grid[r][c] == 1 and
                (r,c) not in visited
            ):
                q.append((r,c))
                visited.add((r,c))
                fresh_count[0] -= 1

        # bfs from the rotten fruit, making adjacent fruit rotten
        minute = 0
        while q and fresh_count[0]:
            for i in range(len(q)):
                r, c = q.popleft()

                # make it 
                grid[r][c] = 2

                # push valid adjacent fresh fruit to the queue
                addFruit(r + 1, c)
                addFruit(r - 1, c)
                addFruit(r, c + 1)
                addFruit(r, c - 1)
            minute += 1

        return minute if fresh_count[0] == 0 else -1
