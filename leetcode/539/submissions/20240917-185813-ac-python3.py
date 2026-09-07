# 539. Minimum Time Difference
# Difficulty: Medium
# Status: Accepted
# Runtime: 65 ms (beats 5.8%)
# Memory: 19.6 MB (beats 100.0%)
# Submitted: 2024-09-17 18:58:13 UTC
# URL: https://leetcode.com/submissions/detail/1393600633/

class Solution:
    # 0 - 1 - 2 - ... 11 - 12 - 13 - ... 21 - 22 - 23

    # Sub-problem 1: given 2 numbers, how to get the diff in minute?
    # steps:
    #   1. check if they are in the same side using the hour
    #       a. if same side, diff = large - small
    #       b. if not, diff = large - (small + 12)

    # Sub-problem 2: how to find the min diff
    # Sort the time
    # Loop through the array to find the min diff
    # Also make sure to check sorted[0] and sorted[last]
    def findMinDifference(self, timePoints: List[str]) -> int:
        # save minutes into array size 1440
        # also keep track of the min and max
        exits = [False] * 1440
        min_m, max_m = 1440, 0
        for t in timePoints:
            m = self.convert(t)

            # same minute
            if exits[m]:
                return 0

            exits[m] = True
            min_m = min(min_m, m)
            max_m = max(max_m, m)

        # now check for distance between the True(s)
        res = (1440 - max_m) + min_m
        print(res)
        prev_m = min_m
        for m in range(min_m + 1, len(exits)):
            if exits[m]:
                diff = m - prev_m
                res = min(res, diff)
                prev_m = m
        
        return res
    
    def convert(self, t: str) -> int:
        [hour, minute] = t.split(":")

        return int(hour) * 60 + int(minute)

        
