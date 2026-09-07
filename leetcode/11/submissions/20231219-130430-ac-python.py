# 11. Container With Most Water
# Difficulty: Medium
# Status: Accepted
# Runtime: 537 ms (beats 5.5%)
# Memory: 23.8 MB (beats 25.5%)
# Submitted: 2023-12-19 13:04:30 UTC
# URL: https://leetcode.com/submissions/detail/1123404907/

class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        res = 0
        l = 0
        r = len(height) - 1

        while l < r:
            res = max(min(height[l], height[r]) * (r - l), res)

            if height[l] <= height[r]:
                l += 1
            else:
                r -= 1
        
        return res
