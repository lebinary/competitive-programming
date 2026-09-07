# 935. Knight Dialer
# Difficulty: Medium
# Status: Accepted
# Runtime: 887 ms (beats 51.1%)
# Memory: 37.6 MB (beats 39.9%)
# Submitted: 2025-04-28 11:50:45 UTC
# URL: https://leetcode.com/submissions/detail/1620160955/

class Solution:
    def knightDialer(self, n: int) -> int:
        if n == 0:
            return 0

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
        
        dp = [[0] * 10 for _ in range(n)]
        for j in range(10):
            dp[0][j] = 1

        for i in range(1, n):
            for j in range(10):
                for pre_j in moves[j]:
                    dp[i][j] += dp[i-1][pre_j]
        
        return sum(dp[-1]) % (10**9 + 7)
