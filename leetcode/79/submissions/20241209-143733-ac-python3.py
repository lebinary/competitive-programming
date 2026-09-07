# 79. Word Search
# Difficulty: Medium
# Status: Accepted
# Runtime: 8458 ms (beats 5.0%)
# Memory: 17.7 MB (beats 100.0%)
# Submitted: 2024-12-09 14:37:33 UTC
# URL: https://leetcode.com/submissions/detail/1474405920/

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        ROWS, COLS = len(board), len(board[0])
        seen = set()

        def dfs(i, r, c):
            if i >= len(word):
                return True
            if (
                r not in range(0, ROWS) or
                c not in range(0, COLS) or
                (r, c) in seen or
                board[r][c] != word[i]
            ):
                return False
            
            seen.add((r, c))
            res = (
                dfs(i+1, r+1, c) or
                dfs(i+1, r-1, c) or
                dfs(i+1, r, c+1) or
                dfs(i+1, r, c-1)
            )
            seen.remove((r, c))

            return res
        
        for r in range(ROWS):
            for c in range(COLS):
                if dfs(0, r, c):
                    return True
        return False
