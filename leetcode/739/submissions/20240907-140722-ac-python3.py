# 739. Daily Temperatures
# Difficulty: Medium
# Status: Accepted
# Runtime: 903 ms (beats 5.0%)
# Memory: 30.8 MB (beats 24.6%)
# Submitted: 2024-09-07 14:07:22 UTC
# URL: https://leetcode.com/submissions/detail/1382128316/

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        res = [0 for _ in range(len(temperatures))]
        stack = []

        for i, temp in enumerate(temperatures):
            while stack and temp > stack[-1][0]:
                last_temp, last_i = stack.pop()
                res[last_i] = i - last_i

            stack.append((temp, i))
        
        return res

