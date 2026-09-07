# 217. Contains Duplicate
# Difficulty: Easy
# Status: Accepted
# Runtime: 497 ms (beats 5.1%)
# Memory: 23.7 MB (beats 93.6%)
# Submitted: 2022-03-09 07:48:09 UTC
# URL: https://leetcode.com/submissions/detail/656419341/

class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        s = set()
        
        for num in nums:
            if num in s:
                return True
            else:
                s.add(num)
        
        return False
