# 72. Edit Distance
# Difficulty: Medium
# Status: Accepted
# Runtime: 46 ms (beats 65.0%)
# Memory: 18.5 MB (beats 100.0%)
# Submitted: 2024-11-17 09:40:50 UTC
# URL: https://leetcode.com/submissions/detail/1455164206/

class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n = len(word1)
        m = len(word2)
        memo = {} # (i, j) -> min_action_count

        def dfs(i, j):
            if i >= n and j >= m:
                return 0
            if (i, j) in memo:
                return memo[(i, j)]

            res = 0
            if i >= n:
                res = 1 + dfs(i, j+1) # only insert
            elif j >= m:
                res = 1 + dfs(i+ 1, j) # only delete
            elif word1[i] == word2[j]:
                res = dfs(i+1, j+1)
            else:
                res = 1 + min(
                        dfs(i, j+1),    # insert
                        dfs(i+1, j),    # delete
                        dfs(i+1, j+1)   # replace
                    )
            memo[(i, j)] = res
            return res

        return dfs(0, 0) 
