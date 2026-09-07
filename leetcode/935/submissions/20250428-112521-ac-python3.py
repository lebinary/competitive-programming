# 935. Knight Dialer
# Difficulty: Medium
# Status: Accepted
# Runtime: 2223 ms (beats 21.0%)
# Memory: 88.9 MB (beats 30.1%)
# Submitted: 2025-04-28 11:25:21 UTC
# URL: https://leetcode.com/submissions/detail/1620146459/

class Solution:
    def knightDialer(self, n: int) -> int:
        moves = [
            [4, 6], 
            [6, 8], 
            [7, 9], 
            [4, 8], 
            [0, 3, 9], 
            [], 
            [0, 1, 7],
            [2, 6],
            [1, 3],
            [2, 4]
        ]

        memo = {}
        def dfs(pos, n):
            if n == 0:
                return 0
            if n == 1:
                return 1
            if (pos, n) in memo:
                return memo[(pos, n)]
            
            count = 0
            for nxt_pos in moves[pos]:
                count += dfs(nxt_pos, n-1)
            
            memo[(pos, n)] = count
            return count
        
        res = 0
        for pos in range(10):
            res += dfs(pos, n)
        
        return res % (10**9 + 7)
