# 70. Climbing Stairs
# Difficulty: Easy
# Status: Accepted
# Runtime: 0 ms (beats 100.0%)
# Memory: 17.9 MB (beats 100.0%)
# Submitted: 2025-06-18 16:51:41 UTC
# URL: https://leetcode.com/submissions/detail/1668521143/

import math

class Solution:
    def climbStairs(self, n: int) -> int:
        count = 0
        
        # i is the number of 2-steps we take
        for i in range(n // 2 + 1):  # from 0 to max possible 2-steps
            # remaining steps after taking i two-steps
            remaining = n - 2 * i
            # total positions = remaining ones + i twos = remaining + i
            # choose i positions out of (remaining + i) for the twos
            count += math.factorial(remaining + i) // (math.factorial(i) * math.factorial(remaining))
        
        return count
