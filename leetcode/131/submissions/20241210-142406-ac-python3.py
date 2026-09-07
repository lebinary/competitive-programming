# 131. Palindrome Partitioning
# Difficulty: Medium
# Status: Accepted
# Runtime: 50 ms (beats 26.2%)
# Memory: 34.5 MB (beats 10.8%)
# Submitted: 2024-12-10 14:24:06 UTC
# URL: https://leetcode.com/submissions/detail/1475306181/

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def isPal(l, r):
            # r is not index
            if l > r: return False

            while l <= r:
                if s[l] != s[r]:
                    return False

                l += 1
                r -= 1
            return True

        res, split = [], []
        n = len(s)

        def dfs(i):
            if i >= n:
                res.append(split.copy())
                return

            for j in range(i, n):
                if isPal(i, j):
                    split.append(s[i : j+1])
                    dfs(j+1)
                    split.pop()

        dfs(0)
        return res




