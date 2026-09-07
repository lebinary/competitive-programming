# 90. Subsets II
# Difficulty: Medium
# Status: Accepted
# Runtime: 2 ms (beats 24.2%)
# Memory: 16.7 MB (beats 100.0%)
# Submitted: 2024-11-25 12:43:40 UTC
# URL: https://leetcode.com/submissions/detail/1462426005/

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
            print(subset)
            if i >= len(nums):
                print("add")
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
