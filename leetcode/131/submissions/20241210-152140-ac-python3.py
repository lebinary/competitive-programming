# 131. Palindrome Partitioning
# Difficulty: Medium
# Status: Accepted
# Runtime: 48 ms (beats 29.5%)
# Memory: 34.5 MB (beats 10.8%)
# Submitted: 2024-12-10 15:21:40 UTC
# URL: https://leetcode.com/submissions/detail/1475351197/

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def isPal(l, r):
            while l < r:
                if s[l] != s[r]:
                    return False
                l += 1
                r -= 1

            return True
        
        res, sub = [], []
        N = len(s)

        def dfs(i, j):
            if i >= N and j >= N:
                res.append(sub.copy())
                return
            if j >= N:
                return
            
            if isPal(i, j):
                sub.append(s[i: j+1])
                dfs(j+1, j+1)
                sub.pop()

            dfs(i, j+1)

        dfs(0, 0)
        return res




