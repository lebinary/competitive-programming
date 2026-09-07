# 128. Longest Consecutive Sequence
# Difficulty: Medium
# Status: Accepted
# Runtime: 4746 ms (beats 5.0%)
# Memory: 30.5 MB (beats 5.2%)
# Submitted: 2023-10-21 04:40:51 UTC
# URL: https://leetcode.com/submissions/detail/1080343880/

class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        numSet = set(nums)

        longest = 0
        for num in nums:
            if num - 1 not in numSet:
                length = 1
                while num + length in numSet:
                    length += 1
                
                longest = max(longest, length)
        
        return longest
