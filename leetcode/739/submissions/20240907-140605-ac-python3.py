# 739. Daily Temperatures
# Difficulty: Medium
# Status: Accepted
# Runtime: 931 ms (beats 5.0%)
# Memory: 31.2 MB (beats 24.5%)
# Submitted: 2024-09-07 14:06:05 UTC
# URL: https://leetcode.com/submissions/detail/1382127188/

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        res = [0 for _ in range(len(temperatures))]
        stack = []

        for i, temp in enumerate(temperatures):
            if len(stack) == 0:
                stack.append((temp, i))
            else:
                while stack and temp > stack[-1][0]:
                    last_temp, last_i = stack.pop()
                    res[last_i] = i - last_i

                stack.append((temp, i))
        
        return res

