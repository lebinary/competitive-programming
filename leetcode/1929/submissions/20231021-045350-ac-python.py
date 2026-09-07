# 1929. Concatenation of Array
# Difficulty: Easy
# Status: Accepted
# Runtime: 62 ms (beats 6.1%)
# Memory: 13.6 MB (beats 35.6%)
# Submitted: 2023-10-21 04:53:50 UTC
# URL: https://leetcode.com/submissions/detail/1080350010/

class Solution(object):
    def getConcatenation(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        return [num for i in range(2) for num in nums]
        
