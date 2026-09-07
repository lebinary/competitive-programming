# 79. Word Search
# Difficulty: Medium
# Status: Accepted
# Runtime: 8198 ms (beats 5.0%)
# Memory: 17.9 MB (beats 100.0%)
# Submitted: 2024-12-21 10:20:04 UTC
# URL: https://leetcode.com/submissions/detail/1484422070/

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        R, C = len(board), len(board[0])
        N = len(word)
        DIRS = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        visited = set()

        def dfs(r, c, i):
            if i >= N:
                return True
            if (r not in range(R) or
                c not in range(C) or
                board[r][c] != word[i] or
                (r, c) in visited
            ):
                return False
            
            visited.add((r, c))
            for dr, dc in DIRS:
                if dfs(r + dr, c + dc, i+1):
                    return True
            visited.remove((r, c))
            return False
        
        for r in range(R):
            for c in range(C):
                if dfs(r, c, 0):
                    return True
        return False
