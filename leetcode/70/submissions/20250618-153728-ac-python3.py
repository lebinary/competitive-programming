# 70. Climbing Stairs
# Difficulty: Easy
# Status: Accepted
# Runtime: 0 ms (beats 100.0%)
# Memory: 17.7 MB (beats 100.0%)
# Submitted: 2025-06-18 15:37:29 UTC
# URL: https://leetcode.com/submissions/detail/1668444359/

class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        one = 1
        two = 1
        for i in range(2, n+1):
            temp = one
            one = one + two
            two = temp
        return one
