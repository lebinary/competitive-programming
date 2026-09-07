# 131. Palindrome Partitioning
# Difficulty: Medium
# Status: Accepted
# Runtime: 483 ms (beats 5.0%)
# Memory: 35.4 MB (beats 8.0%)
# Submitted: 2024-09-27 04:48:54 UTC
# URL: https://leetcode.com/submissions/detail/1403594587/

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def isPalindrome(l, r):
            while l < r:
                if s[l] != s[r]:
                    return False
                
                l += 1
                r -= 1

            return True

        res = []
        subset = []
        def backtrack(i):
            if i >= len(s):
                res.append(subset.copy())
                return

            subset.append(s[i])
            backtrack(i+1)
            
            subset.pop()
            for j in range(i+1, len(s)):
                if isPalindrome(i, j):
                    subset.append(s[i : j + 1])
                    backtrack(j + 1)
                    subset.pop()
            
        backtrack(0)
        return res




