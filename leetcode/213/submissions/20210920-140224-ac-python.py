# 213. House Robber II
# Difficulty: Medium
# Status: Accepted
# Runtime: 29 ms (beats 1.3%)
# Memory: 13.4 MB (beats 25.2%)
# Submitted: 2021-09-20 14:02:24 UTC
# URL: https://leetcode.com/submissions/detail/558067690/

class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0: return 0
        if n < 3: return max(nums)
        
        #first to n-1
        total1 = self.findMaxRob(nums[:-1])
        
        #second to last
        total2 = self.findMaxRob(nums[1:])
        
        return max(total1, total2)
    
    def findMaxRob(self, nums):
        rob1, rob2 = 0, 0
        for n in nums:
            newRob = max(rob1 + n, rob2)
            rob1 = rob2
            rob2 = newRob
        return rob2
        
            
        
