# 115. Distinct Subsequences
# Difficulty: Hard
# Status: Accepted
# Runtime: 971 ms (beats 5.1%)
# Memory: 247.1 MB (beats 7.5%)
# Submitted: 2024-11-16 10:21:53 UTC
# URL: https://leetcode.com/submissions/detail/1454224829/

class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        # top-down
        memo = {} # (i, j) -> ways

        def dfs(i, j):
            if j >= len(t):
                return 1
            if i >= len(s):
                return 0
            if (i, j) in memo:
                return memo[(i, j)]

            res = dfs(i + 1, j)
            if s[i] == t[j]:
                res += dfs(i + 1, j + 1)

            memo[(i, j)] = res
            return memo[(i, j)]

        return dfs(0, 0)
