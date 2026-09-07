# 40. Combination Sum II
# Difficulty: Medium
# Status: Accepted
# Runtime: 35 ms (beats 13.4%)
# Memory: 17.5 MB (beats 100.0%)
# Submitted: 2024-12-09 13:48:32 UTC
# URL: https://leetcode.com/submissions/detail/1474367801/

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
