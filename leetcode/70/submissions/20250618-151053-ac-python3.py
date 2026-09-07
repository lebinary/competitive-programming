# 70. Climbing Stairs
# Difficulty: Easy
# Status: Accepted
# Runtime: 0 ms (beats 100.0%)
# Memory: 17.8 MB (beats 100.0%)
# Submitted: 2025-06-18 15:10:54 UTC
# URL: https://leetcode.com/submissions/detail/1668418819/

import math

class Solution:
    def climbStairs(self, n: int) -> int:
        count = 0
        for i in range(0, n + 1, 2):
            twoStep = i // 2
            oneStep = n - (2 * twoStep)
            count += (math.factorial(twoStep + oneStep) / (math.factorial(twoStep) * math.factorial(oneStep)))
        
        return int(count)
