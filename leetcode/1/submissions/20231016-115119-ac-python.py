# 1. Two Sum
# Difficulty: Easy
# Status: Accepted
# Runtime: 38 ms (beats 43.4%)
# Memory: 14.3 MB (beats 17.0%)
# Submitted: 2023-10-16 11:51:19 UTC
# URL: https://leetcode.com/submissions/detail/1076621315/

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hm = {}

        for idx, num in enumerate(nums):
            diff = target - num
            if diff in hm:
                return [hm.get(diff), idx]
            else:
                hm[num] = idx



        
