# 79. Word Search
# Difficulty: Medium
# Status: Accepted
# Runtime: 4025 ms (beats 43.7%)
# Memory: 16.7 MB (beats 100.0%)
# Submitted: 2024-09-26 12:50:14 UTC
# URL: https://leetcode.com/submissions/detail/1402900042/

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        M, N = len(board), len(board[0])
        path = set()

        def dfs(r, c, i):
            if i >= len(word):
                return True
            if ((r, c) in path or           # path visited
                r >= M or c >= N or         # exceed range
                r < 0 or c < 0 or
                board[r][c] != word[i]):    # word doesn't exist
                return False
            
            path.add((r, c))

            # check next charater in adjacent positions
            res =  (dfs(r + 1, c, i + 1) or
                    dfs(r - 1, c, i + 1) or
                    dfs(r, c + 1, i + 1) or
                    dfs(r, c - 1, i + 1))
            
            path.remove((r, c))

            return res

        for i in range(M):
            for j in range(N):
                if dfs(i, j, 0):
                    return True
        
        return False
