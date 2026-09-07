# 39. Combination Sum
# Difficulty: Medium
# Status: Accepted
# Runtime: 19 ms (beats 11.7%)
# Memory: 16.8 MB (beats 100.0%)
# Submitted: 2024-11-23 09:45:24 UTC
# URL: https://leetcode.com/submissions/detail/1460645030/

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        res = []
        comb = []

        def dfs(i, curr):
            if i >= len(candidates) or curr < 0:
                return
            if curr == 0:
                res.append(comb.copy())
                return

            comb.append(candidates[i])
            dfs(i, curr - candidates[i])

            comb.pop()
            dfs(i+1, curr)
        
        dfs(0, target)
        return res
        
            
