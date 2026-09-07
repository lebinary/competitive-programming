# 11. Container With Most Water
# Difficulty: Medium
# Status: Accepted
# Runtime: 526 ms (beats 5.4%)
# Memory: 29.4 MB (beats 97.7%)
# Submitted: 2024-09-06 11:26:18 UTC
# URL: https://leetcode.com/submissions/detail/1380998685/

class Solution:
    def maxArea(self, height: List[int]) -> int:
        if len(height) == 0: return 0

        max_area = 0
        l = 0
        r = len(height) - 1

        while l < r:
            max_area = max(max_area, min(height[l], height[r]) * (r - l))

            if height[l] <= height[r]:
                l += 1
            else:
                r -= 1
        
        return max_area
        
