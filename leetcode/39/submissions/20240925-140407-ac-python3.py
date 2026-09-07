# 39. Combination Sum
# Difficulty: Medium
# Status: Accepted
# Runtime: 62 ms (beats 5.0%)
# Memory: 16.6 MB (beats 100.0%)
# Submitted: 2024-09-25 14:04:07 UTC
# URL: https://leetcode.com/submissions/detail/1401891628/

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []

        subset = []

        def dfs(i):
            total = sum(subset) 
            if total == target:
                res.append(subset.copy())
                return

            if i >= len(candidates) or total > target:
                return

            subset.append(candidates[i])
            dfs(i)

            subset.pop()
            dfs(i+1)

        dfs(0)
        return res
        
            
