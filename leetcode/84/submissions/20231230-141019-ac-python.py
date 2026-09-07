# 84. Largest Rectangle in Histogram
# Difficulty: Hard
# Status: Accepted
# Runtime: 1010 ms (beats 5.1%)
# Memory: 31.7 MB (beats 5.1%)
# Submitted: 2023-12-30 14:10:19 UTC
# URL: https://leetcode.com/submissions/detail/1132236925/

class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        stack = [] # stack_item = ( index(the left most where h[l] >= h[i]),  height )
        maxArea = 0

        for i, h in enumerate(heights):
            start = i
            while stack and h < stack[-1][1]:
                start_index, height = stack.pop()
                maxArea = max(maxArea, height * (i - start_index))
                start = start_index
            
            stack.append((start, h))
        
        end_index = len(heights)
        for start_index, height in stack:
            maxArea = max(maxArea, height * ( end_index - start_index ))
        
        return maxArea

