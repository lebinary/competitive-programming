# 90. Subsets II
# Difficulty: Medium
# Status: Accepted
# Runtime: 0 ms (beats 100.0%)
# Memory: 16.9 MB (beats 100.0%)
# Submitted: 2024-11-25 13:32:37 UTC
# URL: https://leetcode.com/submissions/detail/1462456345/

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        '''
        [1, 1, 2]
        1   -> 11 -> 112
                  -> 11      
            -> 1  -> 12
                  -> 1
        
        (skip these branch)
        1 -> 12
          -> 1
        
        2 -> 2
        '''

        nums.sort()
        res = []
        subset = []
        def dfs(i):
            if i >= len(nums):
                res.append(subset.copy())
                return

            subset.append(nums[i])
            dfs(i+1)

            subset.pop()
            # skipping branch
            j = i+1
            while j < len(nums) and nums[j] == nums[i]:
                j += 1
            dfs(j)
        dfs(0)
        return res
