# 875. Koko Eating Bananas
# Difficulty: Medium
# Status: Accepted
# Runtime: 268 ms (beats 5.0%)
# Memory: 18.2 MB (beats 100.0%)
# Submitted: 2024-09-08 05:41:10 UTC
# URL: https://leetcode.com/submissions/detail/1382865719/

import math
class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l = 1
        r = max(piles)
        res = r

        while l <= r:
            k = (l + r) // 2

            t = sum([math.ceil(pile / k) for pile in piles])

            if t <= h:
                res = min(res, k)
                r = k - 1
            else:
                l = k + 1
        
        return res
