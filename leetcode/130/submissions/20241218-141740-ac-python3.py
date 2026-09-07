# 130. Surrounded Regions
# Difficulty: Medium
# Status: Accepted
# Runtime: 8 ms (beats 28.7%)
# Memory: 21.7 MB (beats 100.0%)
# Submitted: 2024-12-18 14:17:40 UTC
# URL: https://leetcode.com/submissions/detail/1482076192/

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        R, C = len(board), len(board[0])
        DIRS = [(1,0), (-1,0), (0,1), (0,-1)]

        def dfs(r, c):
            if (
                r not in range(R) or
                c not in range(C) or
                board[r][c] != "O"
            ):
                return
            
            board[r][c] = "I"
            for dr, dc in DIRS:
                dfs(r + dr, c + dc)
        
        # Mark all reachable cells from edges as invalid
        for r in range(R):
            if board[r][0] == "O":
                dfs(r, 0)
            if board[r][C-1] == "O":
                dfs(r, C-1)
        for c in range(C):
            if board[0][c] == "O":
                dfs(0, c)
            if board[R-1][c] == "O":
                dfs(R-1, c)

        # Anything that are not reachable, is trapped
        for r in range(R):
            for c in range(C):
                if board[r][c] == "O":
                    board[r][c] = "X"
                if board[r][c] == "I":
                    board[r][c] = "O"
