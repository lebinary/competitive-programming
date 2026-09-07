# 739. Daily Temperatures
# Difficulty: Medium
# Status: Accepted
# Runtime: 2184 ms (beats 5.2%)
# Memory: 30 MB (beats 5.1%)
# Submitted: 2023-12-30 04:20:10 UTC
# URL: https://leetcode.com/submissions/detail/1131894807/

class Solution(object):
    def dailyTemperatures(self, temperatures):
        """
        :type temperatures: List[int]
        :rtype: List[int]
        """
        stack = [] # stack_item = [index, value]
        res = [0] * len(temperatures)

        for i, temp in enumerate(temperatures):
            while stack and temp > stack[-1][1]:
                index, value = stack.pop()
                res[index] = i - index

            stack.append([i, temp])
        
        return res
            

        
