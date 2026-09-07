# 1760. Minimum Limit of Balls in a Bag
# Difficulty: Medium
# Status: Accepted
# Runtime: 815 ms (beats 30.0%)
# Memory: 29.9 MB (beats 71.7%)
# Submitted: 2025-05-03 10:24:34 UTC
# URL: https://leetcode.com/submissions/detail/1624307301/

import math

class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        l, r = 1, max(nums)
        res = r
        
        while l < r:
            p = (l + r) // 2
            ops = 0
            for num in nums:
                if num > p:
                    ops += math.ceil(num / p) - 1

            if ops <= maxOperations:
                res = p
                r = p
            else:
                l = p + 1
        
        return res
