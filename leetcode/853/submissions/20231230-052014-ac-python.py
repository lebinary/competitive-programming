# 853. Car Fleet
# Difficulty: Medium
# Status: Accepted
# Runtime: 2695 ms (beats 5.1%)
# Memory: 44 MB (beats 5.2%)
# Submitted: 2023-12-30 05:20:14 UTC
# URL: https://leetcode.com/submissions/detail/1131930215/

class Solution(object):
    def carFleet(self, target, pos, speed):
        # pairs of (position, speed) sorted descending by position
        pairs = [(p, s) for p, s in sorted(zip(pos, speed), reverse=True)]
        print(pairs)
        fleets = []
        for (p, s) in pairs:
            t = float(target - p) / s

            if len(fleets) == 0:
                fleets.append(t)
            else:
                if t > fleets[-1]:
                    fleets.append(t)

        return len(fleets)
        
