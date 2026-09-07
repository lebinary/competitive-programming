# 130. Surrounded Regions
# Difficulty: Medium
# Status: Accepted
# Runtime: 9 ms (beats 24.4%)
# Memory: 20.9 MB (beats 100.0%)
# Submitted: 2024-11-01 11:04:04 UTC
# URL: https://leetcode.com/submissions/detail/1439805404/

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # approach: 
        # . go from the board's edges 
        # . mark all the possible posiitons that can be reached as invalid
        # . the remaining are the trapped positions
        rows, cols = len(board), len(board[0])
        invalid = set()

        def dfs(r, c):
            if (
                r not in range(rows) or
                c not in range(cols) or
                board[r][c] != 'O' or
                (r, c) in invalid
            ):
                return

            invalid.add((r,c))
            dfs(r + 1, c)
            dfs(r - 1, c)
            dfs(r, c + 1)
            dfs(r, c - 1)

        for r in range(rows):
            dfs(r, 0)
            dfs(r, cols - 1)
        
        for c in range(cols):
            dfs(0, c)
            dfs(rows - 1, c)

        for r in range(1, rows-1):
            for c in range(1, cols-1):
                if board[r][c] == "O" and (r,c) not in invalid:
                    board[r][c] = "X"
