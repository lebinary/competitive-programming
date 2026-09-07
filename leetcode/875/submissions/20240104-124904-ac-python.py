# 875. Koko Eating Bananas
# Difficulty: Medium
# Status: Accepted
# Runtime: 452 ms (beats 5.1%)
# Memory: 14.4 MB (beats 15.4%)
# Submitted: 2024-01-04 12:49:04 UTC
# URL: https://leetcode.com/submissions/detail/1136625042/

import math

class Solution(object):
    def minEatingSpeed(self, piles, h):
        """
        :type piles: List[int]
        :type h: int
        :rtype: int
        """
        l, r = 1, max(piles)
        res = r

        while l <= r:
            k = (l + r) // 2

            # hours taken to eat k bananas per hour
            t = 0
            for p in piles:
                t += math.ceil(float(p) / k)
            
            if t <= h:
                res = min(res, k)
                r = k - 1
            else:
                l = k + 1
        
        return res
