# 238. Product of Array Except Self
# Difficulty: Medium
# Status: Accepted
# Runtime: 301 ms (beats 5.0%)
# Memory: 27.4 MB (beats 8.4%)
# Submitted: 2024-08-28 18:59:30 UTC
# URL: https://leetcode.com/submissions/detail/1371496740/

class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # left to right
        lr = [1] * (len(nums) + 1)
        for i, num in enumerate(nums):
            lr[i+1] = num * lr[i]
        
        # right to left
        rl = [1] * (len(nums) + 1)
        for i, num in reversed(list(enumerate(nums))):
            rl[i] = num * rl[i+1]

        return [lr[i] * rl[i+1] for i in range(len(nums))]
        
