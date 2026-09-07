# 40. Combination Sum II
# Difficulty: Medium
# Status: Accepted
# Runtime: 73 ms (beats 5.8%)
# Memory: 16.7 MB (beats 100.0%)
# Submitted: 2024-09-26 10:35:24 UTC
# URL: https://leetcode.com/submissions/detail/1402808150/

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates = sorted(candidates)
        
        subset = []
        def dfs(i, total):
            if total == target:
                res.append(subset.copy())
                return
            
            if i >= len(candidates) or total > target:
                return
            

            subset.append(candidates[i])
            dfs(i + 1, total + candidates[i])

            subset.pop()
            # avoid repeat
            while i + 1 < len(candidates) and candidates[i] == candidates[i+1]:
                i += 1
            dfs(i + 1, total)
        
        dfs(0, 0)
        return res
