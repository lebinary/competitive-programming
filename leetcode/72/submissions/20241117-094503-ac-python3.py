# 72. Edit Distance
# Difficulty: Medium
# Status: Accepted
# Runtime: 44 ms (beats 67.5%)
# Memory: 18.5 MB (beats 100.0%)
# Submitted: 2024-11-17 09:45:03 UTC
# URL: https://leetcode.com/submissions/detail/1455166796/

class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n = len(word1)
        m = len(word2)
        memo = {} # (i, j) -> min_action_count

        def dfs(i, j):
            if i >= n:
                return m - j # reach end of word1, need to insert (m-j) chars to match word2
            if j >= m:
                return n - i # reach end of word2, need to delete (n-i) chars to match word1
            if (i, j) in memo:
                return memo[(i, j)]

            res = 0
            if word1[i] == word2[j]:
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
