# 10. Regular Expression Matching
# Difficulty: Hard
# Status: Accepted
# Runtime: 7 ms (beats 57.6%)
# Memory: 16.8 MB (beats 100.0%)
# Submitted: 2024-11-22 11:06:22 UTC
# URL: https://leetcode.com/submissions/detail/1459949989/

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m = len(s)
        n = len(p)
        memo = {} # (i,j) -> is_matched

        def dfs(i, j):
            if j >= n:
                return i >= m
            if (i, j) in memo:
                return memo[(i,j)]
            
            # store a match flag, to use in both scenarios
            matched = i < m and (s[i] == p[j] or p[j] == ".")

            # peek next character: if "*", repeated pattern
            res = False
            if (j+1) < n and p[j+1] == "*":
                res = (dfs(i, j + 2) or                 # don't use * 
                                (matched and dfs(i + 1, j)))    # use *
            # peek next character: if not "*", actually matching
            elif matched:
                res = dfs(i+1, j+1)

            memo[(i,j)] = res
            return memo[(i,j)]
        
        return dfs(0, 0)
