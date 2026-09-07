# 56. Merge Intervals
# Difficulty: Medium
# Status: Accepted
# Runtime: 64 ms (beats 5.1%)
# Memory: 15.7 MB (beats 99.7%)
# Submitted: 2021-09-14 15:29:07 UTC
# URL: https://leetcode.com/submissions/detail/554837889/

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        intervals.sort(key=lambda x: x[0])
        
        newIntervals = []
        for interval in intervals:
            if not newIntervals or newIntervals[-1][1] < interval[0]:
                newIntervals.append(interval)
            else:
                newIntervals[-1][1] = max(newIntervals[-1][1], interval[1])
        return newIntervals
                    
                
        
        
