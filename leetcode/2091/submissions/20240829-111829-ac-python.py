# 2091. Removing Minimum and Maximum From Array
# Difficulty: Medium
# Status: Accepted
# Runtime: 730 ms (beats 5.1%)
# Memory: 23.7 MB (beats 13.5%)
# Submitted: 2024-08-29 11:18:29 UTC
# URL: https://leetcode.com/submissions/detail/1372119802/

class Solution(object):
    def minimumDeletions(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        N = len(nums)
        if N <= 2: return N

        # find max, min
        min_item = [0, nums[0]]
        max_item = [0, nums[0]]
        for i, num in enumerate(nums):
            if num > max_item[1]:
                max_item = [i, num]
            if num < min_item[1]:
                min_item = [i, num]

        # compare deletion count
        lr_count = max(min_item[0], max_item[0]) + 1
        rl_count = N - min(min_item[0], max_item[0]) 
        both_count = 2*N - lr_count - rl_count + 2

        return min(lr_count, rl_count, both_count)

        
