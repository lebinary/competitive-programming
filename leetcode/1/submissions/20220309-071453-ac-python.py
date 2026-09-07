# 1. Two Sum
# Difficulty: Easy
# Status: Accepted
# Runtime: 42 ms (beats 43.4%)
# Memory: 14.2 MB (beats 17.0%)
# Submitted: 2022-03-09 07:14:53 UTC
# URL: https://leetcode.com/submissions/detail/656402324/

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hm = {}
        
        for i, num in enumerate(nums):
            if hm.get(target - num) is None:
                hm[num] = i
            else:
                return [hm.get(target - num), i]
                
        return []
                
