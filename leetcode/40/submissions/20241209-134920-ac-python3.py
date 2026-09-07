# 40. Combination Sum II
# Difficulty: Medium
# Status: Accepted
# Runtime: 34 ms (beats 14.4%)
# Memory: 17.6 MB (beats 100.0%)
# Submitted: 2024-12-09 13:49:20 UTC
# URL: https://leetcode.com/submissions/detail/1474368460/

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        res = []
        comb = []

        def dfs(i, total):
            if total == 0:
                res.append(comb.copy())
                return
            if i >= len(candidates) or total < 0:
                return

            comb.append(candidates[i])
            dfs(i+1, total-candidates[i])

            comb.pop()
            while i+1 < len(candidates) and candidates[i] == candidates[i+1]:
                i += 1
            dfs(i+1, total)
        
        dfs(0, target)
        return res
