# 42. Trapping Rain Water
# Difficulty: Hard
# Status: Accepted
# Runtime: 145 ms (beats 5.9%)
# Memory: 15.1 MB (beats 5.5%)
# Submitted: 2023-12-19 14:18:02 UTC
# URL: https://leetcode.com/submissions/detail/1123450803/

class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        N = len(height)

        # Precalculate maxLeft and maxRight value of each position
        max_l = [0] * N
        max_r = [0] * N
        min_l_r = [0] * N

        for i in range(N - 1, -1, -1):
            print(i)
            if i == N - 1:
                max_r[i] = height[i]
            else:
                max_r[i] = max(max_r[i+1], height[i])

        for i in range(0, N):
            # Calculate maxLeft
            if i == 0:
                max_l[i] = height[i]
            else:
                max_l[i] = max(max_l[i-1], height[i])

            # Calculate min of 2 maxes on both sides
            min_l_r[i] = min(max_l[i], max_r[i])

        # Calculate trap amount
        trap_amount = 0
        for i in range(0, N):
            trap_amount += max(0, min_l_r[i] - height[i])
        
        return trap_amount
