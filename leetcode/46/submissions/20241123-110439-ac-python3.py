# 46. Permutations
# Difficulty: Medium
# Status: Accepted
# Runtime: 3 ms (beats 31.5%)
# Memory: 16.7 MB (beats 100.0%)
# Submitted: 2024-11-23 11:04:39 UTC
# URL: https://leetcode.com/submissions/detail/1460683402/

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        perm = []

        def dfs():
            if len(perm) == len(nums):
                res.append(perm.copy())
                return
                
            for num in nums:
                if num not in perm:
                    perm.append(num)
                    dfs()
                    perm.pop()
        
        dfs()
        return res
