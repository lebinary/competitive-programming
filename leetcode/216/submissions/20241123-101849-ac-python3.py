# 216. Combination Sum III
# Difficulty: Medium
# Status: Accepted
# Runtime: 0 ms (beats 100.0%)
# Memory: 16.6 MB (beats 100.0%)
# Submitted: 2024-11-23 10:18:49 UTC
# URL: https://leetcode.com/submissions/detail/1460661468/

class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res = []
        comb = []

        def dfs(i, total):
            if len(comb) == k and total == n:
                res.append(comb.copy())
                return
            if i > 9 or len(comb) > k or total > n:
                return

            comb.append(i)
            dfs(i + 1, total + i)

            comb.pop()
            dfs(i + 1, total)

        dfs(1, 0)
        return res
