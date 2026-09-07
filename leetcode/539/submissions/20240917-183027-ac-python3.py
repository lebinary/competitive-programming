# 539. Minimum Time Difference
# Difficulty: Medium
# Status: Accepted
# Runtime: 74 ms (beats 5.8%)
# Memory: 19.7 MB (beats 100.0%)
# Submitted: 2024-09-17 18:30:27 UTC
# URL: https://leetcode.com/submissions/detail/1393572606/

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
        minutes = [self.convert(x) for x in timePoints]
        minutes.sort()

        res = float('inf')
        l = -1
        for r in range(len(minutes)):
            diff = self.diff(minutes[l], minutes[r])
            res = min(res, diff)
            l += 1
        
        return res
    
    def convert(self, t: str) -> int:
        [hour, minute] = t.split(":")

        return int(hour) * 60 + int(minute)
    
    def diff(self, m1: int, m2:int) -> int:
        if abs(m1 - m2) < 1440/2:
            return abs(m1 - m2)
        else:
            return (1440 - max(m1, m2)) + min(m1, m2)

        
