# 46. Permutations
# Difficulty: Medium
# Status: Accepted
# Runtime: 5 ms (beats 1.9%)
# Memory: 16.8 MB (beats 100.0%)
# Submitted: 2024-11-23 11:04:23 UTC
# URL: https://leetcode.com/submissions/detail/1460683257/

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        perm = []
        path = set()

        def dfs():
            if len(perm) == len(nums):
                res.append(perm.copy())
                return
                
            for num in nums:
                if num not in perm:
                    perm.append(num)
                    path.add(num)
                    dfs()
                    perm.pop()
                    path.remove(num)
        
        dfs()
        return res
