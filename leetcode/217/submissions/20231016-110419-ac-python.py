# 217. Contains Duplicate
# Difficulty: Easy
# Status: Accepted
# Runtime: 431 ms (beats 5.1%)
# Memory: 29.1 MB (beats 7.5%)
# Submitted: 2023-10-16 11:04:19 UTC
# URL: https://leetcode.com/submissions/detail/1076596929/

class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        uniques = set()
        for num in nums:
            if num in uniques:
                return True
            else:
                uniques.add(num)
        
        return False
