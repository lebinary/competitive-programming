# 853. Car Fleet
# Difficulty: Medium
# Status: Accepted
# Runtime: 1351 ms (beats 5.1%)
# Memory: 37.3 MB (beats 27.4%)
# Submitted: 2023-12-30 05:04:57 UTC
# URL: https://leetcode.com/submissions/detail/1131920951/

class Solution(object):
    def carFleet(self, target, pos, speed):
        # calulate time took for each car to reach destination and sorted descending by position
        times = [float(target - p) / s for p, s in sorted(zip(pos, speed), reverse=True)]

        res = cur = 0
        for t in times:
            if t > cur:
                cur = t
                res += 1            

        return res
        
