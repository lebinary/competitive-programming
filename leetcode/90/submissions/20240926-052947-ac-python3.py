# 90. Subsets II
# Difficulty: Medium
# Status: Accepted
# Runtime: 40 ms (beats 5.0%)
# Memory: 16.7 MB (beats 100.0%)
# Submitted: 2024-09-26 05:29:47 UTC
# URL: https://leetcode.com/submissions/detail/1402581734/

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums = sorted(nums)

        subset = []
        def dfs(prev, curr):
            if curr >= len(nums):
                res.append(subset.copy())
                return
            
            subset.append(nums[curr])
            dfs(curr, curr + 1)

            subset.pop()
            if nums[curr] == nums[prev] and (subset and nums[curr] == subset[-1]):
                return
            dfs(curr, curr + 1)

        dfs(0, 0)
        return res
