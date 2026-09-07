# 1838. Frequency of the Most Frequent Element
# Difficulty: Medium
# Status: Accepted
# Runtime: 1136 ms (beats 5.4%)
# Memory: 24.2 MB (beats 15.5%)
# Submitted: 2023-12-25 13:15:26 UTC
# URL: https://leetcode.com/submissions/detail/1128138467/

# TIPS: Think about how to calculate area of a rectangle, shrink the window based on it
class Solution(object):
    def maxFrequency(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if len(nums) == 1: return 1

        nums.sort()

        res = 0
        l = 0
        total = 0
        for r in range(len(nums)):
            total += nums[r]
            while nums[r] * (r - l + 1) > total + k:
                total -= nums[l] 
                l += 1
            
            res = max(res, r - l + 1)

        return res


        
