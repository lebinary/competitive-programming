# 268. Missing Number
# Difficulty: Easy
# Status: Accepted
# Runtime: 197 ms (beats 21.7%)
# Memory: 14.6 MB (beats 5.1%)
# Submitted: 2021-10-13 14:40:00 UTC
# URL: https://leetcode.com/submissions/detail/570604287/

class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        xSum = n * (n+1) / 2
        
        realSum = 0
        for num in nums: realSum += num
        
        return xSum - realSum
        
