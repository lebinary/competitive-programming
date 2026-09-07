# 39. Combination Sum
# Difficulty: Medium
# Status: Accepted
# Runtime: 47 ms (beats 5.2%)
# Memory: 16.8 MB (beats 100.0%)
# Submitted: 2024-09-25 14:10:39 UTC
# URL: https://leetcode.com/submissions/detail/1401897862/

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []

        subset = []

        def dfs(i, total):
            if total == target:
                res.append(subset.copy())
                return

            if i >= len(candidates) or total > target:
                return

            subset.append(candidates[i])
            dfs(i, total + candidates[i])

            subset.pop()
            dfs(i+1, total)

        dfs(0, 0)
        return res
        
            
