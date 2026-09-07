# 84. Largest Rectangle in Histogram
# Difficulty: Hard
# Status: Accepted
# Runtime: 660 ms (beats 5.0%)
# Memory: 33.6 MB (beats 30.6%)
# Submitted: 2024-09-21 12:36:34 UTC
# URL: https://leetcode.com/submissions/detail/1397391182/

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        # intuition: 
        # try to extend bar as far right as possible
        # if cannot extend anymore, calculate the area and pop
        # finally, the stack will be left with elements that can be extend far to the left
        #   calculate it and return
        
        stack = []
        res = 0
        for i, h in enumerate(heights):
            start = i

            while stack and stack[-1][1] > h:
                prev_i, prev_h = stack.pop()

                # calculate area of previous bars that cannot be anymore
                res = max(res, prev_h * (i - prev_i))

                # extend to the left for current bar
                start = prev_i

            stack.append((start, h))
        
        # now left with only bars that extended to the left
        for i, h in stack:
            res = max(res, h * (len(heights) - i))
        
        return res
