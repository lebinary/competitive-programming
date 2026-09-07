# 46. Permutations
# Difficulty: Medium
# Status: Accepted
# Runtime: 31 ms (beats 1.9%)
# Memory: 16.7 MB (beats 100.0%)
# Submitted: 2024-09-26 04:25:45 UTC
# URL: https://leetcode.com/submissions/detail/1402529869/

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []

        def dfs(perm):
            if len(perm) == len(nums):
                res.append(perm.copy())
                return
            
            for num in nums:
                if num not in perm:
                    perm.append(num)
                    dfs(perm)
                    perm.pop()
        
        dfs([])
        return res

