# 131. Palindrome Partitioning
# Difficulty: Medium
# Status: Accepted
# Runtime: 114 ms (beats 5.0%)
# Memory: 34.5 MB (beats 9.2%)
# Submitted: 2024-12-10 13:04:13 UTC
# URL: https://leetcode.com/submissions/detail/1475248920/

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        def isPal(substr):
            if len(substr) == 0: return False

            l, r = 0, len(substr) - 1
            while l <= r:
                if substr[l] != substr[r]:
                    return False

                l += 1
                r -= 1
            return True

        res = []
        split = []
        n = len(s)

        def dfs(i):
            if i >= n:
                for substr in split:
                    if not isPal(substr):
                        return
                res.append(split.copy())
                return

            split.append(s[i])
            dfs(i+1)
            split.pop()

            if len(split) > 0:
                substr = split[-1] + s[i]
                split[-1] = substr
                dfs(i+1)

        dfs(0)
        return res




