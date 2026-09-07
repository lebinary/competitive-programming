# 42. Trapping Rain Water
# Difficulty: Hard
# Status: Accepted
# Runtime: 89 ms (beats 5.9%)
# Memory: 14.9 MB (beats 5.5%)
# Submitted: 2023-12-19 14:43:09 UTC
# URL: https://leetcode.com/submissions/detail/1123467212/

class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        N = len(height)

        l = 0
        r = N - 1

        max_l = height[l]
        max_r = height[r]

        trap_amount = 0

        while l < r: 
            if max_l < max_r:
                trap_amount += max(0, max_l - height[l])

                l += 1
                max_l = max(max_l, height[l])
            else:
                trap_amount += max(0, max_r - height[r])

                r -= 1
                max_r = max(max_r, height[r])
        
        return trap_amount

