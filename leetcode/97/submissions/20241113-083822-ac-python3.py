# 97. Interleaving String
# Difficulty: Medium
# Status: Accepted
# Runtime: 40 ms (beats 96.5%)
# Memory: 17.6 MB (beats 100.0%)
# Submitted: 2024-11-13 08:38:22 UTC
# URL: https://leetcode.com/submissions/detail/1451423370/

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1) + len(s2) != len(s3):
            return False
        
        memo = {} # (i, j) -> bool
        def dfs(i, j):
            # Check if current prefix of s3 matches our interleaving so far
            k = i + j  # current position in s3
            
            if i >= len(s1) and j >= len(s2):
                return True
            if (i, j) in memo:
                return memo[(i,j)]

            res = False
            # Try s1[i] if it matches with current position in s3
            if i < len(s1) and s1[i] == s3[k]:
                res = dfs(i+1, j)
                
            # Try s2[j] if it matches with current position in s3
            if not res and j < len(s2) and s2[j] == s3[k]:
                res = dfs(i, j+1)

            memo[(i,j)] = res
            return res
        
        return dfs(0, 0)
