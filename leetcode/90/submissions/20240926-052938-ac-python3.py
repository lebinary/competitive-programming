# 90. Subsets II
# Difficulty: Medium
# Status: Accepted
# Runtime: 41 ms (beats 5.0%)
# Memory: 16.9 MB (beats 100.0%)
# Submitted: 2024-09-26 05:29:38 UTC
# URL: https://leetcode.com/submissions/detail/1402581609/

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()

        def backtrack(i, subset):
            if i == len(nums):
                res.append(subset[::])
                return

            # All subsets that include nums[i]
            subset.append(nums[i])
            backtrack(i + 1, subset)
            subset.pop()
            # All subsets that don't include nums[i]
            while i + 1 < len(nums) and nums[i] == nums[i + 1]:
                i += 1
            backtrack(i + 1, subset)

        backtrack(0, [])
        return res
