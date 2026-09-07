# 417. Pacific Atlantic Water Flow
# Difficulty: Medium
# Status: Accepted
# Runtime: 55 ms (beats 12.2%)
# Memory: 18.3 MB (beats 100.0%)
# Submitted: 2024-10-31 10:47:42 UTC
# URL: https://leetcode.com/submissions/detail/1438979909/

class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        # better approach: 
        # . dfs from the edges
        #   . store all the set of pacific and atlantic
        # return the intersection
        rows, cols = len(heights), len(heights[0])
        pacific, atlantic = set(), set()

        # graph alg to find all positions that can reach eiher Pacific or Atlantic
        def dfs(r, c, visited, prev_height):
            if (r not in range(rows) or
                c not in range(cols) or
                (r, c) in visited or
                heights[r][c] < prev_height):
                return
            visited.add((r,c))

            directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
            for dr, dc in directions:
                nxt_r, nxt_c = r + dr, c + dc 
                dfs(nxt_r, nxt_c, visited, heights[r][c])
        
        for c in range(cols):
            # store all pos that can reach Pacific
            dfs(0, c, pacific, heights[0][c])

            # store all pos that can reach Atlantic
            dfs(rows-1, c, atlantic, heights[rows-1][c])

        for r in range(rows):
            # store all pos that can reach Pacific
            dfs(r, 0, pacific, heights[r][0])

            # store all pos that can reach Atlantic
            dfs(r, cols-1, atlantic, heights[r][cols-1])
        
        return list(pacific.intersection(atlantic))
