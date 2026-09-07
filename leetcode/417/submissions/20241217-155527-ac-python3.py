# 417. Pacific Atlantic Water Flow
# Difficulty: Medium
# Status: Accepted
# Runtime: 59 ms (beats 11.2%)
# Memory: 19.7 MB (beats 100.0%)
# Submitted: 2024-12-17 15:55:27 UTC
# URL: https://leetcode.com/submissions/detail/1481243914/

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        R, C = len(heights), len(heights[0])
        DIRS = [(1, 0), (-1, 0), (0, 1), (0, -1)]

        visited, pacific, atlantic = set(), set(), set()

        def dfs(r, c, ocean):
            ocean.add((r,c))
            visited.add((r,c))

            for dr, dc in DIRS:
                row, col = r + dr, c + dc
                if (
                    row in range(R) and
                    col in range(C) and
                    (row, col) not in visited and
                    heights[row][col] >= heights[r][c]
                ):
                    dfs(row, col, ocean)
        
        # go as high as possible from pacific
        for r in range(R):
            dfs(r, 0, pacific)
        for c in range(C):
            dfs(0, c, pacific)
        
        visited.clear()

        # go as high as possible from atlantic
        for r in range(R):
            dfs(r, C-1, atlantic)
        for c in range(C):
            dfs(R-1, c, atlantic)
        
        # intersection of pacific and atlantic is the result
        return list(pacific.intersection(atlantic))
