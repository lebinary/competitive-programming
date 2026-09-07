# 2594. Minimum Time to Repair Cars
# Difficulty: Medium
# Status: Accepted
# Runtime: 1263 ms (beats 52.0%)
# Memory: 14.8 MB (beats 36.0%)
# Submitted: 2026-08-08 12:07:37 UTC
# URL: https://leetcode.com/submissions/detail/2099064427/

class Solution(object):
    def repairCars(self, ranks, cars):
        """
        :type ranks: List[int]
        :type cars: int
        :rtype: int
        """
        ranks.sort()

        def validator(threshold):
            capacity = 0
            for rank in ranks:
                capacity += int(sqrt(threshold / rank))
            return capacity >= cars 
        
        l, r = 0, ranks[-1] * pow(cars, 2)

        while l < r:
            m = l + (r - l) // 2
            if(validator(m)): r = m
            else: l = m + 1
        
        return l
