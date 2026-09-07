# 2091. Removing Minimum and Maximum From Array
# Difficulty: Medium
# Status: Accepted
# Runtime: 717 ms (beats 5.1%)
# Memory: 23.8 MB (beats 13.5%)
# Submitted: 2024-08-29 11:15:16 UTC
# URL: https://leetcode.com/submissions/detail/1372117627/

class Solution(object):
    def minimumDeletions(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0: return 0

        min_item = [0, nums[0]]
        max_item = [0, nums[0]]
        for i, num in enumerate(nums):
            if num > max_item[1]:
                max_item = [i, num]
            if num < min_item[1]:
                min_item = [i, num]

        lr_count = max(min_item[0], max_item[0]) + 1
        rl_count = len(nums) - min(min_item[0], max_item[0]) 
        both_count = len(nums) - lr_count + 1 + len(nums) - rl_count + 1

        return min(lr_count, rl_count, both_count)

        
