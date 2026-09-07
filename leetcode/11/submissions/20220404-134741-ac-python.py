# 11. Container With Most Water
# Difficulty: Medium
# Status: Accepted
# Runtime: 1010 ms (beats 5.5%)
# Memory: 23.9 MB (beats 25.5%)
# Submitted: 2022-04-04 13:47:41 UTC
# URL: https://leetcode.com/submissions/detail/673658033/

class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        l = 0
        r = len(height) - 1
        
        max_area = 0
        
        while l < r:
            curr_area = (r - l) * min(height[l], height[r])
            
            max_area = max(max_area, curr_area)
            
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
                
        return max_area
            
